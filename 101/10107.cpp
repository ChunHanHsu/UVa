#include<iostream>

using namespace std;

int main()
{
    int a,line[10001]={},i=1,temp;
    while(cin>>a)
    {
        for(int j=0;j<i;j++)
        {
            if(line[j]<a)
            {
                temp=line[j];
                line[j]=a;
                a=temp;
            }
        }
        if((i-1)%2==0)
            cout<<line[(i-1)/2]<<endl;
        else
            cout<<(line[(i-1)/2]+line[(i-1)/2+1])/2<<endl;
        i++;
    }
}
