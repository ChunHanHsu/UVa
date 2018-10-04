#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main()
{
    string c;
    while(cin>>c&&c!="#")
    {
        vector<stack<string> > Pile;
        stack<string> a;
        Pile.push_back(a);
        Pile[0].push(c);
        for(int i=0;i<51;i++)
        {
            cin>>c;
            Pile.push_back(a);
            Pile[i+1].push(c);
        }

        int many=52,where;
        bool p;
        for(int i=0;i<Pile.size();i++)
        {
            p=1;
            where=i;
            for(int j=where-3;j<where;j+=2)
            {
                if(j<0) continue;
                if(Pile[j].top()[0]==Pile[i].top()[0]||Pile[j].top()[1]==Pile[i].top()[1])
                {
                    p=0;
                    where=j;
                    j-=5;
                }
            }
            if(p==0)
            {
                Pile[where].push(Pile[i].top());
                Pile[i].pop();
                if(Pile[i].size()==0) { Pile.erase(Pile.begin()+i);many--;}
                i=where;
            }
        }
        cout<<many;
        if(many==1) cout<<" pile ";
        else        cout<<" piles ";
        cout<<"remaining:";
        for(int i=0;i<many;i++)  cout<<" "<<Pile[i].size();
        cout<<endl;
    }
    return 0;
}
