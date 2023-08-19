#include<bits/stdc++.h>
using namespace std;
using lol=long long int;
#define endl "\n"

namespace FFT{
    const int P=998244353;
    //for 1<<23
    const lol MAXLEN=1<<23;
    const lol W=15311432;  //take W such that W^MAXLEN = 1 mod P
    lol binexp(lol b,lol p){
        if(p==0)    return 1ll;
        lol res=binexp(b,p/2);
        res=(res*res)%P;
        if(p&1)   res=(res*b)%P;
        return res;
    }
    vector<lol> fft(const vector<lol>& poly,lol ww){
        int n=(int)poly.size();
        if(n==1){
            return poly;
        }
        vector<lol> A(n/2),B(n/2);
        for(int i=0;i<n;i+=2){
            A[i/2]=poly[i];
            B[i/2]=poly[i+1];
        }
        vector<lol> resA,resB;
        lol ww2=ww*ww;
        if(ww2>=P)  ww2-=P*(ww2/P);
        resA=fft(A,ww2);
        resB=fft(B,ww2);
        vector<lol> res(n);
        for(lol i=0,j=1;i<n;i++){
            lol t=resA[(i>=n/2?i-n/2:i)]+j*resB[(i>=n/2?i-n/2:i)];
            if(t>=P)    t-=P*(t/P);
            res[i]=t;
            j*=ww;
            if(j>=P)    j-=P*(j/P);
        }
        return res;
    }
    vector<lol> mult(vector<lol> poly1,vector<lol> poly2){
        int j=1;
        while(j<poly1.size()+poly2.size())   j<<=1;
        poly1.resize(j,0);
        poly2.resize(j,0);
        lol ww=binexp(W,MAXLEN/j);
        vector<lol> pv1=fft(poly1,ww);
        vector<lol> pv2=fft(poly2,ww);
        vector<lol> pvres(j);
        for(int i=0;i<j;i++){
            pvres[i]=pv1[i]*pv2[i];
            if(pvres[i]>=P) pvres[i]-=P*(pvres[i]/P);
        }
        vector<lol> res=fft(pvres,ww);
        //(n*a_0,n*a_n-1,...,n*a_1)
        reverse(res.begin()+1,res.end());
        int j_1=binexp(j,P-2);
        for(auto& t:res){
            t*=j_1;
            if(t>=P)    t-=P*(t/P);
        }
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
