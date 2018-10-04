#include<iostream>

using namespace std;

int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        int b,c;
        cin>>b>>c;
        for(int i=0;i<c;i++)
        {
            for(int j=1;j<=b;j++)
            {
                for(int k=0;k<j;k++)
                    cout<<j;
                cout<<endl;
            }
            for(int j=b-1;j>=1;j--)
            {
                for(int k=0;k<j;k++)
                    cout<<j;
                cout<<endl;
            }
            if(a!=0||i!=c-1)
                cout<<endl;
        }
    }
}
