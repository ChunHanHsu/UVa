#include<iostream>
#include<map>
#include<vector>

using namespace std;

map<char,bool > used;

void DFS(map<char,vector<char> > line,vector<char> Vmane,char T,int &Del)
{
    Del++;
    used[T]=0;
    for(int i=0;i<line[T].size();i++)
        if(used[line[T][i]]!=0)
            DFS(line,Vmane,line[T][i],Del);
}

int main()
{
    int V,E;
    while(cin>>V>>E)
    {
        used.clear();
        int F,C=0,Del=0;
        map<char,vector<char> > line;
        vector<char> Vmane;
        for(int i=0;i<E;i++)
        {
            char a,b;
            cin>>a>>b;
            line[a].push_back(b);
            line[b].push_back(a);
            used[a]=1;
            used[b]=1;
            Vmane.push_back(a);
        }
        for(int i=0;i<Vmane.size();i++)
        {
            if(used[Vmane[i]]==1)
            {
                C++;
                DFS(line,Vmane,Vmane[i],Del);
            }
        }

        C+=(V-Del);
        F=E+C-V+1;
        cout<<F<<endl;
    }
}

//V+F=E+C+1 => F=E+C-V+1
