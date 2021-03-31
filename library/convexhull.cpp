#include<bits/stdc++.h>
using namespace std;
using lol=long long int;
const int N=5*1e5+5;
const lol modcon=1000000007,mod=998244353,hval=31,inf=2*1e9+5;
const double eps=1e-7;
#define endl "\n"
//vector<int> g[N];
//bool vis[N]={0};
//vector<int> d(N,INT_MAX);

struct Point
{
    int x,y;
};

bool comp(Point a,Point b)
{
    if(a.x==b.x)
    {
        return (a.y<b.y);
    }
    return (a.x<b.x);
}

int ccw(Point o,Point a,Point b) //+ if a to b is a ccw turn relative to o, 0 if no turn, - if cw turn
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

vector<Point> convex_hull(vector<Point> &points)
{
    vector<Point> tp;
    for(int i=0;i<n;i++)
    {
        int sz=(int)tp.size();
        while(sz>=2)
        {
            sz=(int)tp.size();
            if(ccw(tp[sz-2],points[i],tp[sz-1]))
            {
                tp.pop_back();
            }
        }
        tp.push_back(points[i]);
    }
    vector<Point> bt;
    for(int i=n-1;i>=0;i--)
    {
        int sz=(int)bt.size();
        while(sz>=2)
        {
            sz=(int)bt.size();
            if(ccw(bt[sz-2],points[i],bt[sz-1])>=0)
            {
                bt.pop_back();
            }
        }
        bt.push_back(points[i]);
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    set<Point> pointss;
    for(int i=0;i<n;i++)
    {
        Point p;
        cin>>p.x>>p.y;
        pointss.insert(p);
    }
    vector<Point> points;
    for(auto p:points)
    {
        points.push_back(p);
    }
    sort(points.begin(),points.end(),comp);
    vector<Point> ans=convex_hull(points);
    cout<<"Number of points: "<<(int)ans.size();
    for(int i=0;i<(int)ans.size();i++)
    {
        cout<<ans[i].x<<" "<<ans[i].y<<endl;
    }
}
return 0;
}
