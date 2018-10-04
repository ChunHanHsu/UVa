#include<iostream>
#include<cmath>
using namespace std;

double kind[12],fir[12],sec[12],thi[12],fou[12],fiv[12],six[12];
int many;
char temp;


void Inp()
{
    many=0;
    while(cin>>temp)
    {
        if(temp=='*')
            return ;
        many++;
        if(temp=='c')
        {
            kind[many]=0;
            cin>>fir[many]>>sec[many]>>thi[many];
        }
        if(temp=='t')
        {
            kind[many]=1;
            cin>>fir[many]>>sec[many]>>thi[many]>>fou[many]>>fiv[many]>>six[many];
        }
        if(temp=='r')
        {
            kind[many]=2;
            cin>>fir[many]>>sec[many]>>thi[many]>>fou[many];
        }
    }
}

bool checkTriangles(double x,double y, double x1,double y1,double x2,double y2,double x3,double y3)
{
    double t1=abs((x*y1+x1*y2+x2*y)-(x1*y+x2*y1+x*y2))/2;
    double t2=abs((x*y2+x2*y3+x3*y)-(x2*y+x3*y2+x*y3))/2;
    double t3=abs((x*y1+x1*y3+x3*y)-(x1*y+x3*y1+x*y3))/2;
    double ttotal=abs((x3*y1+x1*y2+x2*y3)-(x1*y3+x2*y1+x3*y2))/2;
    return t1>0.000001 &&t2>0.000001 &&t3>0.000001 &&abs(t1+t2+t3-ttotal)<0.000001 ;
}

void Opt()
{
    double x,y;
    bool check;
    int where,count=0;
    while(cin>>x>>y)
    {
        if(x==9999.9&&y==9999.9)
            return;
        count++;
        for(where=1,check=0; where<=many; where++)
        {
            if(kind[where]==0)
            {
                if(pow(x-fir[where],2)+pow(y-sec[where],2)<pow(thi[where],2))
                {
                    check=1;
                    cout<<"Point "<<count<<" is contained in figure "<<where<<endl;
                }
            }
            if(kind[where]==1)
            {
                if(checkTriangles( x, y,fir[where],sec[where],thi[where],fou[where],fiv[where],six[where]))
                {
                    check=1;
                    cout<<"Point "<<count<<" is contained in figure "<<where<<endl;
                }
            }
            if(kind[where]==2)
            {
                if(x>fir[where]&&x<thi[where]&&y<sec[where]&&y>fou[where])
                {
                    check=1;
                    cout<<"Point "<<count<<" is contained in figure "<<where<<endl;
                }
            }
        }
        if(check==0)
        {
            cout<<"Point "<<count<<" is not contained in any figure"<<endl;
        }
    }
}

int main()
{
    Inp();
    Opt();
    return 0;
}
