#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<double> fr,to,r,line,ans1,ans2;
        double a,b,c,g;
        for(int i=0;i<n;i++)
        {
            cin>>a>>g>>b>>g>>c;
            if(a>b)
            {
                double temp;
                temp=a;
                a=b;
                b=temp;
            }
            fr.push_back(a);
            to.push_back(b);
            r.push_back(c);
            line.push_back(a);
            line.push_back(b);
        }
        sort(line.begin(),line.end());
        ans2.push_back(1.0);
        for(int i=0;i<line.size();i++)
        {
            if(ans1.empty()||ans1[ans1.size()-1]!=line[i])
            {
                 ans1.push_back(line[i]);
                 for(int j=0;j<n;j++)
                 {
                     if(fr[j]==ans1[ans1.size()-1])
                        ans2[ans1.size()-1]*=r[j];
                     if(to[j]==ans1[ans1.size()-1])
                        ans2[ans1.size()-1]/=r[j];
                 }
                 ans2.push_back(ans2[ans2.size()-1]);
            }
        }
        cout<<ans1.size()+1<<endl;
        for(int i=0;i<=ans1.size();i++)
        {
            if(i==0)
                cout<<fixed<<setprecision(3)<<"-inf "<<ans1[i]<<" "<<1.000<<endl;
            else if(i==ans1.size())
                cout<<fixed<<setprecision(3)<<ans1[i-1]<<" +inf "<<1.000<<endl;
            else
                cout<<fixed<<setprecision(3)<<ans1[i-1]<<" "<<ans1[i]<<" "<<ans2[i-1]<<endl;
        }
        if(t!=0)
            cout<<endl;
    }
}
