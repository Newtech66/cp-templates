struct DSU
{
    int n; //number of vertices
    vector<int> sz;
    vector<int> p;
    DSU(int val)
    {
        n=val+1;
        sz.resize(n);
        p.resize(n);
        fill(sz.begin(),sz.end(),1);
        iota(p.begin(),p.end(),0);
    }
    int root(int a)
    {
        while(a!=p[a])
        {
            p[a]=p[p[a]];
            a=p[a];
        }
        return a;
    }
    bool find(int a,int b)
    {
        return root(a)==root(b);
    }
    void join(int a,int b)
    {
        int rta=root(a),rtb=root(b);
        if(rta==rtb)   return;
        if(sz[rta]>sz[rtb]) swap(rta,rtb);
        p[rta]=p[rtb];
        sz[rtb]+=sz[rta];
    }
};
