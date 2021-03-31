#include<bits/stdc++.h>
using namespace std;
//-----------SEGTREE START
//The combine function is a general function to implement combination
//REMEMBER: Zero based indexing
//REMEMBER: Query returns answer in range [l,r)

int combine(int a,int b)
{
    return min(a,b);
}

void build(vector<int> &v)
{
int n=v.size()/2;
for(int i=n-1;i>0;i--)
{
    v[i]=combine(v[i<<1],v[(i<<1)^1]);
}
}

void update(int val,int p,vector<int> &v)
{
int n=v.size()/2;
v[p+=n]=val;
while(p>0)
{
    v[p>>1]=combine(v[p],v[p^1]);
    p>>=1;
}
}

int query(int l,int r,vector<int> &v)
{
int n=v.size()/2;
int res=INT_MAX;
l+=n,r+=n;
while(l<r)
{
    if(l&1)
    {
        res=combine(res,v[l]);
        l++;
    }
    if(r&1)
    {
        r--;
        res=combine(res,v[r]);
    }
    l>>=1,r>>=1;
}
return res;
}
//-----------SEGTREE END

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,t;
cin>>n>>t;
vector<int> v(2*n);
for(int i=n;i<2*n;i++)
{
cin>>v[i];
}
build(v);
while(t--)
{
char type;
cin>>type;
if(type=='q')
{
int l,r;
cin>>l>>r;
cout<<query(l,r+1,v)<<endl;
}else
{
int p,val;
cin>>p>>val;
update(val,p,v);
}
}
return 0;
}
