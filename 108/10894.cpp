#include<iostream>
#include<string>

using namespace std;

string S[5][11]=
{
    {"*****",".***.","*...*","*****",".","*...*","*****","*****","***..","*****","*...*"},
    {"*....","*...*","*...*","*....",".","*...*","*...*","..*..","*..*.","*...*",".*.*."},
    {"*****","*****","*...*","***..",".","*****","*****","..*..","*...*","*...*","..*.."},
    {"....*","*...*",".*.*.","*....",".","*...*","*.*..","..*..","*..*.","*...*","..*.."},
    {"*****","*...*","..*..","*****",".","*...*","*..**","*****","***..","*****","..*.."}
};

int main()
{
    int a;
    while(cin>>a&&a!=0)
    {
        if(a<0)
        {
            a*=-1;
            for(int i=0; i<11; i++)
            {
                if(i!=4)
                {
                    for(int j=0; j<5; j++)
                        for(int l=0; l<a; l++)
                        {
                            for(int m=0; m<S[j][i].size(); m++)
                                for(int k=0; k<a; k++)
                                    cout<<S[j][i][m];
                            cout<<endl;
                        }
                }
                else
                {
                    for(int k=0;k<a;k++)
                    {
                        for(int j=0; j<a*5; j++)
                            cout<<".";
                        cout<<endl;
                    }
                }
                if(i!=10)
                {
                    for(int k=0;k<a;k++)
                    {
                        for(int j=0; j<a*5; j++)
                            cout<<".";
                        cout<<endl;
                    }
                }
            }
        }
        else
        {
            for(int i=0; i<5; i++)
                for(int k=0; k<a; k++)
                {
                    for(int j=0; j<11; j++)
                    {
                        for(int m=0; m<S[i][j].size(); m++)
                            for(int l=0; l<a; l++)
                                cout<<S[i][j][m];
                        if(j!=10)
                        {
                            for(int l=0;l<a;l++)
                                cout<<".";
                        }

                    }
                    cout<<endl;
                }
        }
        cout<<endl<<endl;
    }
}
