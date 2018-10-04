#include<iostream>

using namespace std;

int main()
{
    int bag[3][3];
    while(cin>>bag[0][0]>>bag[0][1]>>bag[0][2])
    {
        int sum[6],ch=999999999,an=0,to=bag[0][0]+bag[0][1]+bag[0][2];
        string ans[6];
         for(int i=1;i<3;i++)
        for(int j=0;j<3;j++)
        {
            cin>>bag[i][j];
            to+=bag[i][j];
        }
        sum[0]=to-(bag[0][0]+bag[1][2]+bag[2][1]);
        sum[1]=to-(bag[0][0]+bag[1][1]+bag[2][2]);
        sum[2]=to-(bag[0][2]+bag[1][0]+bag[2][1]);
        sum[3]=to-(bag[0][2]+bag[1][1]+bag[2][0]);
        sum[4]=to-(bag[0][1]+bag[1][0]+bag[2][2]);
        sum[5]=to-(bag[0][1]+bag[1][2]+bag[2][0]);
        ans[0]="BCG";
        ans[1]="BGC";
        ans[2]="CBG";
        ans[3]="CGB";
        ans[4]="GBC";
        ans[5]="GCB";

        for(int i=0;i<6;i++)
        {
            if(ch>sum[i])
            {
                ch=sum[i];
                an=i;
            }
        }
        cout<<ans[an]<<" "<<ch<<endl;
    }
    return 0;
}
