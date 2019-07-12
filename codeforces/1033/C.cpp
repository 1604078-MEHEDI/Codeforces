#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 100005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

bool ans[maxn];

int main()
{
    FASTIO
    ///*
    //double start_time = clock();
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
//*/
    int T;
    //cin >> T;
    T = 1;
    for (int cs = 1; cs <= T; cs++) {
        int n;
        cin >> n;
        int a[n + 2], pos[n + 2];
        for (int i = 0; i < n; i++) {
            cin  >> a[i];
            pos[a[i]] = i;
        }

        for (int i = n; i > 0; i--) {
            int l = pos[i] % i;
            int t = pos[i];
            ans[t] = false;
            for (int j = l; j < n; j += i) {
                if (a[j] > i && !ans[j]) {
                    ans[t] = true;
                }
            }
        }
        for(int i = 0; i < n; i++) cout << (ans[i] ? 'A' : 'B');
    }

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
    return 0;
}