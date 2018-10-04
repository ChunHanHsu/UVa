#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;

int a,b,c,d,e,f;
double cal(double x)
{
    double temp=a*exp(-x)+b*sin(x)+c*cos(x)+d*tan(x)+e*pow(x,2)+f;
    return temp;
}

int main()
{//ofstream  out("text.txt");
    while(cin>>a>>b>>c>>d>>e>>f)
    {
        double up=1,low=0;
        if(cal(up)*cal(low)>0)
        {
            cout<<"No solution\n";
        }
        else
        {
            while(abs(cal(up)-cal(low))>=0.000000001)
            {
                if(cal(up)*cal((up+low)/2)>0)
                    up=(up+low)/2.0;
                else
                    low=(up+low)/2.0;
            }
            if(cal(up)<=0.000000001)
                cout<<fixed<<setprecision(4)<<up<<endl;
            else
                cout<<fixed<<setprecision(4)<<low<<endl;
        }
    }
}
