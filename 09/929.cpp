#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node{
    int i,j,v;
    bool operator()(const node l,const node r ){return l.v>r.v;}
};






int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        vector<int> table,ans;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans.push_back(-1);
                int temp;
                cin>>temp;
                table.push_back(temp);
            }
        }
        int p_i=0,p_j=0,p_v;
        priority_queue<node,vector<node>,node > buffer;
        bool used[1000][1000]={};
        node temp;
        temp.i=p_i;
        temp.j=p_j;
        temp.v=table[p_i*m+p_j];
        ans[p_i*m+p_j]=table[p_i*m+p_j];
        buffer.push(temp);
        while(p_i!=n-1||p_j!=m-1){
            temp=buffer.top();
            p_i=temp.i;
            p_j=temp.j;
            p_v=temp.v;
            buffer.pop();
            if(used[p_i][p_j])continue;
            used[p_i][p_j]=true;
            //cout<<p_i<<" "<<p_j<<" "<<p_v<<endl;
            if(!used[p_i+1][p_j]&&p_i+1<=n-1&&(ans[(p_i+1)*m+p_j]==-1||ans[(p_i+1)*m+p_j]>ans[p_i*m+p_j]+table[(p_i+1)*m+p_j])){
                ans[(p_i+1)*m+p_j]=ans[p_i*m+p_j]+table[(p_i+1)*m+p_j];
                temp.i=p_i+1;
                temp.j=p_j;
                temp.v=ans[(p_i+1)*m+p_j];
                buffer.push(temp);
            }
            if(!used[p_i-1][p_j]&&p_i-1>=0&&(ans[(p_i-1)*m+p_j]==-1||ans[(p_i-1)*m+p_j]>ans[p_i*m+p_j]+table[(p_i-1)*m+p_j])){
                ans[(p_i-1)*m+p_j]=ans[p_i*m+p_j]+table[(p_i-1)*m+p_j];
                temp.i=p_i-1;
                temp.j=p_j;
                temp.v=ans[(p_i-1)*m+p_j];
                buffer.push(temp);
            }
            if(!used[p_i][p_j+1]&&p_j+1<=m-1&&(ans[p_i*m+p_j+1]==-1||ans[p_i*m+p_j+1]>ans[p_i*m+p_j]+table[p_i*m+p_j+1])){
                ans[p_i*m+p_j+1]=ans[p_i*m+p_j]+table[p_i*m+p_j+1];
                temp.i=p_i;
                temp.j=p_j+1;
                temp.v=ans[p_i*m+p_j+1];
                buffer.push(temp);
            }
            if(!used[p_i][p_j-1]&&p_j-1>=0&&(ans[p_i*m+p_j-1]==-1||ans[p_i*m+p_j-1]>ans[p_i*m+p_j]+table[p_i*m+p_j-1])){
                ans[p_i*m+p_j-1]=ans[p_i*m+p_j]+table[p_i*m+p_j-1];
                temp.i=p_i;
                temp.j=p_j-1;
                temp.v=ans[p_i*m+p_j-1];
                buffer.push(temp);
            }
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<ans[i*m+j]<<" ";
            }
            cout<<endl;
        }*/
        cout<<ans[(n-1)*m+m-1]<<endl;
    }
}
