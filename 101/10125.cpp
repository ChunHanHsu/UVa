#include<iostream>
#include<vector>
#include<algorithm>
//#include<fstream>
#include <utility>
using namespace std;

bool check(pair<int,int>L,pair<int,int>R)
{
    return L.first+L.second<R.first+R.second;
}

int main()
{
    //ifstream fin("input.txt");
    //ofstream fou("oup.txt");
    istream &inp(cin);
    ostream &out(cout);
    int N,temp;
    while(inp>>N)
    {
        if(N==0)break;
        else
        {
            vector<int> in;
            vector<pair<int,int> >L;
            for(int i=0; i<N; i++)
            {
                inp>>temp;
                in.push_back(temp);
            }
            sort(in.begin(),in.end());
            for(int i=0; i<N-1; i++)
                for(int j=i+1; j<N; j++)
                    L.push_back(make_pair(in[i],in[j]));
            sort(L.begin(),L.end(),check);

            bool is_find=false;
              for(int i=N-1;i>=0&&!is_find;i--)
                  for(int j=0;j<N&&!is_find;j++)
                  {
                      temp=in[i]-in[j];
                      int l=0,r=L.size();
                      while(l!=r-1&&!is_find)
                      {
                          if(temp==L[(l+r)/2].first+L[(l+r)/2].second&&(L[(l+r)/2].first!=in[i]&&L[(l+r)/2].first!=in[j]&&L[(l+r)/2].second!=in[i]&&L[(l+r)/2].second!=in[j]))
                          {
                              out<<in[i]<<endl;
                              is_find=true;
                          }
                          else if(temp>L[(l+r)/2].first+L[(l+r)/2].second)
                              l=(l+r)/2;
                          else
                              r=(l+r)/2;
                      }
                  }
              if(!is_find)
                  out<<"no solution\n";
        }
    }
}
