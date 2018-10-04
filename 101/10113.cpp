
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<fstream>
using namespace std;

int table[100][100][2]= {};
int counter=1;
int GCD(int a,int b)
{
    int t;
    while(a % b != 0)
    {
        t = a % b;
        a = b;
        b = t;
    }
    return b;
}

struct _pair
{
    int item;
    int cost1,cost2;
};

bool find_equ(int a, int b)
{
    queue<_pair> bfs_queue;
    bool used[100]= {};
    _pair temp;
    temp.cost1=1;
    temp.cost2=1;
    temp.item=a;
    bfs_queue.push(temp);
    while(!bfs_queue.empty())
    {
        if(used[bfs_queue.front().item])
        {
            bfs_queue.pop();
            continue;
        }
        int item=bfs_queue.front().item,cost1=bfs_queue.front().cost1,cost2=bfs_queue.front().cost2;
        used[item]=true;
        bfs_queue.pop();
        for(int i=1; i<counter; i++)
        {
            if(table[item][i][0]!=0&&!used[i])
            {
                temp.cost1=cost1*table[item][i][0];
                temp.cost2=cost2*table[item][i][1];
                int the_gcd=GCD(temp.cost1,temp.cost2);
                temp.cost1/=the_gcd;
                temp.cost2/=the_gcd;
                temp.item=i;
                table[a][i][0]=temp.cost1;
                table[a][i][1]=temp.cost2;
                table[i][a][0]=temp.cost2;
                table[i][a][1]=temp.cost1;
                bfs_queue.push(temp);
            }
            if(table[a][b][0]!=0) return true;
        }
    }
    return false;
}

int main()
{
    map<string,int> name2int;

    //ofstream fout("data.out");
    ostream& outs(cout);

    char first_char;
    while(cin>>first_char)
    {
        if(first_char=='.') return 0;
        if(first_char=='!')
        {
            string str,item1="",item2="";
            int str_int1=0,str_int2=0,the_gcd;
            bool equ=false;
            getline(cin,str);
            for(int i=0; i<str.length(); i++)
            {
                if(str[i]>='0'&&str[i]<='9')
                {
                    if(!equ)str_int1=str_int1*10+str[i]-'0';
                    else str_int2=str_int2*10+str[i]-'0';
                }
                else if(str[i]>='a'&&str[i]<='z')
                {
                    if(!equ)item1+=str[i];
                    else item2+=str[i];
                }
                else if(str[i]=='=')equ=true;
            }
            if(str_int1==0)str_int1=1;
            if(str_int2==0)str_int2=1;
            the_gcd=GCD(str_int1,str_int2);
            str_int1/=the_gcd;
            str_int2/=the_gcd;
            if(name2int[item1]==0)
            {
                name2int[item1]=counter;
                counter++;
            }
            if(name2int[item2]==0)
            {
                name2int[item2]=counter;
                counter++;
            }
            table[name2int[item1]][name2int[item2]][0]=str_int1;
            table[name2int[item1]][name2int[item2]][1]=str_int2;
            table[name2int[item2]][name2int[item1]][0]=str_int2;
            table[name2int[item2]][name2int[item1]][1]=str_int1;
        }
        else if(first_char=='?')
        {
            string str,item1="",item2="";
            bool equ=false;
            getline(cin,str);
            for(int i=0; i<str.length(); i++)
            {
                if(str[i]>='a'&&str[i]<='z')
                {
                    if(!equ)item1+=str[i];
                    else item2+=str[i];
                }
                else if(str[i]=='=')equ=true;
            }
            if(name2int[item1]==0||name2int[item2]==0)
            {
                outs<<"? "<<item1<<" = ? "<<item2<<endl;
                break;
            }

            if(!find_equ(name2int[item1],name2int[item2])) outs<<"? "<<item1<<" = ? "<<item2<<endl;
            else {
                    outs<<table[name2int[item1]][name2int[item2]][0]<<" "<<item1<<" = "<<table[name2int[item1]][name2int[item2]][1]<<" "<<item2<<endl;
            }
        }
    }
}
