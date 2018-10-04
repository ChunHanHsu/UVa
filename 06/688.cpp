#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int main()
{
    int a,T=0;
    while(cin>>a)
    {
        T++;
        if(a==0)break;

        double X[101],Y[101],R[101];
        double x[202],y[202];
        for(int i=0 ;i<a;i++)
        {
            cin>>X[i]>>Y[i]>>R[i];
            x[i*2]=X[i]-R[i];
            y[i*2]=Y[i]-R[i];
            x[i*2+1]=X[i]+R[i];
            y[i*2+1]=Y[i]+R[i];
        }
        sort(x,x+a*2);
        sort(y,y+a*2);

        double ans=0.0;
        for(int i=0;i<(a*2-1);i++)
            for(int j=0;j<(a*2-1);j++)
                for(int k=0;k<a;k++)
                    if(x[i]>=X[k]-R[k]&&x[i+1]<=X[k]+R[k])
                        if(y[j]>=Y[k]-R[k]&&y[j+1]<=Y[k]+R[k])
                        {
                            ans+=(x[i+1]-x[i])*(y[j+1]-y[j]);
                            break;
                        }

        cout<<T<<" "<<fixed<<setprecision(2)<<ans<<endl;

    }
}
