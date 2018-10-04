#include<iostream>
#include<iomanip>
using namespace std;

struct node
{
    unsigned long long first,second,thired,forth;
};
bool overflow[1000];
node board[1000][1000];
void make_board()
{
    for(int i=0;i<1000;i++)
        overflow[i]=true;
    for(int i=0;i<1000;i++)
        for(int j=0;j<1000;j++)
        {
            board[i][j].forth=0;
            board[i][j].thired=0;
            board[i][j].second=0;
            board[i][j].first=0;
            if(i==0||j==0)
                board[i][j].forth=1;
            else
            {
                board[i][j].forth=board[i][j-1].forth+board[i-1][j].forth;
                board[i][j].thired=board[i][j-1].thired+board[i-1][j].thired;
                board[i][j].second=board[i][j-1].second+board[i-1][j].second;
                board[i][j].first=board[i][j-1].first+board[i-1][j].first;
            }

            if(board[i][j].forth>1000000000000000)
            {
                board[i][j].thired+=board[i][j].forth/1000000000000000;
                board[i][j].forth=board[i][j].forth%1000000000000000;
            }
            if(board[i][j].thired>1000000000000000)
            {
                board[i][j].second+=board[i][j].thired/1000000000000000;
                board[i][j].thired=board[i][j].thired%1000000000000000;
            }
            if(board[i][j].second>1000000000000000)
            {
                board[i][j].first+=board[i][j].second/1000000000000000;
                board[i][j].second=board[i][j].second%1000000000000000;
            }
            if(board[i][j].first>2000000000000000)
            {
                board[i][j].forth=0;
                board[i][j].thired=0;
                board[i][j].second=0;
                board[i][j].first=0;
                overflow[i+j]=false;
                break;
            }
        }
}

int main()
{
    make_board();
    int i=0;
    while(overflow[i])
    {
        for(int j=0;j<=i;j++)
        {
            if(board[i-j][j].first!=0)cout<<board[i-j][j].first;
            if(board[i-j][j].second!=0&&board[i-j][j].first!=0)cout<<setw(15)<<setfill('0')<<board[i-j][j].second;
            else if(board[i-j][j].second!=0) cout<<board[i-j][j].second;
            if(board[i-j][j].thired!=0&&board[i-j][j].second!=0)cout<<setw(15)<<setfill('0')<<board[i-j][j].thired;
            else if(board[i-j][j].thired!=0) cout<<board[i-j][j].thired;
            if(board[i-j][j].forth!=0&&board[i-j][j].thired!=0)cout<<setw(15)<<setfill('0')<<board[i-j][j].forth;
            else if(board[i-j][j].forth!=0) cout<<board[i-j][j].forth;
            if(j!=i)cout<<" ";
            else cout<<endl;
        }
        i++;
    }
}
