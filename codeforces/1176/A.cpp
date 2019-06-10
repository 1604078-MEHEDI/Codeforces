#include<bits/stdc++.h>
using namespace std;

int solve(long long n, int cnt)
{
    if(n == 1) return cnt;
    if(n%2 == 0)  solve(n/2, cnt+1);
    else if(n% 3 == 0)  solve(2*n/3, cnt+1);
    else if(n % 5 == 0) solve(4*n/5, cnt+1);
    else return -1;
}

int main()
{
    int q;
    cin >> q;
    while(q--){
        long long n;
        cin >> n;
        cout << solve(n, 0)<<endl;
    }
    return 0;
}
