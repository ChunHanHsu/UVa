#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int check,a,b;
        bool ans=1;
        cin>>a>>b;
        check=abs(a-b);
        n--;
        while(n--)
        {
            cin>>a>>b;
            if(check!=abs(a-b))
                ans=0;
        }
        if(ans==1)
            cout<<"yes\n";
        else
            cout<<"no\n";
        if(t!=0)cout<<endl;
    }
}

