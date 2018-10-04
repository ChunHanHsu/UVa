#include<iostream>
#include<iomanip>
#include<map>
using namespace std;

int main()
{
    int n;
    string temp;
    cin>>n;
    getline(cin,temp);
    getline(cin,temp);
    while(n--)
    {
        map<string,int> tree;
        int total=0,i;
        while(1)
        {
            getline(cin,temp);
            if(temp=="") break;
            tree[temp]++;
            total++;
        }

        for(map<string,int>::iterator it=tree.begin();it!=tree.end();it++)
        {
            cout<<it->first<<" "<<fixed<<setprecision(4)<<((double)it->second/total*100.00)<<endl;
        }
        if(n!=0)
            cout<<endl;
    }
}
