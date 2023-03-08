template<typename T>
struct f{
    //fill in the operation here
    T operator()(const T& a,const T& b){return min(a,b);}
};

template<typename T,class F>
struct SparseTable{
    int len,k;
    vector<vector<T>> st;
    F f;
    //Assumes operation is idempotent like in max/min
    SparseTable(int n,const vector<T>& init){
        len=n;
        k=__lg(len)+2;
        st.resize(k);
        for(auto& v:st) v.resize(len);
        for(int i=0;i<len;i++)  st[0][i]=init[i];
        for(int j=1;j<k;j++){
            for(int i=0;i+(1<<j)<=len;i++){
                st[j][i]=f(st[j-1][i],st[j-1][i+(1<<(j-1))]);
            }
        }
    }
    T query(int l,int r){
        int j=__lg(r-l+1);
        return f(st[j][l],st[j][r-(1<<j)+1]);
    }
};
