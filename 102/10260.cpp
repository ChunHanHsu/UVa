#include<iostream>
#include<map>

using namespace std;

map<char,int> check;

int main()
{
    char c='A';
    for(int i=0;i<26;i++)
    {
        if(c+i=='B'||c+i=='F'||c+i=='P'||c+i=='V')
            check[c+i]=1;
        else if(c+i=='C'||c+i=='G'||c+i=='J'||c+i=='K'||c+i=='Q'||c+i=='S'||c+i=='X'||c+i=='Z')
            check[c+i]=2;
        else if(c+i=='D'||c+i=='T')
            check[c+i]=3;
        else if(c+i=='L')
            check[c+i]=4;
        else if(c+i=='M'||c+i=='N')
            check[c+i]=5;
        else if(c+i=='R')
            check[c+i]=6;
        else
            check[c+i]=0;
    }
    int checklest=0;
    while(cin.get(c))
    {
        if(c=='\n')
        {
            cout<<endl;
            checklest=0;
        }

        else
        {
            if(check[c]!=0&&checklest!=check[c])
            {
                cout<<check[c];
                checklest=check[c];
            }
            if(check[c]==0)
                checklest=check[c];
        }
    }
}
