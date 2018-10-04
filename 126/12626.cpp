#include<iostream>
#include<map>
#include<string>

using namespace std;

//MARGIT

int main()
{
    string a="MARGARITA";
    map<char,int> needused,many;
    for(int i=0;i<a.size();i++)
    {
        needused[a[i]]=0;
        many[a[i]]=0;
    }
    for(int i=0;i<a.size();i++)
        needused[a[i]]++;
    int t;
    cin>>t;
    while(t--)
    {
        int ans=600;
        cin>>a;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]=='M'||a[i]=='A'||a[i]=='R'||a[i]=='G'||a[i]=='I'||a[i]=='T')
                many[a[i]]++;
        }
        map<char,int> ::iterator it1=many.begin(),it2=needused.begin();
        for(;it1!=many.end();it1++,it2++)
        {
            if((it1->second)/(it2->second)<ans)
                ans=(it1->second)/(it2->second);
            it1->second=0;
        }
        cout<<ans<<endl;
    }
}
