#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int prime[maxn];
vector<int> p, pFactor;

void seive()
{
  memset(prime, 0, sizeof(prime));
  prime[0] = prime[1] = 1;
  for (int i = 4; i < maxn; i += 2) prime[i] = 1;

  for (int i = 3; i * i < maxn; i += 2) {
    if (prime[i] == 0) {
      for (int j = i * i; j < maxn; j += i)
        prime[j] = 1;
    }
  }
  for (int i = 2; i < maxn; i++) {
    if (prime[i] == 0) p.push_back(i);
  }
}
void primeFactorization(int x)
{
  for (int i = 0; i < (int) p.size(); i++) {
    while (x % p[i] == 0) {
      x /= p[i];
      pFactor.push_back(p[i]);
    }
    if (x == 1) break;
  }
  if (x != 1) pFactor.push_back(x);
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  seive();
  int n;
  int t;
  cin >> t;
  while (t--) {
    pFactor.clear();
    cin >> n;
    primeFactorization(n);
    if ((int)pFactor.size() < 3) {
      cout << "NO\n";
    }
    else {
      // cout << "YES\n";
      //cout << pFactor[0] << " " << pFactor[1] << " ";
      set<long long> st;
      st.insert(pFactor[0]);
      long long ans = 1ll;
      //cerr << (int)pFactor.size() << endl;
      int i = 1;
      if (pFactor[1] == pFactor[0]) {
        st.insert(pFactor[1]*pFactor[2]);
        i = 3;
      }
      else {
        st.insert(pFactor[1]);
        i = 2;
      }

      for (; i < (int)pFactor.size(); i++) {
        ans *= pFactor[i];
      }
      if (ans > 1)
        st.insert(ans);
      if ((int)st.size() == 3) {
        cout << "YES\n";
        for (auto x : st) cout << x << " ";
        cout << endl;
      }
      else cout << "NO\n";
    }

  }
  return 0;
}
