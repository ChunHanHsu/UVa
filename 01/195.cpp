#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<char> > ans;
void backtrack(vector<char> S, vector<bool> used,vector<char> temp,int L)
{
    char last_letter = '\0';
    for(int i=0;i<S.size();i++)
    {
        if(used[i]==0&&S[i]!=last_letter)
        {
            last_letter=S[i];
            temp[L]=S[i];
            used[i]=1;
            if(L+1!=S.size())
                backtrack(S,used,temp,L+1);
            else
                ans.push_back(temp);
            used[i]=0;
        }
    }
}

int main()
{
    int T;
    cin>>T;
    cin.get();
    while(T--)
    {
        vector<vector<char> > zero;
        ans=zero;
        vector<char> S;
        vector<bool> used;
        int Aa[53]={};
        char c;
        while(cin.get(c)&&c!='\n')
        {
            if(c>='A'&&c<='Z')
                Aa[(c-'A')*2]++;
            else
                Aa[(c-'a')*2+1]++;
             used.push_back(0);
        }
        for(int i=0;i<53;i++)
            for(int j=0;j<Aa[i];j++)
            {
                if(i%2==0)
                    S.push_back(i/2+'A');
                else
                    S.push_back((i-1)/2+'a');
            }
        vector<char> temp=S;
        backtrack(S,used,temp,0);
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++)
                cout<<ans[i][j];
            cout<<endl;
        }
    }
}
