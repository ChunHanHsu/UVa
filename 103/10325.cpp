#include<iostream>
#include<vector>
using namespace std;
long long int N;
long long int M;//1~M
vector<long long int> array;

long long int gcd(long long int a,long long int b)// 程そ计
{
    return b ? gcd(b, a%b) : a;
}

long long int lcm(long long int a, long long int b)// 程そ计
{
    return a / gcd(a, b) * b;
}
int backtrack(long long int n,long long int divisor)
{
    long long int total = 0;
    total += M / divisor; // ヘ玡搓ㄓ栋

    for (long long int i=n; i<N; ++i)// 膥尿猅羭ぇ计癘眔跑腹
        total -= backtrack(i+1, lcm(divisor, array[i]));

    return total;
}

void inclusion_exclusion()
{
    //cin>>M>>N;
    array.clear();
    for(long long int i=0;i<N;i++)
    {
        long long int a;
	cin>>a;
	array.push_back(a);
    }
    cout<<backtrack(0,1)<<endl;
}

int main()
{
    while(cin>>M>>N)
        inclusion_exclusion();
}
