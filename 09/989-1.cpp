#include<iostream>
#include<vector>
using namespace std;

int n;
int board[10][10];
bool mx[10][10],my[10][10],mz[10][10];//可更動的判斷表
bool x[10][10],y[10][10],z[10][10]; //不可更動的判斷表
int ans[10][10];
bool has_ans;
vector<int> xy;

void clean()        //歸零
{
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
        {
            mx[i][j]=false;
            my[i][j]=false;
            mz[i][j]=false;
            x[i][j]=false;
            y[i][j]=false;
            z[i][j]=false;
        }
    xy.clear();
    has_ans=false;
}

void make_board()   //建表
{
    for(int i=0; i<n*n; i++)
        for(int j=0; j<n*n; j++)
        {
            cin>>board[i][j];
            if(board[i][j]!=0)
            {
                int k=i-i%n+j/n;
                x[board[i][j]][j]=true;
                y[board[i][j]][i]=true;
                z[board[i][j]][k]=true;
            }
            else
            {
                xy.push_back(i);
                xy.push_back(j);
            }
        }
}

void backtrack(int i)
{
    if(i>=xy.size())
    {
        has_ans=true;
        for(int j=0; j<n*n; j++)
        {
            for(int k=0; k<n*n; k++)
            {
                cout<<board[j][k];
                if(k!=n*n-1)
                    cout<<" ";
            }
            cout<<endl;
        }
        return ;
    }
    for(int k=1; k<=n*n; k++)
    {
        int l=xy[i]-xy[i]%n+xy[i+1]/n;
        if(x[k][xy[i+1]]==false&&y[k][xy[i]]==false&&z[k][l]==false&&mx[k][xy[i+1]]==false&&my[k][xy[i]]==false&&mz[k][l]==false)
        {
            board[xy[i]][xy[i+1]]=k;
            mx[k][xy[i+1]]=true;
            my[k][xy[i]]=true;
            mz[k][l]=true;
            backtrack(i+2);
            if(has_ans==true)
                return;
            mx[k][xy[i+1]]=false;
            my[k][xy[i]]=false;
            mz[k][l]=false;
        }
    }
}

int main()
{
    int T=0;
    while(cin>>n)
    {
        if(T!=0)
            cout<<endl;
        T++;
        clean();
        make_board();
        backtrack(0);
        if(has_ans==false)
            cout<<"NO SOLUTION\n";
    }
}

