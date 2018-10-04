#include<iostream>
#include<string>

using namespace std;

string N[5][10]=
{
    {" - ","   "," - "," - ","   "," - "," - "," - "," - "," - "},//0
    {"| |","  |","  |","  |","| |","|  ","|  ","  |","| |","| |"},//1
    {"   ","   "," - "," - "," - "," - "," - ","   "," - "," - "},//2
    {"| |","  |","|  ","  |","  |","  |","| |","  |","| |","  |"},//3
    {" - ","   "," - "," - ","   "," - "," - ","   "," - "," - "}//4
};

int main()
{
    int a;
    string b;
    while(cin>>a>>b&&a!=0)
    {
        for(int i=0; i<5; i++)
        {
            if(i%2==0)
            {
                for(int j=0; j<b.size(); j++)
                {
                    cout<<" ";
                    for(int k=0; k<a; k++)
                        cout<<N[i][b[j]-'0'][1];
                    cout<<" ";
                    if(j!=b.size()-1)
                        cout<<" ";
                }
                cout<<endl;
            }
            else
            {
                for(int k=0; k<a; k++)
                {
                    for(int j=0; j<b.size(); j++)
                    {
                        cout<<N[i][b[j]-'0'][0];
                        for(int l=0; l<a; l++)
                            cout<<" ";
                        cout<<N[i][b[j]-'0'][2];
                        if(j!=b.size()-1)
                        cout<<" ";
                        if(j==b.size()-1)
                            cout<<endl;
                    }
                }
            }
        }
        cout<<endl;
    }
}

