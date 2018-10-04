#include<iostream>
#include<stack>
using namespace std;


int main()
{
    int a;
    cin>>a;
    cin.get();
    while(a--)
    {
        stack<char> left;
        bool ans=1;
        char c;
        while(cin.get(c))
        {
            if(c=='\n')break;
            else if(c=='('||c=='[') { left.push(c);}
            else if(c==')'&&(left.empty()||left.top()!='(')) { ans=0;}
            else if(c==']'&&(left.empty()||left.top()!='[')) { ans=0;}
            if((c==')'||c==']')&&!left.empty()) { left.pop();}
        }
        if(!left.empty()) { ans=0;}
        if(ans==1) { cout<<"Yes\n";}
        else { cout<<"No\n";}
    }
    return 0;
}
