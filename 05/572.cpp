#include<iostream>

using namespace std;

char board[102][102];

void used(int i,int j,int m,int n)
{
    board[i][j]='*';
    if(i<m&&board[i+1][j]=='@')
        used(i+1,j,m,n);
    if(i>0&&board[i-1][j]=='@')
        used(i-1,j,m,n);
    if(j<n&&board[i][j+1]=='@')
        used(i,j+1,m,n);
    if(j>0&&board[i][j-1]=='@')
        used(i,j-1,m,n);
    if(j<n&&i<m&&board[i+1][j+1]=='@')
        used(i+1,j+1,m,n);
    if(j>0&&i<m&&board[i+1][j-1]=='@')
        used(i+1,j-1,m,n);
    if(j<n&&i>0&&board[i-1][j+1]=='@')
        used(i-1,j+1,m,n);
    if(j>0&&i>0&&board[i-1][j-1]=='@')
        used(i-1,j-1,m,n);
    return;
}

int main()
{
    int m,n;
    while(cin>>m>>n&&m!=0)
    {

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                cin>>board[i][j];
        int ans=0;
         for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                if(board[i][j]=='@')
            {
                ans++;
                used(i,j,m,n);
            }
        cout<<ans<<endl;
    }
}
