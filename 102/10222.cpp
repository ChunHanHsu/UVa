#include<iostream>
#include<string>
using namespace std;

string key="/`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

int main()
{
    char c;
    while(cin.get(c))
    {
        bool used=0;
        for(int i=1;i<key.size();i++)
        {
            if(c==key[i])
            {
                cout<<key[i-2];
                used=1;
                break;
            }
        }
        if(used==0)
        {
            cout<<c;
        }
    }
}
