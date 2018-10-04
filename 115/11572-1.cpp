#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
     int t;
    cin>>t;
     while(t--)
    {
        int a,b,ans=0,del=0;
        vector<int> line;
        map<int,int> where;
        cin>>a;
        for(int i=1;i<=a;i++)
        {
            cin>>b;
            if(where[b]!=0)
            {
                if((line.size()-del)>ans)
                    ans=line.size()-del;
                if(del<where[b])
                {
                    del=where[b];
                }
                where[b]=i;
            }
            if(where[b]==0)
            {
                where[b]=i;
            }

            line.push_back(b);
        }
        if((line.size()-del)>ans)
            ans=line.size()-del;
        cout<<ans<<endl;
    }
}
