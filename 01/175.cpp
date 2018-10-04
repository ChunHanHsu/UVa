#include<iostream>
#include<vector>
#include<cctype>
#include<fstream>
using namespace std;

vector<vector<string> >P,T;
vector<int> Pn;

void IPT()
{
    int tempi;
    char tempc;
    string temps;
    while(cin.get(tempc))
    {
        if(tempc=='#')
             break;
        else if(tempc=='P')
        {
            vector<string> tempvs;
            temps="";
            cin>>tempc>>tempi;
            Pn.push_back(tempi);
            while(cin.get(tempc))
            {
                if(tempc==' '&&temps!="")
                {
                    tempvs.push_back(temps);
                    temps="";
                }
                else if(tempc=='\n'&&temps!="")
                {
                    tempvs.push_back(temps);
                    temps="";
                    break;
                }
                else if(isalpha(tempc))
                {
                    if(isupper(tempc))
                        tempc=tempc-'A'+'a';
                    temps+=tempc;
                }
            }
            P.push_back(tempvs);
        }
        else if(tempc=='T')
        {
            vector<string> tempvs;
            temps="";
            while(cin.get(tempc))
            {
                if(tempc=='|')
                {
                    if(temps!="")
                    {
                        tempvs.push_back(temps);
                        temps="";
                    }
                    break;
                }
                else if((tempc==' '||tempc=='\n')&&temps!="")
                {
                    tempvs.push_back(temps);
                    temps="";
                }
                else if(isalpha(tempc))
                {
                    if(isupper(tempc))
                        tempc=tempc-'A'+'a';
                    temps+=tempc;
                }
            }
            T.push_back(tempvs);
        }
    }
}

int main()
{
    //ofstream fout("text.txt");
    //ostream& out(fout);

    IPT();
    for(int i=0;i<Pn.size();i++)
    {
        cout<<i+1<<": ";
        bool first=false;
        for(int j=0;j<T.size();j++)
        {
            int count=0;
            int flag=-1;
            for(int k=0;k<T[j].size();k++)
            {
                bool used=false,secend_used=false;
                count++;
                for(int l=0;l<P[i].size();l++)
                {
                    if(P[i][l]==T[j][k])
                    {
                        if(flag==l)
                        {
                            secend_used=true;
                            continue;
                        }
                        if(flag!=-1&&count<=Pn[i]+1)
                        {
                            if(first)
                                cout<<",";
                            cout<<j+1;
                            first=true;
                            used=true;
                        }
                        flag=l;
                        count=0;
                        break;
                    }
                    if(used)
                        break;
                }
                if(secend_used)
                        count=0;
                 if(used)
                        break;

            }
        }
        cout<<endl;
    }

}
