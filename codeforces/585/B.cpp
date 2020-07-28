#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int cs, n, k;

char line[3][150];

void go(ll r, ll c)
{
  if (line[r][c + 1] == '.')
  {
    if (line[r][c + 3] == '.')
      line[r][c + 3] = 's';
    if (r - 1 >= 0 && line[r - 1][c + 1] == '.' && line[r - 1][c + 3] == '.')
      line[r - 1][c + 3] = 's';

    if (r + 1 <= 2 && line[r + 1][c + 1] == '.' && line[r + 1][c + 3] == '.')
      line[r + 1][c + 3] = 's';
  }
}

void solve() {

  for (int j = 0; j < n + 10; j += 3) {
    for (int i = 0; i < 3; i++) {
      if (line[i][j] == 's') {
        if (j >= n) {
          cout << "YES\n";
          return;
        }
        go(i, j);
      }
    }
  }
  cout << "NO\n";
}

int main()
{
  ///*
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  //*/

  cin >> cs;
  while (cs--)
  {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 150; j++)
        line[i][j] = '.';
    cin >> n >> k;
    for (int i = 0; i < 3; i++)
      for (ll j = 0; j < n; j++)
        cin >> line[i][j];

    solve();
  }
  return 0;
}