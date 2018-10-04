#include<iostream>

using namespace std;

char board[110][110]={};

int main()
{
    int x,y,T=0;
    while(cin>>x>>y&&x!=0)
    {
        if(T!=0)
            cout<<endl;
        for(int i=1;i<=x;i++)
            for(int j=1;j<=y;j++)
                cin>>board[i][j];

        int ans[110][110]={};

        for(int i=1;i<=x;i++)
            for(int j=1;j<=y;j++)
                if(board[i][j]=='*')
                {
                    ans[i][j]=-1;
                    if(ans[i+1][j]!=-1)
                        ans[i+1][j]++;
                    if(ans[i-1][j]!=-1)
                        ans[i-1][j]++;
                    if(ans[i][j+1]!=-1)
                        ans[i][j+1]++;
                    if(ans[i][j-1]!=-1)
                        ans[i][j-1]++;
                    if(ans[i+1][j+1]!=-1)
                        ans[i+1][j+1]++;
                    if(ans[i+1][j-1]!=-1)
                        ans[i+1][j-1]++;
                    if(ans[i-1][j+1]!=-1)
                        ans[i-1][j+1]++;
                    if(ans[i-1][j-1]!=-1)
                        ans[i-1][j-1]++;
                }
        T++;
        cout<<"Field #"<<T<<":\n";
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                if(ans[i][j]==-1)
                    cout<<"*";
                else
                    cout<<ans[i][j];
            }
            cout<<endl;
        }
    }
}
