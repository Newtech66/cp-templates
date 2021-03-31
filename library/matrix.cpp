#include<bits/stdc++.h>
using namespace std;

//-------------MATRIX START

//REMEMBER: None of the functions assume modulo, add as necessary
//LIST OF FUNCTIONS: add[+,+=], mult[*] (no mod), scalar mult[*,*=], modulo[%,%=], read(), print(), access[M(i,j)]
template<typename T>
class Matrix
{
int n,m;
vector<vector<T> > mat;
public:
    Matrix()
    {}
    Matrix(int r,int c): n(r), m(c)
    {
        mat.resize(n);
        for(int i=0;i<n;i++)
        {
            mat[i].resize(m);
        }
    }
    Matrix(initializer_list<initializer_list<T> > l): Matrix((int)l.size(),(int)l.begin()->size())
    {
        int r=0;
        for(auto row:l)
        {
            int c=0;
            for(auto elem:row)
            {
                mat[r][c]=elem;
                c++;
            }
            r++;
        }
    }

    Matrix operator+(const Matrix&);       //matrix addition
    Matrix& operator+=(const Matrix&);
    Matrix operator*(const Matrix&);       //matrix multiplication without modulo
    Matrix& operator*=(const long long int&);          //multiplication with a scalar
    Matrix operator*(const long long int&);
    Matrix& operator%=(const long long int&);         //modulo
    Matrix operator%(const long long int&);
    T& operator()(const int&,const int&);   //value access
    const T& operator()(const int&,const int&) const;
    void read();                //input matrix values (it is assumed size of matrix is known)
    void print() const;       //output matrix values
};

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& M)
{
    if(M.n!=n || M.m!=m)
    {
        cerr<<"Matrix addition failure: sizes do not match\n M1(r,c)=("<<n<<","<<m<<")\n M2(r,c)=("<<M.n<<","<<M.m<<")";
        exit(0);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            mat[i][j]+=M.mat[i][j];
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& M)
{
    Matrix<T> res;
    res=*this;
    res+=M;
    return res;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& M)
{
    if(m!=M.n)
    {
        cerr<<"Matrix multiplication failure: sizes do not match\n M1(r,c)=("<<n<<","<<m<<")\n M2(r,c)=("<<M.n<<","<<M.m<<")";
        exit(0);
    }
    Matrix<T> res(n,M.m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<M.m;j++)
        {
            res.mat[i][j]=0;
            for(int k=0;k<m;k++)
            {
                res.mat[i][j]+=mat[i][k]*M.mat[k][j];
            }
        }
    }
    return res;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const long long int& s)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            mat[i][j]*=s;
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const long long int& s)
{
    Matrix<T> res;
    res=*this;
    res*=s;
    return res;
}

template<typename T>
Matrix<T>& Matrix<T>::operator%=(const long long int& modulo)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]>=modulo || mat[i][j]<(-modulo))
            {
                mat[i][j]%=modulo;
            }
            if(mat[i][j]<0) mat[i][j]+=modulo;
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator%(const long long int& modulo)
{
    Matrix<T> res;
    res=*this;
    res%=modulo;
    return res;
}

template<typename T>
void Matrix<T>::read()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
}

template<typename T>
T& Matrix<T>::operator()(const int& i,const int& j)
{
    if((i<0 || i>=n) && (j<0 || j>=m))
    {
        cerr<<"Both indices out of bounds. "<<"i="<<i<<" j="<<j;
        exit(0);
    }else if(i<0 || i>=n)
    {
        cerr<<"First index out of bounds. "<<"i="<<i<<" j="<<j;
        exit(0);
    }else if(j<0 || j>=m)
    {
        cerr<<"Second index out of bounds. "<<"i="<<i<<" j="<<j;
        exit(0);
    }
    return mat[i][j];
}

template<typename T>
const T& Matrix<T>::operator()(const int& i,const int& j) const
{
    if((i<0 || i>=n) && (j<0 || j>=m))
    {
        cerr<<"Both indices out of bounds. "<<"i="<<i<<" j="<<j;
        exit(0);
    }else if(i<0 || i>=n)
    {
        cerr<<"First index out of bounds. "<<"i="<<i<<" j="<<j;
        exit(0);
    }else if(j<0 || j>=m)
    {
        cerr<<"Second index out of bounds. "<<"i="<<i<<" j="<<j;
        exit(0);
    }
    return mat[i][j];
}

template<typename T>
void Matrix<T>::print() const
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
}
//-------------MATRIX END

int main()
{
    return 0;
}
