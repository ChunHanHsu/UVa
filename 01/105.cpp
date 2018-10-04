#include<iostream>

using namespace std;

int H[10001]={},maxnum=0,minnum=1000000;

int main()
{
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        if(a>c)
            swap(a,c);
        for(int i=a;i<c;i++)
            if(H[i]<b)
            H[i]=b;
        if(maxnum<c)
            maxnum=c;
        if(minnum>a)
            minnum=a;
    }
    int lesthigh=0;
    bool firstspace=0;
    for(int i=minnum;i<=maxnum;i++)
    {
        if(lesthigh!=H[i])
        {
            if (firstspace==0)
                firstspace=1;
            else
                cout<<" ";
            cout<<i<<" "<<H[i];
            lesthigh=H[i];
        }
    }
    cout<<endl;
}
