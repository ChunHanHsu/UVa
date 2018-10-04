#include<iostream>
#include<cmath>
#include<map>

using namespace std;

int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int s,n;
        cin>>s>>n;

        double x[1001],y[1001],r[1001];
        int ans=0;

        for(int i=1;i<=n;i++)
            cin>>x[i]>>y[i]>>r[i];

        int an=0;
        for(double i=1;i<=s;i++)
        {
            map<int,int> used;
            for(int j=1;j<=n;j++)
            {
                int rx=x[j];
                if(x[j]-r[j]<=i&&x[j]>=i)
                {
                    double z=pow((r[j]*r[j]-(x[j]-i)*(x[j]-i)),0.5);
                    int miy=y[j]-z,may=y[j]+z;
                    if(miy<0)
                        miy=0;
                    if(may<y[j]+z)
                        may++;
                    if(may>s)
                        may=s;
                    for(;miy+1<may+1;miy++)
                        used[miy+1]=1;
                }
                else if(x[j]+r[j]>=i-1&&x[j]<=i-1)
                {
                    double z=pow((r[j]*r[j]-(x[j]-i+1)*(x[j]-i+1)),0.5);
                    int miy=y[j]-z,may=y[j]+z;
                    if(miy<0)
                        miy=0;
                    if(may<y[j]+z)
                        may++;
                    if(may>s)
                        may=s;
                    for(;miy+1<may+1;miy++)
                        used[miy+1]=1;
                }
                else if(x[j]!=rx&&x[j]>=i-1&&x[j]<=i)
                {
                    int miy=y[j]-r[j],may=y[j]+r[j];
                    if(miy<0)
                        miy=0;
                    if(may<y[j]+r[j])
                        may++;
                    if(may>s)
                        may=s;
                    for(;miy+1<may+1;miy++)
                        used[miy+1]=1;
                }
            }
            an+=used.size();
        }
        cout<<an<<endl;
    }
}
