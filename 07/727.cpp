#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main()
{
    char c;
    int a;
    cin>>a;
    cin.get();
    cin.get();
    while(a--)
    {
        string ans="";
        stack<char> s;
        while(cin.get(c))
        {
            if(c=='\n')break;
            if(c>='0'&&c<='9') ans+=c;
            else if(c=='*'||c=='/')
            {
                while(s.size()!=0&&(s.top()=='*'||s.top()=='/'))  { ans+=s.top(); s.pop();}
                s.push(c);
            }
            else if(c=='+'||c=='-')
            {
                while(s.size()!=0&&(s.top()=='*'||s.top()=='/'||s.top()=='+'||s.top()=='-')) { ans+=s.top(); s.pop();}
                s.push(c);
            }
            else if(c==')')
            {
                while(s.top()!='(') { ans+=s.top(); s.pop();}
                s.pop();
            }
            else if(c=='(') s.push(c);
            cin.get(c);
        }
        while(s.size()!=0) { ans+=s.top(); s.pop();}
        cout<<ans<<endl;
        if(a!=0)cout<<endl;
    }
}
