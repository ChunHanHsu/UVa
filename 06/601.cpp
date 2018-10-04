#include<iostream>

using namespace std;

char board[85][85]={};

bool checkwin(char C,int m,int i,int j,int k,bool used[][85])
{
    used[i][j]=1;
    if(j+1<m&&board[i][j+1]==C&&used[i][j+1]!=1)
        if(j+1==m-1&&C=='W'||checkwin(C,m,i,j+1,k,used))
           return true;
    if(i+1<m&&board[i+1][j]==C&&used[i+1][j]!=1)
        if(i+1==m-1&&C=='B'||checkwin(C,m,i+1,j,k,used))
           return true;
    if(i>0&&board[i-1][j]==C&&used[i-1][j]!=1)
        if(checkwin(C,m,i-1,j,k,used))
            return true;
    if(j>0&&board[i][j-1]==C&&used[i][j-1]!=1)
        if(checkwin(C,m,i,j-1,k,used))
            return true;

    if(j+1<m&&board[i][j+1]=='U'&&k==1&&used[i][j+1]!=1)
        if(j+1==m-1&&C=='W'||checkwin(C,m,i,j+1,k-1,used))
           return true;
    if(i+1<m&&board[i+1][j]=='U'&&k==1&&used[i+1][j]!=1)
        if(i+1==m-1&&C=='B'||checkwin(C,m,i+1,j,k-1,used))
           return true;
    if(i>0&&board[i-1][j]=='U'&&k==1&&used[i-1][j]!=1)
        if(checkwin(C,m,i-1,j,k-1,used))
           return true;
    if(j>0&&board[i][j-1]=='U'&&k==1&&used[i][j-1]!=1)
        if(checkwin(C,m,i,j-1,k-1,used))
            return true;

    return false;
}

int main()
{
    int m;
    while(cin>>m&&m!=0)
    {
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                cin>>board[i][j];

        int ans=4;
        for(int i=0;i<m&&ans==4;i++)
        {
            bool used[85][85]={};
            if(board[i][0]=='W'&&checkwin('W',m,i,0,0,used))
                ans=0;
        }
        for(int j=0;j<m&&ans==4;j++)
        {
            bool used[85][85]={};
            if(board[0][j]=='B'&&checkwin('B',m,0,j,0,used))
                ans=1;
        }
        for(int i=0;i<m&&ans==4;i++)
        {
            bool used[85][85]={};
            if(board[i][0]=='W'&&checkwin('W',m,i,0,1,used))
                ans=2;
            if(board[i][0]=='U'&&checkwin('W',m,i,0,0,used))
                ans=2;
        }
        for(int j=0;j<m&&ans==4;j++)
        {
            bool used[85][85]={};
            if(board[0][j]=='B'&&checkwin('B',m,0,j,1,used))
                ans=3;
            if(board[0][j]=='U'&&checkwin('B',m,0,j,0,used))
                ans=3;
        }
        if(m==1)
        {
            if(board[0][0]=='W')
                ans=0;
            if(board[0][0]=='B')
                ans=1;
            if(board[0][0]=='U')
                ans=2;
        }
        if(ans==0)
            cout<<"White has a winning path.\n";
        if(ans==1)
            cout<<"Black has a winning path.\n";
        if(ans==2)
            cout<<"White can win in one move.\n";
        if(ans==3)
            cout<<"Black can win in one move.\n";
        if(ans==4)
            cout<<"There is no winning path.\n";
    }
}
