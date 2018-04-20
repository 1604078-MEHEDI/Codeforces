#include<bits/stdc++.h>
using namespace std;

void solve(long long int n)
{
    long long answer;
    if(n%3==0)answer = 2*n/3;
    else
        answer = 2*(n-n%3)/3 + 1;
    cout<<answer<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin>>n;
    solve(n);
    return 0;
}
