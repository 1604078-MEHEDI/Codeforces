/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
using pii = pair<int, int>;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;

const int N = 5005;

vector<int> g[N], Cost[N];
int n, tt;
int par[N][N];
int d[N][N];
struct data
{
    int city, cnt , dist;
    bool operator < (const data &p)const {
        return dist < p.dist;
    }
};
void dijkstra() {
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)d[i][j] = mod;

    d[1][1] = 0;
    queue<data> Q;
    data u, v;
    u.city = 1;
    u.cnt = 1;
    u.dist = 0;
    Q.push(u);
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        int ucost = d[u.city][u.cnt];
        for (int i = 0; i < (int)g[u.city].size(); i++) {
            v.city = g[u.city][i];
            v.cnt = u.cnt + 1;
            v.dist = ucost + Cost[u.city][i];
            if (v.dist > tt)continue;
            if (v.dist < d[v.city][v.cnt]) {
                d[v.city][v.cnt] = v.dist;
                par[v.city][v.cnt] = u.city;
                Q.push(v);
            }
        }
    }
}

int main()
{
    FASTIO
    ///*
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
//*/
    int T;
    T = 1;
    //scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++) {
        int m;
        cin >> n >> m >> tt;
        for (int i = 1;  i <= m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back(b);
            Cost[a].push_back(c);
        }
        dijkstra();
        int i;
        for (i = n; i; i--)if (d[n][i] != mod)break;
        int j = n;
        vector<int> ans;
        ans.push_back(n);
        // dbg(i);
        while (j != 1) {
            // dbg(j, i);
            j = par[j][i];
            ans.push_back(j);
            i--;
        }
        cout << (int)ans.size() << "\n";
        reverse(ans.begin(), ans.end());
        for (auto &x : ans) {
            cout << x  << " ";
        }
        cout << "\n";
    }
    return 0;
}