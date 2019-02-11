#include <bits/stdc++.h>
using namespace std;
//#define MAXN   1000001
//long long spf[MAXN];
//map<long long, long long>mp;
 vector<long long> ret;
void primeFactors(long long n)
{
    long long mx = 0;
    // Prlong long the number of 2s that divide n
    while (n%2 == 0)
    {
        //prlong longf("%d ", 2);
        ret.push_back(2);
        n = n/2;
        mx = max(2LL,mx);
    }

    // n must be odd at this polong long.  So we can skip
    // one element (Note i = i +2)
    for (long long i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, prlong long i and divide n
        while (n%i == 0)
        {
           // prlong longf("%d ", i);
           ret.push_back(i);
           mx = max(i,mx);
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
   if (n > 2) {
    ret.push_back(n);
    mx = max(mx,n);
   }
//   return mx;
        //prlong longf ("%d ", n);
}

long long solve(long long N, long long H, long long cnt)
{
    long long ans = 0;
  while(N > 0){
    ans += N/H;
    N = N/H;
    //H = H*H;
  }
  return ans/cnt;
}
int main()
{
    long long N,B;
    cin >> N >> B;
  primeFactors(B);
  //cout << H << endl;
  map<long long,long long>mp;
  set<long long>st;
  for(long long  i = 0; i < ret.size(); i++){
  //  if(H == ret[i])pw++;
  mp[ret[i]]++;
  st.insert(ret[i]);
  }
  long long mx = 5e18+5;
  for(auto x: st){
    long long k = solve(N,x,mp[x]);
    mx = min(mx, k);
  }
  cout << mx << endl;
  return 0;
}
