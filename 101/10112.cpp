#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int many,x[20],y[20],ans[3];
char temp;

bool Ipt()
{
    cin>>many;
    for(int i=0;i<many;i++)
    {
        cin>>temp>>x[i]>>y[i];
    }
    return many;
}

int tri_area(int i,int j,int k)
{
    return abs((y[k]-y[i])*(x[j]-x[i])-(y[j]-y[i])*(x[k]-x[i]));
}

void Opt()
{
    int maxsize=0;
    for(int i=0;i<many-2;i++)
        for(int j=i+1;j<many-1;j++)
            for(int k=j+1;k<many;k++)
    {
        int trisize=tri_area(i,j,k);
        bool has_inside=false;
        for(int l=0;l<many;l++)
        {
            if(l==i||l==j||l==k)
                continue;
            if(trisize==tri_area(i,j,l)+tri_area(i,l,k)+tri_area(l,j,k))
            {
                    has_inside=true;
                    break;
            }
        }
        if((!has_inside)&&maxsize<trisize)
        {
            maxsize=trisize;
            ans[0]=i;
            ans[1]=j;
            ans[2]=k;
        }
    }
    cout<<char('A'+ans[0])<<char('A'+ans[1])<<char('A'+ans[2])<<endl;
}

int main()
{
    while(Ipt())
        Opt();
    return 0;
}
