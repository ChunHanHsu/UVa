#include<iostream>
using namespace std;

int L(int a,int b)
{
    return a>b;
}

int main()
{
    int a,e,f;
    while(cin>>a)
    {
         bool z=1,zz=1,zzz=1;
        int b[1100]={},c[1100]={},d[1100]={},bb=-1,cc=-1,dd=-1,ccc=0;
         while(a--)
         {
            cin>>e>>f;
            if(e==1)
            {
                bb++;
                cc++;
                dd++;
                b[bb]=f;
                c[cc]=f;
                d[dd]=f;
            }
           else
            {
                if(b[bb]!=f&&z==1)
                    z=0;
               bb--;
                if(c[ccc]!=f&&zz==1)
                    zz=0;
                ccc++;
                int ma=0,wh;
                for(int i=0;i<=dd;i++)
                {
                    if(d[i]>ma)
                    {
                        ma=d[i];
                        wh=i;
                    }
                }
                d[wh]=0;
                if(ma!=f&&zzz==1)
                    zzz=0;
            }
         }

        if(z==1)
        {
            if(zz==1||zzz==1) cout<<"not sure"<<endl;
            else cout<<"stack"<<endl;
        }
        else if(zz==1)
        {
            if(zzz==1) cout<<"not sure"<<endl;
            else cout<<"queue"<<endl;
        }
        else if(zzz==1) cout<<"priority queue"<<endl;
        else cout<<"impossible"<<endl;

    }
}
