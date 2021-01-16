#include <bits/stdc++.h>
using namespace std;

vector<int> go(int x) {
    vector<int> ret;
    for (int i = 2; i * i <= x; i++) {
        if (x % i)continue;
        int cnt = 0;
        while (x % i == 0) {
            cnt ^= 1;
            x /= i;
        }
        if (cnt)ret.push_back(i);
    }
    if (x > 1) ret.push_back(x);
    // for(auto &x: ret)cout << x << " ";
    // cout << "\n";
    return ret;
}

const int N = 1000001;
int lp[N];
vector<int> pr;

void pre() {
    for (int i = 2; i < N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

int ar[N];

vector<int>factorize (int x) {
    vector<int>rt;
    while (x > 1) {
        int l = lp[x];
        int cnt = 0;
        while (x % l == 0) {
            x /= l;
            cnt ^= 1;
        }
        if (cnt) rt.push_back(l);
    }
    return rt;
}

int main() {
    /*
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    //*/

    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // your code goes here
    int t;
    cin >> t;
    pre();
    while (t--) {
        int n;
        cin >> n;
        map<vector<int>, int> zero, one;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            zero[factorize(x)]++;
        }

        int ansZero = 0;
        for (auto &x : zero)ansZero = max(ansZero, x.second);

        for (auto x : zero) {
            if (x.second & 1)one.insert(x);
            else {
                vector<int> mt;
                one[mt] += x.second;
            }
        }


        int ansOne = 0;
        for (auto x : one)ansOne = max(ansOne, x.second);

        int q;
        cin >> q;
        while (q--) {
            long long w = 0;
            cin >> w;
            if (w == 0)cout << ansZero << "\n";
            else {
                cout << ansOne << "\n";
            }
        }
    }
}