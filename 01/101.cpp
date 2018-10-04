#include<iostream>
#include<vector>

using namespace std;

int main()
{
        int a,d,f;
        string c,e;
        cin>>a;
        vector<int> ans[a],wait;
        int wh[a];
        for(int i=0;i<a;i++)   { ans[i].push_back(i);wh[i]=i;}
        while(cin>>c)
        {
            if(c=="quit") break;
            cin>>d>>e>>f;
            if(wh[f]==wh[d])continue;
            if(c=="move")
            {
                 if(e=="onto")
                 {
                     while(ans[wh[f]].back()!=f)
                     {
                         wh[ans[wh[f]].back()]=ans[wh[f]].back();
                         ans[ans[wh[f]].back()].push_back(ans[wh[f]].back());
                         ans[wh[f]].pop_back();
                     }
                     while(ans[wh[d]].back()!=d)
                     {
                         wh[ans[wh[d]].back()]=ans[wh[d]].back();
                         ans[ans[wh[d]].back()].push_back(ans[wh[d]].back());
                         ans[wh[d]].pop_back();
                     }

                     ans[wh[f]].push_back(ans[wh[d]].back());
                     ans[wh[d]].pop_back();
                     wh[d]=wh[f];
                 }
                 else
                 {
                      while(ans[wh[d]].back()!=d)
                     {
                         wh[ans[wh[d]].back()]=ans[wh[d]].back();
                         ans[ans[wh[d]].back()].push_back(ans[wh[d]].back());
                         ans[wh[d]].pop_back();
                     }
                     ans[wh[f]].push_back(ans[wh[d]].back());
                     ans[wh[d]].pop_back();
                     wh[d]=wh[f];
                 }
            }
            else
            {
                if(e=="onto")
                 {while(ans[wh[f]].back()!=f)
                     {
                         wh[ans[wh[f]].back()]=ans[wh[f]].back();
                         ans[ans[wh[f]].back()].push_back(ans[wh[f]].back());
                         ans[wh[f]].pop_back();
                     }
                     while(ans[wh[d]].back()!=d)
                     {
                         wh[ans[wh[d]].back()]=wh[f];
                         wait.push_back(ans[wh[d]].back());
                         ans[wh[d]].pop_back();
                     }

                     ans[wh[f]].push_back(ans[wh[d]].back());
                     ans[wh[d]].pop_back();
                     while(wait.size()!=0)
                     {
                       ans[wh[f]].push_back(wait.back());
                       wait.pop_back();
                     }
                     wh[d]=wh[f];
                 }
                 else
                 {
                      while(ans[wh[d]].back()!=d)
                     {
                         wh[ans[wh[d]].back()]=wh[f];
                         wait.push_back(ans[wh[d]].back());
                         ans[wh[d]].pop_back();
                     }
                     ans[wh[f]].push_back(ans[wh[d]].back());
                     ans[wh[d]].pop_back();
                     while(wait.size()!=0)
                     {
                       ans[wh[f]].push_back(wait.back());
                       wait.pop_back();
                     }
                     wh[d]=wh[f];
                 }
            }
        }
        for(int i=0;i<a;i++)
        {
            cout<<i<<":";
            for(int j=0;j<ans[i].size();j++)
            {
                cout<<" "<<ans[i][j];
            }
            cout<<endl;
        }
        return 0;
}
