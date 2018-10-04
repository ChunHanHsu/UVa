#include<iostream>

using namespace std;

int cou(int a,int b)
{
    b++;
    if(a==1) return b;
    if(a%2==0)return cou(a/2,b);
    else return cou(a*3+1,b);
}

int main()
{
    int i,j,ans,c;
    while(cin>>i>>j)
    {
        cout<<i<<" "<<j<<" ";
        ans=0;
        if(j<i) swap(i,j);
        for(;i<=j;i++)
        {
            c=cou(i,0);
            if(ans<c)ans=c;
        }
        cout<<ans<<endl;
    }
}
