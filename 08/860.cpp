#include<iostream>
#include<vector>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;

double total_word, Et, Erel;
vector<string> Text;

void Count_Et()
{
    Et=0;
    int sameword=1;
    for(int i=1;i<total_word;i++)
    {
        if(Text[i]==Text[i-1])
        {
            sameword++;
            continue;
        }
        Et+=sameword*(log10(total_word)-log10(sameword));
        sameword=1;
    }
    Et+=sameword*(log10(total_word)-log10(sameword));
    Et/=total_word;
   /* int temp=(Et+0.05)*10;
    Et=temp/10.0;*/
}
void Count_Erel()
{
    Erel=Et/log10(total_word)*100;
}
int main()
{
    char temp;
    string str="";
    total_word=0;
    while(cin.get(temp))
    {
        if(temp==','||temp=='.'||temp==':'||temp==';'||temp=='!'||temp=='?'||temp=='"'||temp=='('||temp==')'||temp=='\0'||temp=='\n')
            temp=' ';
        if(temp!=' ')
        {
            if(islower(temp))
                temp=temp-'a'+'A';
            str+=temp;
        }
        else
        {
            if(str=="")
                continue;
            if(str=="****END_OF_TEXT****")
            {
                sort(Text.begin(),Text.end());
                Count_Et();
                Count_Erel();
                cout<<total_word<<" "<<std::fixed<<setprecision(1)<<Et<<" "<<setprecision(0)<<Erel<<endl;
                Text.erase(Text.begin(),Text.end());
                total_word=0;
                str="";
            }
            else if(str=="****END_OF_INPUT****")
                return 0;
            else
            {
                Text.push_back(str);
                str="";
                total_word++;
            }
        }
    }
}
