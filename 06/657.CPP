#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

char board[51][51];
int T=0,w,h;
void check_dot(int i,int j)
{
    board[i][j]='*';
    if(j+1<w&&board[i][j+1]=='X')
        check_dot(i,j+1);
    if(j>0&&board[i][j-1]=='X')
        check_dot(i,j-1);
    if(i+1<h&&board[i+1][j]=='X')
        check_dot(i+1,j);
    if(i>0&&board[i-1][j]=='X')
        check_dot(i-1,j);
    return;
}

int dice(int i,int j,int ans)
{
    if(board[i][j]=='X')
    {
        ans++;
        check_dot(i,j);
    }
    board[i][j]='.';
    if(j+1<w&&board[i][j+1]=='*')
        ans=dice(i,j+1,ans);
    if(j+1<w&&board[i][j+1]=='X')
    {
        ans++;
        check_dot(i,j+1);
        ans=dice(i,j+1,ans);
    }
    if(j>0&&board[i][j-1]=='*')
        ans=dice(i,j-1,ans);
    if(j>0&&board[i][j-1]=='X')
    {
        ans++;
        check_dot(i,j-1);
        ans=dice(i,j-1,ans);
    }
    if(i+1<h&&board[i+1][j]=='*')
        ans=dice(i+1,j,ans);
    if(i+1<h&&board[i+1][j]=='X')
    {
        ans++;
        check_dot(i+1,j);
        ans=dice(i+1,j,ans);
    }
    if(i>0&&board[i-1][j]=='*')
        ans=dice(i-1,j,ans);
    if(i>0&&board[i-1][j]=='X')
    {
        ans++;
        check_dot(i-1,j);
        ans=dice(i-1,j,ans);
    }
    return ans;

}

int main()
{
    while(cin>>w>>h&&w!=0)
    {
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
            cin>>board[i][j];

        vector<int> ans;
         for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                if(board[i][j]=='*'||board[i][j]=='X')
                    ans.push_back(dice(i,j,0));

        sort(ans.begin(),ans.end());
        T++;
        cout<<"Throw "<<T<<endl;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i];
            if(i!=ans.size()-1)
                cout<<" ";
        }
        cout<<endl<<endl;
    }

}
