#include<iostream>
#include<vector>
using namespace std;

int board[10][10];
bool mx[10][10],my[10][10],mB[10][10];//可更動的判斷表
bool x[10][10],y[10][10],B[10][10]; //不可更動的判斷表
int n;
int many;
vector<int> lestxy;
void backtrack(int i,int j)
{
    if(many==0)
        return ;
    for(int i=0;i<n*n;i++)
    {
        for(int j=0;j<n*n;j++)
        {
            for(int k=1;k<=n*n;k++)
            {
                int l=i-i%3+j/3;
                if(board[i][j]==0&&x[k][j]==false&&y[k][i]==false&&B[k][l]==false&&mx[k][j]==false&&my[k][i]==false&&mB[k][l]==false)
                { cout<<i<<" "<<j<<" "<<k<<" "<<many<<endl;
                    board[i][j]=k;
                    mx[k][j]=true;
                    my[k][i]=true;
                    mB[k][l]=true;
                    many--;
                    backtrack(i,j);
                    board[i][j]=0;
                    mx[k][j]=false;
                    my[k][i]=false;
                    mB[k][l]=false;
                    many++;
                }

            }
        }
    }
}

int main()
{
    while(cin>>n)
    {
        many=0;
        lestxy.clear();
        for(int i=0; i<10; i++)     //歸零
            for(int j=0; j<10; j++)
            {
                board[i][j]=0;
                mx[i][j]=false;
                my[i][j]=false;
                mB[i][j]=false;
                x[i][j]=false;
                y[i][j]=false;
                B[i][j]=false;
            }

        for(int i=0; i<n*n; i++)    //建表存
            for(int j=0; j<n*n; j++)
            {
                cin>>board[i][j];
                if(board[i][j]!=0)
                {
                    int k=i-i%3+j/3;
                    x[board[i][j]][j]=true;
                    y[board[i][j]][i]=true;
                    B[board[i][j]][k]=true;

                }
                else
                    many++;
            }

        backtrack(0,0);

        for(int i=0; i<n*n; i++)
        {
            for(int j=0; j<n*n; j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
