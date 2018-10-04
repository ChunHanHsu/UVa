#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int a;
    while(cin>>a)
    {
        double f[101],ff[101];
        for(int i=0; i<a; i++)
            cin>>f[i]>>ff[i];

        int b;
        cin>>b;

        double g[101],gg[101];
        for(int i=0; i<b; i++)
            cin>>g[i]>>gg[i];

        int conf=0,cong=0;
        double lf=ff[0],lg=gg[0];
        double mi=99999999;

        while(conf<a&&cong<b)
        {
            if(f[conf]>=g[cong]&&mi>f[conf])
            {
                mi=f[conf];
            }
            if(g[cong]>f[conf]&&mi>g[cong])
            {
                mi=g[cong];
            }

            if(lf<=lg)
            {
                lf+=ff[conf+1];
                conf++;
            }
            else
            {
                lg+=gg[cong+1];
                cong++;
            }
        }
        if(conf==a)
        {
            for(; cong<b; cong++)
                if(lg<=lf&&g[cong]>f[conf-1]&&mi>g[cong])
                    mi=g[cong];
        }
        if(cong==b)
        {
            for(; conf<a; conf++)
                if(lf<=lg&&f[conf]>=g[cong-1]&&mi>f[conf])
                    mi=f[conf];
        }
        cout<<fixed<<setprecision(3)<<mi<<endl;
    }
}
