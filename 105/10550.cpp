#include<iostream>

using namespace std;

int main()
{
    int a,b,c,d;
    while(cin>>a>>b>>c>>d)
    {
        if(a==0&&b==0&&c==0&&d==0) break;
        int ans=120;
        ans+=40-b+a;
        if(40-b+a>=40)
            ans-=40;
        ans+=40-b+c;
        if(40-b+c>=40)
            ans-=40;
        ans+=40-d+c;
        if(40-d+c>=40)
            ans-=40;
        ans=ans*360/40;
        cout<<ans<<endl;
    }
}
