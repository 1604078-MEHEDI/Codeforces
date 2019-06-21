#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 200005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

pair<int,int> a[maxn];
int t[maxn];
int n;

bool solve(int x)
{
    for(int i = 0, j = 0; i < n; i++)
    {
        if(i == x) continue;
        t[j++] = a[i].first;
    }

    int d = t[1] - t[0];
    for(int i = 1; i < n - 1; i++)
    {
        if(t[i] - t[i - 1] != d) return false;
    }
    return true;
}
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

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a+n);
    if(n <= 3) cout << "1\n";
    else if(solve(0))
    {
        cout << a[0].second + 1<<endl;
    }
    else if(solve(1))
    {
        cout << a[1].second+1<<endl;
    }
    else if(solve(2))
    {
        cout << a[2].second + 1 << endl;
    }
    else
    {
        int d = a[1].first - a[0].first;
        for(int i = 1; i < n; i++)
        {
            if(a[i].first - a[i - 1].first != d)
            {
                if(solve(i))
                {
                    cout << a[i].second + 1 << endl;
                    return 0;
                }
                else
                {
                    cout << "-1\n";
                    return 0;
                }
            }

        }
        cout << 1 << endl;
    }

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}