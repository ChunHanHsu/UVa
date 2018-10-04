#include<iostream>
#include<vector>
using namespace std;

vector<string> M;
int f( int x,int y,int ans)
{
    ans++;
    M[y][x]='L';
    if(x+1<M[y].size()&&M[y][x+1]=='W')
        ans=f(x+1,y,ans);
    if(x>0&&M[y][x-1]=='W')
        ans=f(x-1,y,ans);
    if(y+1<M.size()&&M[y+1][x]=='W')
        ans=f(x,y+1,ans);
    if(y>0&&M[y-1][x]=='W')
        ans=f(x,y-1,ans);
    if(y+1<M.size()&&x+1<M[y].size()&&M[y+1][x+1]=='W')
        ans=f(x+1,y+1,ans);
    if(y+1<M.size()&&x>0&&M[y+1][x-1]=='W')
        ans=f(x-1,y+1,ans);
    if(y>0&&x+1<M[y].size()&&M[y-1][x+1]=='W')
        ans=f(x+1,y-1,ans);
    if(y>0&&x>0&&M[y-1][x-1]=='W')
        ans=f(x-1,y-1,ans);
    return ans;
}

int main()
{
    int T;
    cin>>T;
    vector<string> CLEAR,M2;
    bool second=0;
    string c;
    while(cin>>c&&T!=0)
    {
        int x,y=0;
        if(c[0]=='L'||c[0]=='W')
        {
            if(second==1)
            {
                second=0;
                M=CLEAR;
                T--;
                cout<<endl;
            }
            M.push_back(c);
        }
        else
        {
            int m=M.size(),n=M[0].size();
            for(int i=0;i<c.size();i++)
                y=y*10+c[i]-'0';
            cin>>x;
            x--;
            y--;
            M2=M;
            cout<<f(x,y,0)<<endl;
            M=M2;
            second=1;
        }
    }
}
