#include<bits/stdc++.h>
using namespace std;
using lol=long long int;
#define endl "\n"
const lol mod1=1e9+7,mod2=998244353,mod3=100000000000000003,hashpr=31;
const lol inf=1e18+8;
const double eps=1e-12;
const double PI=acos(-1.0);
const int N=1e6+5;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using ordered_set_type=lol;
typedef tree<ordered_set_type,null_type,less<ordered_set_type>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace FFT{
    const int LEN=1<<20;
    const int P=998244353;
    const int LENINV=998243401;
    const lol W=565042129;  //take W such that W^LEN = 1 mod P
    vector<lol> fft(const vector<lol>& poly,lol ww){
        if((int)poly.size()==1){
            return poly;
        }
        vector<lol> A,B;
        for(int i=0;i<(int)poly.size();i+=2){
            A.push_back(poly[i]);
            B.push_back(poly[i+1]);
        }
        vector<lol> resA,resB;
        resA=fft(A,(ww*ww)%P);
        resB=fft(B,(ww*ww)%P);
        vector<lol> res;
        for(lol i=0,j=1;i<(int)poly.size();i++){
            res.push_back((resA[i%(int)resA.size()]+j*resB[i%(int)resA.size()])%P);
            j=(j*ww)%P;
        }
        return res;
    }
    vector<lol> mult(vector<lol> poly1,vector<lol> poly2){
        poly1.resize(LEN,0);
        poly2.resize(LEN,0);
        vector<lol> pv1=fft(poly1,W);
        vector<lol> pv2=fft(poly2,W);
        vector<lol> pvres(LEN);
        for(int i=0;i<LEN;i++){
            pvres[i]=(pv1[i]*pv2[i])%P;
        }
        vector<lol> res=fft(pvres,W);
        //(n*a_0,n*a_n-1,...,n*a_1)
        reverse(res.begin()+1,res.end());
        for(auto& t:res)    t=(t*LENINV)%P;
        return res;
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int _=1;
//cin>>_;
while(_--)
{
    int n,m;
    cin>>n>>m;
    vector<lol> poly1(n),poly2(m);
    for(auto& e:poly1)  cin>>e;
    for(auto& e:poly2)  cin>>e;
    vector<lol> res=FFT::mult(poly1,poly2);
    for(int i=0;i<n+m-1;i++)    cout<<res[i]<<" ";
}
return 0;
}
