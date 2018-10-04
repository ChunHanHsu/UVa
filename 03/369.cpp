
#include<iostream>

using namespace std;
//19
struct node
{
    unsigned long int first,second;
};
node board[100][100];
void make_board()
{
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
        {
            board[i][j].second=0;
            board[i][j].first=0;
            if(i==0||j==0)
                board[i][j].second=1;
            else if(i+j>101) break;
            else
            {
                board[i][j].second=board[i][j-1].second+board[i-1][j].second;
                board[i][j].first=board[i][j-1].first+board[i-1][j].first;
            }
            if(board[i][j].second>100000000000000)
            {
                board[i][j].first+=board[i][j].second/100000000000000;
                board[i][j].second=board[i][j].second%100000000000000;
            }
        }
}

int main()
{
    make_board();
    int n,m;
    while(cin>>n>>m&&n!=0)
    {
        unsigned long int ans[2]={};
        cout<<n<<" things taken "<<m<<" at a time is ";
        n=n-m;
        if(board[n][m].first!=0)cout<<board[n][m].first;
        cout<<board[n][m].second<<" exactly.\n";
    }
}
