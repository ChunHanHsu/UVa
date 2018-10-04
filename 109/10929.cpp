#include<iostream>
#include<string>
using namespace std;

int main()
{
    string c;
    while(cin>>c)
    {
        if(c.size()==1&&c[0]=='0')
            break;
        int a=0,b=0;
        for(int i=0;i<c.size();i++)
        {
            a+=c[i++]-'0';
            if(i<c.size())
                b+=c[i]-'0';
        }
        if((a-b)%11==0)
            cout<<c<<" is a multiple of 11.\n";
        else
            cout<<c<<" is not a multiple of 11.\n";
    }
}
