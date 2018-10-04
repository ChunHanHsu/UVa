#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    int a;
    while(cin>>a)
    {
        int b=999999,c;
        bool check[3001]={},ans=1;
        for(int i=0;i<a;i++)
        {
            cin>>c;
            if(b!=999999)
            {
                if((abs(b-c)>=a||check[abs(b-c)]==1)&&ans==1)
                {
                    ans=0;
                }
                check[abs(b-c)]=1;
            }
            b=c;
        }
        if(ans==1) cout<<"Jolly\n";
        else cout<<"Not jolly\n";
    }
}
