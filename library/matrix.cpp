#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
//-------------MATRIX START

//REMEMBER: None of the functions assume modulo, add as necessary
//NOTE: passing 'c' to read gets the size of the matrix as well
//NOTE: passing 'i' to square matrix constructor initialises it as an identity matrix
//LIST OF FUNCTIONS: add[+], mult[*] (no mod), scalar mult[*], read(), print(M), exp(M,p)
class matrix
{
int n,m;
vector<vector<lol> > mat;
public:
    matrix()
    {}
    matrix(int r,int c): n(r), m(c)
    {
        mat.resize(n);
        for(int i=0;i<n;i++)
        {
            mat[i].resize(m);
        }
    }
    matrix(int r,char s): n(r), m(r)
    {
        mat.resize(n);
        for(int i=0;i<n;i++)
        {
            mat[i].resize(m);
        }
        if(s=='i')
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    mat[i][j]=0;
                }
                mat[i][i]=1;
            }
        }
    }
    matrix operator+(matrix);       //matrix addition
    matrix operator*(matrix);       //matrix multiplication without modulo
    matrix operator*(int);          //multiplication with a scalar
    void read(char);                //input matrix values (it is assumed size of matrix is known)
    void print(matrix) const;       //output matrix values
    matrix exp(lol);                //matrix binary exponentiation without modulo (assumes p>0)
};

matrix matrix::operator+(matrix M)
{
if(M.n!=n || M.m!=m)
{
    cerr<<"Matrix addition failure: sizes do not match\n M1(r,c)=("<<n<<","<<m<<")\n M2(r,c)=("<<M.n<<","<<M.m<<")";
    exit(0);
}
matrix res(n,m);
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        res.mat[i][j]=mat[i][j]+M.mat[i][j];
    }
}
return res;
}

matrix matrix::operator*(matrix M)
{
if(m!=M.n)
{
    cerr<<"Matrix multiplication failure: sizes do not match\n M1(r,c)=("<<n<<","<<m<<")\n M2(r,c)=("<<M.n<<","<<M.m<<")";
    exit(0);
}
matrix res(n,M.m);
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

matrix matrix::operator*(int s)
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

void matrix::read(char s)
{
if(s=='c')
{
    cin>>n>>m;
}
mat.resize(n);
for(int i=0;i<n;i++)
{
    mat[i].resize(m);
}
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        cin>>mat[i][j];
    }
}
}

void matrix::print(matrix M) const
{
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        cout<<M.mat[i][j]<<" ";
    }
    cout<<"\n";
}
}

matrix matrix::exp(lol p)
{
if(n!=m)
{
    cerr<<"Matrix to be exponentiated is not square.";
    exit(0);
}
matrix res(n,'i');
while(p>0)
{
if(p%2)
{
res=(res*(*this));
}
(*this)=(*this)*(*this);
p/=2;
}
return (res);
}
//-------------MATRIX END

int main()
{
matrix m1,m2;
m1.read('c');
m1.print(m1.exp(0));
return 0;
}
