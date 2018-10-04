#include<iostream>

using namespace std;

char board[201][201];

bool w_win(int N,int i,int j)
{
    if(j==N-1)
        return true;
    if(board[i][j]=='w')
    {
        board[i][j]='b';
        if(i>0&&j>0&&i<N&&j<N&&board[i-1][j-1]=='w'&&w_win(N,i-1,j-1))
            return true;
        if(i>0&&j>=0&&i<N&&j<N&&board[i-1][j]=='w'&&w_win(N,i-1,j))
            return true;
        if(i>=0&&j>0&&i<N&&j<N&&board[i][j-1]=='w'&&w_win(N,i,j-1))
            return true;
        if(i>=0&&j>=0&&i<N&&j<N-1&&board[i][j+1]=='w'&&w_win(N,i,j+1))
            return true;
        if(i>=0&&j>=0&&i<N-1&&j<N&&board[i+1][j]=='w'&&w_win(N,i+1,j))
            return true;
        if(i>=0&&j>=0&&i<N-1&&j<N-1&&board[i+1][j+1]=='w'&&w_win(N,i+1,j+1))
            return true;
    }
    return false;
}

int main()
{
    int N,con=0;
    while(cin>>N&&N!=0)
    {
        con++;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cin>>board[i][j];

        bool ans=1;
        for(int i=0; i<N; i++)
        {
            if(w_win(N,i,0))
            {
                cout<<con<<" W\n";
                ans=0;
                break;
            }
        }
        if(ans==1)
            cout<<con<<" B\n";
    }
}
