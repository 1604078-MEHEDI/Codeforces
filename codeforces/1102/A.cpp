#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long ans = (n*n+n) /2;
    if(ans&1)cout << "1\n";
    else cout << "0\n";
    return 0;
}
