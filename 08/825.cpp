#include<iostream>
#include<string>
#include<vector>
using namespace std;

int x,y;
int board[1000][1000];

void DP()
{
    for(int i=1; i<=x; i++)
    {
        if(board[i][1]==-1)
            break;
        board[i][1]=1;
    }
    for(int i=1; i<=y; i++)
    {
        if(board[1][i]==-1)
            break;
        board[1][i]=1;
    }

    for(int i=2; i<=x; i++)
        for(int j=2; j<=y; j++)
        {
            if(board[i][j]==-1)
                continue;
            board[i][j]=board[i-1][j]+board[i][j-1];
            if(board[i-1][j]==-1)
                board[i][j]++;
            if(board[i][j-1]==-1)
                board[i][j]++;
        }
}
void clean()
{
    for(int i=0; i<=x; i++)
        for(int j=0; j<=y; j++)
            board[i][j]=0;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        cin.get();
        clean();
        string a;
        for(int i=1; i<=x; i++)
        {
            vector<int> temp;
            int c=0;
            getline(cin,a);
            for(int j=0;j<a.size();j++)
            {
                if(a[j]>='0'&&a[j]<='9')
                    c=c*10+a[j]-'0';
                else
                {
                    temp.push_back(c);
                    c=0;
                }
            }
             temp.push_back(c);
            for(int j=1;j<temp.size();j++)
                board[i][temp[j]]=-1;
        }
        DP();
        cout<<board[x][y]<<endl;
        if(t!=0)
            cout<<endl;
    }
}
