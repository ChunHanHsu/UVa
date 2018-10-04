#include<iostream>
#include<vector>
using namespace std;


void find(int v,bool check[],vector<int> N[])
{
    check[v]=1;
    for(int i=0;i<N[v].size();i++)
    {
        if(check[N[v][i]]==0)
            find(N[v][i],check,N);
    }
    return;
}

int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        vector<int> N[101];
        int first,v;
        while(cin>>first&&first!=0)
            while(cin>>v&&v!=0)
                N[first].push_back(v);

        cin>>first;
        for(int i=0;i<first;i++)
        {
            bool check[101]={};
            vector<int> ans;
            cin>>v;
            for(int i=0;i<N[v].size();i++)
            {
                if(check[N[v][i]]==0)
                    find(N[v][i],check,N);
            }
            for(int i=1;i<=n;i++)
                if(check[i]==0)
                    ans.push_back(i);
            cout<<ans.size();
            for(int i=0;i<ans.size();i++)
                cout<<" "<<ans[i];
            cout<<endl;
        }
    }
}
