#include <bits/stdc++.h>
using namespace std;

long long countDivisors(long long n) 
{ 
    long long cnt = 0; 
    for (long long i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            // If divisors are equal, 
            // count only one 
            if (n / i == i) 
                cnt++; 
  
            else // Otherwise count both 
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
  
  long long b;
  cin >> b;
  long long ans = countDivisors(b);
  cout<<ans<<endl;
  return 0;
  }