#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main()
{
    //ofstream fout("out.txt");
    int T;
    cin>>T;
    while(T--)
    {
        int N,K,input,table[110]= {0};
        vector<int> temp_table_first,temp_table_second;
        cin>>N>>K;
        cin>>input;
        input%=K;
        if(input<0)input+=K;
        temp_table_first.push_back(input);
        table[input]=1;
        for(int i=1; i<N; i++)
        {
            cin>>input;
            input%=K;
            if(input<0)input+=K;
            while(!temp_table_first.empty())
            {
                int next_add=(temp_table_first.front()+input)%K,next_dec=(temp_table_first.front()-input)%K;
                if(next_dec<0)next_dec+=K;
                if(table[next_add]!=i+1)temp_table_second.push_back(next_add);
                table[next_add]=i+1;
                if(table[next_dec]!=i+1)temp_table_second.push_back(next_dec);
                table[next_dec]=i+1;
                temp_table_first.erase(temp_table_first.begin());
            }
            temp_table_first=temp_table_second;
            temp_table_second.clear();
        }
        if(table[0]==N) cout<<"Divisible"<<endl;
        else cout<<"Not divisible"<<endl;
    }
}
