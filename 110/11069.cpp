#include<iostream>

using namespace std;

int board[77];
int n;

void dynamic_programming()
{
    board[0]=1;
    board[1]=1;
    board[2]=2;
    for(int i=3;i<77;i++)
        board[i]=board[i-3]+board[i-2];
}

int main()
{
    dynamic_programming();
    while(cin>>n)
    {
        cout<<board[n]<<endl;
    }

}
