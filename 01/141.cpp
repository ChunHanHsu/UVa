#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main()
{
    int N;
    while(cin>>N&&N!=0)
    {
        map<int,vector<int> > play,play1,play2,play3;
        vector<map<int,vector<int> > > T;
        map<int,vector<int> > :: iterator it1 ,it2;
        int a,b,ans=0,where;
        char c;
        for(int i=0;i<2*N;i++)
        {
            cin>>a>>b>>c;
            if(ans==0)
            {
                if(c=='+')
                {
                    play[a].push_back(b);
                    play1[N-a+1].push_back(N-b+1);
                    play2[b].push_back(N-a+1);
                    play3[N-b+1].push_back(a);
                }
                if(c=='-')
                {
                    for(int j=0;j<play[a].size();j++)
                        if(play[a][j]==b)
                        {
                            play[a].erase(play[a].begin()+j);
                            if(play[a].empty())
                            {
                                int z=0;
                                for(it1=play.begin();it1!=play.end();it1++)
                                    if(it1->first==a)
                                        break;
                                play.erase(it1);
                            }
                            break;
                        }
                    for(int j=0;j<play1[N-a+1].size();j++)
                        if(play1[N-a+1][j]==(N-b+1))
                        {
                            play1[N-a+1].erase(play1[N-a+1].begin()+j);
                            if(play1[N-a+1].empty())
                            {
                                int z=0;
                                for(it1=play1.begin();it1!=play1.end();it1++)
                                    if(it1->first==(N-a+1))
                                        break;
                                play1.erase(it1);
                            }
                            break;
                        }
                    for(int j=0;j<play2[b].size();j++)
                        if(play2[b][j]==(N-a+1))
                        {
                            play2[b].erase(play2[b].begin()+j);
                            if(play2[b].empty())
                            {
                                int z=0;
                                for(it1=play2.begin();it1!=play2.end();it1++)
                                    if(it1->first==b)
                                        break;
                                play2.erase(it1);
                            }
                            break;
                        }
                    for(int j=0;j<play3[N-b+1].size();j++)
                        if(play3[N-b+1][j]==a)
                        {
                            play3[N-b+1].erase(play3[N-b+1].begin()+j);
                            {
                                if(play3[N-b+1].empty())
                            {
                                for(it1=play3.begin();it1!=play3.end();it1++)

                                    if(it1->first==(N-b+1))
                                        break;
                                play3.erase(it1);
                            }
                            }
                            break;
                        }
                }


                for(int j=0;j<T.size();j++)
                {
                    if(T[j]==play)
                    {
                        ans=i%2;
                        if(ans==0)
                            ans=2;
                        where=i+1;
                    }
                }

                T.push_back(play);
                T.push_back(play1);
                T.push_back(play2);
                T.push_back(play3);
            }
        }
        if(ans==0)
            cout<<"Draw"<<endl;
        else
            cout<<"Player "<<ans<<" wins on move "<<where<<endl;
    }
}
