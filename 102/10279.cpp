#include<iostream>

using namespace std;

char board[12][12],board2[12][12];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>board[i][j];

        int ans[12][12]={};
        bool boom=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                cin>>board2[i][j];
                if(board2[i][j]=='x'&&board[i][j]=='*')
                    boom=1;
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
            }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(board2[i][j]=='x'&&board[i][j]!='*')
                    cout<<ans[i][j];
                else if(boom==1&&board[i][j]=='*')
                    cout<<"*";
                else
                    cout<<".";
            }
                cout<<endl;
        }
        if(t!=0)
            cout<<endl;

    }
}
