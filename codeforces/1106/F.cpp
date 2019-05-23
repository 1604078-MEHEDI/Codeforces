#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 103, M = 998244353;

struct matrix
{
    LL a[N][N];
    matrix()
    {
        memset(a, 0, sizeof(a));
    }
};

matrix operator* (matrix a, matrix b)
{
    matrix ans;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                ans.a[i][j] = (ans.a[i][j] + a.a[i][k] * b.a[k][j]) % (M-1);
    return ans;
}

matrix power(matrix base, int k)
{
    if(k == 1) return base;
    matrix ans = power(base, k/2);
    ans = ans * ans;
    if(k & 1) ans = ans * base;
    return ans;
}

int gcd (int a, int b)
{
    return a ? gcd (b%a, a) : b;
}


LL powMod(LL a, LL b, LL p)
{
    LL res = 1;
    while(b)
    {
        if(b & 1)
            res = (LL) (res * 1LL * a % p), --b;
        else
            a = (LL) (a * 1LL * a % p), b >>= 1;
    }
    return res;
}

LL generator (LL p)
{
    vector<LL> fact;
    LL phi = p - 1, n = phi;
    for(LL i = 2; i*i <= n; i++)
        if(n % i == 0)
        {
            fact.push_back(i);
            while(n % i == 0)
                n /= i;
        }
    if(n > 1)
        fact.push_back(n);

    for(LL res = 2; res <= p; res++)
    {
        bool ok = true;
        for(size_t i = 0; i < fact.size() && ok; i++)
            ok &= powMod(res, phi/fact[i], p) != 1;
        if(ok) return res;
    }
    return -1;
}

/// a^x = b (mod m)
LL discrete_log (LL a, LL b, LL m)
{
    LL n = (LL) sqrt(m + .0) + 1;
    map<LL,LL> Hash;
    for(LL i = n; i >= 1; i--)
        Hash[powMod(a, i*n, m)] = i;

    for(LL i = 0; i <= n; i++)
    {
        LL cur = (powMod(a, i, m) * b) % m;
        if(Hash.count(cur))
        {
            LL ans = Hash[cur] * n - i;
            if(ans < m)
                return ans;
        }
    }
    return -1;
}

/// x^a = b (mod p) p is prime
LL discrete_root (LL a, LL b, LL p)
{
    LL g = generator(p);
    assert(g != -1);
    LL k = discrete_log(powMod(g, a, p), b, p);
    if(k == -1) return -1;
    return powMod(g, k, p);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    matrix ank;
    for(int i = 0; i < n; i++) cin >> ank.a[0][i];
    for(int j = 1; j < n; j++) ank.a[j][j - 1] = 1;
    int k,x;
    cin >> k >> x;
    matrix ans = power(ank, k - n);
    LL pw = ans.a[0][0];
    cout << discrete_root(pw, x, M)<<endl;
    return 0;
}
