#include<iostream>
#include<map>
#include<cctype>
#include<cmath>
using namespace std;

map<string,double> Time_Zones;

void make_table()
{
    Time_Zones["UTC"]=0;
    Time_Zones["GMT"]=0;
    Time_Zones["BST"]=1;
    Time_Zones["IST"]=1;
    Time_Zones["WET"]=0;

    Time_Zones["WEST"]=1;
    Time_Zones["CET"]=1;
    Time_Zones["CEST"]=2;
    Time_Zones["EET"]=2;
    Time_Zones["EEST"]=3;

    Time_Zones["MSK"]=3;
    Time_Zones["MSD"]=4;
    Time_Zones["AST"]=-4;
    Time_Zones["ADT"]=-3;
    Time_Zones["NST"]=-3.5;

    Time_Zones["NDT"]=-2.5;
    Time_Zones["EST"]=-5;
    Time_Zones["EDT"]=-4;
    Time_Zones["CST"]=-6;
    Time_Zones["CDT"]=-5;

    Time_Zones["MST"]=-7;
    Time_Zones["MDT"]=-6;
    Time_Zones["PST"]=-8;
    Time_Zones["PDT"]=-7;
    Time_Zones["HST"]=-10;

    Time_Zones["AKST"]=-9;
    Time_Zones["AKDT"]=-8;
    Time_Zones["AEST"]=10;
    Time_Zones["AEDT"]=11;
    Time_Zones["ACST"]=9.5;
    Time_Zones["ACDT"]=10.5;
    Time_Zones["AWST"]=8;
}



int main()
{
    make_table();
    int T,hour,min,flag=0;
    double count;
    char temp;
    string zones="";
    cin>>T;
    cin.get(temp);
    while(T--)
    while(cin.get(temp))
    {
        if(isdigit(temp))
        {
            flag=1;
            hour=0;
            min=0;
            hour+=temp-'0';
            while(cin.get(temp))
            {
                if(temp==':')
                    break;
                else
                    hour=hour*10+temp-'0';
            }
            if (hour==12)hour=0;
            cin.get(temp);
            min+=temp-'0';
            cin.get(temp);
            min=min*10+temp-'0';
        }
        else if(flag==0&&(temp=='n'||temp=='m'))
        {
            flag=1;
            if(temp=='n')
                hour=12;
            else
                hour=0;
            min=0;
        }
        else if(temp=='a'||temp=='p')
        {
            flag=2;
            if(temp=='p')
                hour+=12;
        }
        else if(temp==' ')
        {
            if(flag==1||flag==2)
                flag=3;
            else if(flag==3)
            {
                flag=4;
                count=-Time_Zones[zones];
                zones="";
            }
        }
        else if(isupper(temp))
            zones+=temp;
        else if(temp=='\n')
        {
            count+=Time_Zones[zones];//cout<<hour<<" ";
            hour+=int(count);//cout<<hour<<":"<<min<<" "<<count<<endl;
            if(count-(int)count!=0)min+=30*count/abs(count);
            if(min<0)
            {
                min+=60;
                hour-=1;
            }
            if(min>=60)
            {
                min-=60;
                hour+=1;
            }
            if(hour<0)
                hour+=24;
            hour%=24;

            if(hour==0&&min==0)cout<<"midnight\n";
            else if(hour==12&&min==0)cout<<"noon\n";
            else
            {
                if(hour%12==0)cout<<12<<":";
                else
                    cout<<hour%12<<":";
                if(min<10)cout<<0;
                cout<<min;
                if(hour/12)cout<<" p.m.\n";
                else cout<<" a.m.\n";
            }
            flag=0;
            count=0;
            zones="";
            break;
        }
    }
}
