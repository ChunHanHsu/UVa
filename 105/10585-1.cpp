#include<iostream>
#include<map>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        cin>>a;

        long double sumx=0,sumy=0,x[10001],y[10001];
        for(int i=0;i<a;i++)
        {
            cin>>x[i]>>y[i];
            sumx+=x[i];
            sumy+=y[i];
        }
        sumx/=a;
        sumy/=a;

        map<long double,int> r;
        int many=0;
        for(int i=0;i<a;i++)
        {
            if(r[x[i]* 10000000+y[i]]==0)
            {
                many++;
                r[x[i]* 10000000+y[i]]=1;
            }
            else if(r[x[i]* 10000000+y[i]]==1)
            {
                many--;
                r[x[i]* 10000000+y[i]]=0;
            }
            if(r[(sumx*2-x[i])* 10000000+(sumy*2-y[i])]==0)
            {
                many++;
                r[(sumx*2-x[i])* 10000000+(sumy*2-y[i])]=1;
            }
            else if(r[(sumx*2-x[i])* 10000000+(sumy*2-y[i])]==1)
            {
                many--;
                r[(sumx*2-x[i])* 10000000+(sumy*2-y[i])]=0;
            }
        }
        if(many==0) cout<<"yes\n";
        else        cout<<"no\n";
    }
}
