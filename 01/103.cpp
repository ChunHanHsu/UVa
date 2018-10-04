#include<iostream>
#include<vector>
using namespace std;

vector<int> put(vector<int> in[],int w)
{
    int a=0;
    vector<int> b,c;
    for(int i=0;i<in[w].size();i++)
    {
        b=put(in,in[w][i]);
        b.push_back(w);
        if(c.size()<b.size())c=b;
    }

    if(in[w].size()==0) c.push_back(w);
    return c ;
}

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        int box[a][b],si[a],mas=0,ans;
        vector<int> in[a],bts[a];
        for(int i=0;i<a;i++)
        {
            mas=0;
            for(int j=0;j<b;j++)
            {
                cin>>box[i][j];
            }
            for(int j=0;j<b;j++)
            {
                if(mas<box[i][j])
                {
                    mas=box[i][j];
                    ans=j;
                }
            }
            if(b!=1&&((ans!=0&&ans!=b-1&&box[i][ans+1]>box[i][ans-1])||(ans==0&&box[i][1]>box[i][b-1])||(ans==b-1&&box[i][0]>box[i][b-2])))
            {
                int t[b],tt=0;
                for(int j=0;j<b;j++)
                {
                    t[j]=box[i][j];
                    if(j+ans<b) box[i][j]=box[i][j+ans];
                    else { box[i][j]=t[tt]; tt++;}
                }
            }
            else if(b!=1)
            {
                int t[b],tt=b-1;
                for(int j=0;j<b;j++)
                {
                    t[j]=box[i][j];
                }
                for(int j=0;j<b;j++)
                {
                     box[i][j]=t[ans--];
                     if (ans<0)ans=b-1;
                }
            }
        }
        for(int i=0;i<a;i++)
        {
           for(int j=0;j<a;j++)
           {
               bool y=1;
               if(i==j)continue;
               for(int k=0;k<b;k++)
               {
                   if(box[i][k]<box[j][k]){y=0;break;}
               }
               if(y==1) in[i].push_back(j);
           }
           si[i]=in[i].size();
        }
        mas=0;
        for(int i=0;i<a;i++)
        {
            bts[i]=put(in,i);
            if(mas<bts[i].size())
            {
                mas=bts[i].size();
                ans=i;
            }
        }
        cout<<bts[ans].size()<<endl;
        for(int i=0;i<bts[ans].size();i++)
        {
            cout<<bts[ans][i]+1<<" ";

        }
        cout<<endl;
    }
}
