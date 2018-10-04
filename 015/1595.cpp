#include<iostream>

using namespace std;

int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        int b;
        cin>>b;

        double x[1100],y[1100],sumx=0;
        for(int i=0;i<b;i++)
        {
            cin>>x[i]>>y[i];
            sumx+=x[i];
        }
        sumx/=b;

        bool ans=0;
        for(int i=0;i<b;i++)
        {
            ans=0;
            for(int j=0;j<b;j++)
            {
                if(sumx*2-x[i]==x[j]&&y[i]==y[j])
                  {
                      ans=1;
                      break;
                  }
            }
            if(ans==0)
                break;
        }
        if(ans==1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
