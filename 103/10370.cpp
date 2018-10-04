#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int c;
    cin>>c;
    while(c--)
    {
        int N,n[1001]={},sum=0,big=0;
        double ans;
        cin>>N;
        for(int i=0;i<N;i++)
        {
                cin>>n[i];
                sum+=n[i];
        }
        for(int i=0;i<N;i++)
        {
            if(n[i]>(sum/N))
                big++;
        }

        ans=big*100.0/N;
        cout<<fixed<<setprecision(3)<<ans<<"%\n";
    }
}
