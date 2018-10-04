#include<iostream>
#include<vector>
using namespace std;

void backtrack(vector<int> S,vector<int> ans,int L,int R)
{
    for(int i=L;i<=S.size()-R;i++)
    {
        ans.push_back(S[i]);
        if(ans.size()==6)
        {
             for(int i=0;i<6;i++)
            {
                cout<<ans[i];
                if(i<5)
                    cout<<" ";
            }
            cout<<endl;
        }
        else
            backtrack(S,ans,i+1,R-1);
        ans.pop_back();
    }
}

int main()
{
    int n, T=0;
    while(cin>>n&&n!=0)
    {
        if(T!=0)
            cout<<endl;
        vector<int> S;
        int a;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            S.push_back(a);
        }
        vector<int> ans;
        backtrack(S,ans,0,6);
        T++;
    }
}
