#include<iostream>
#include<vector>
using namespace std;

struct path{
    int next,w;
};



int main(){
    int Case,counter=0;
    cin>>Case;
    while(Case--){
        counter++;
        int n,p,S,T;
        int ans[20000]={};
        vector<vector<path> >table;
        cin>>n>>p>>S>>T;
        for(int i=0;i<n;i++){
            vector<path> temp;
            table.push_back(temp);
            ans[i]=-1;
        }
        for(int i=0;i<p;i++){
            int s,t,w;
            cin>>s>>t>>w;
            path temp_p;
            temp_p.next=t;
            temp_p.w=w;
            table[s].push_back(temp_p);
            swap(temp_p.next,s);
            table[s].push_back(temp_p);
        }

        vector<int> buffer;
        bool used[20000]={};
        buffer.push_back(S);
        ans[S]=0;
        used[S]=true;
        while(!buffer.empty()){
            int point=buffer[0];
            buffer.erase(buffer.begin());
            used[point]=false;
            for(int i=0;i<table[point].size();i++){
                if(ans[table[point][i].next]==-1){
                    ans[table[point][i].next]=ans[point]+table[point][i].w;
                    buffer.push_back(table[point][i].next);
                    used[table[point][i].next]=true;
                }
                else if(ans[table[point][i].next]>ans[point]+table[point][i].w){
                    ans[table[point][i].next]=ans[point]+table[point][i].w;
                    if(!used[table[point][i].next]){
                        buffer.push_back(table[point][i].next);
                        used[table[point][i].next]=true;
                    }
                }
            }
        }
        cout<<"Case #"<<counter<<": ";
        if(ans[T]==-1)
            cout<<"unreachable"<<endl;
        else
            cout<<ans[T]<<endl;
    }
}
