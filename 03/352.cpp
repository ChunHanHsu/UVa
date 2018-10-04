#include<iostream>

using namespace std;

char M[30][30];
void f(int i,int j,int N)
{
    M[i][j]='0';
    if(j+1<N&&M[i][j+1]=='1')
        f(i,j+1,N);
    if(j-1>=0&&M[i][j-1]=='1')
        f(i,j-1,N);
    if(i+1<N&&M[i+1][j]=='1')
        f(i+1,j,N);
    if(i-1>=0&&M[i-1][j]=='1')
        f(i-1,j,N);
    if(i+1<N&&j+1<N&&M[i+1][j+1]=='1')
        f(i+1,j+1,N);
    if(i-1>=0&&j+1<N&&M[i-1][j+1]=='1')
        f(i-1,j+1,N);
    if(i+1<N&&j-1>=0&&M[i+1][j-1]=='1')
        f(i+1,j-1,N);
    if(i-1>=0&&j-1>=0&&M[i-1][j-1]=='1')
        f(i-1,j-1,N);
    return;
}

int main()
{
    int N,T=0;
    while(cin>>N)
    {
        T++;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                cin>>M[i][j];

        int ans=0;
       for(int i=0;i<N;i++)
       {
           for(int j=0;j<N;j++)
            {
                if(M[i][j]=='1')
                {
                    f(i,j,N);
                    ans++;
                }
            }
       }
        cout<<"Image number "<<T<<" contains "<<ans<<" war eagles.\n";

    }
}
