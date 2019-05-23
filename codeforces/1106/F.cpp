#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 103, M = 998244353;
const int mod = M - 1;
struct matrix
{
    int row, col;
    int a[N][N];

    matrix()
    {
        memset(a, 0, sizeof a);
    }
    matrix(int r, int c) : row(r), col(c)
    {
        memset(a, 0, sizeof a);
    }

    // multiplied by p
    matrix operator * (const matrix &p)
    {
        assert(col == p.row);

        matrix ret(row, p.col);
        LL mod2 = (LL) mod * mod;
        for(int i=0; i<ret.row; ++i)
        {
            for(int j=0; j<ret.col; ++j)
            {
                long long sum = 0;
                for(int k=0; k<col; ++k)
                {
                    sum += (1LL * a[i][k] * p.a[k][j]);
                    if(sum >= mod2) sum -= mod2;
                }
                ret.a[i][j] = sum % mod;
            }
        }

        return ret;
    }

    // pwr p :|
    matrix power (int p)
    {
        assert(row == col);

        matrix base = *this;
        matrix ret(row, col);
        for(int i=0; i<row; ++i) ret.a[i][i] = 1;

        while(p > 0)
        {
            if(p & 1) ret = ret * base;
            base = base * base;
            p >>= 1;
        }

        return ret;
    }
};

inline int gcd (int a, int b)
{
    return a ? gcd (b%a, a) : b;
}


/// a^b modulo p
int powMod(int a, int b, int p)
{
    int res = 1;
    while(b)
    {
        if(b & 1)
            res =  (res * 1LL * a % p), --b;
        else
            a =  (a * 1LL * a % p), b >>= 1;
    }
    return res;
}

// Finds the primitive root modulo p
int primitive_root(int p)
{
    vector<int> fact;
    int phi = p-1, n = phi;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            fact.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        fact.push_back(n);

    for (int res = 2; res <= p; ++res)
    {
        bool ok = true;
        for (int factor : fact)
        {
            if (powMod(res, phi / factor, p) == 1)
            {
                ok = false;
                break;
            }
        }
        if (ok) return res;
    }
    return -1;
}


/// a^x = b (mod m)
int discrete_log (int a, int b, int m)
{
    LL n = (int) sqrt(m + .0) + 1;
    map<int,int> Hash;
    for(int i = n; i >= 1; i--)
        Hash[powMod(a, i*n, m)] = i;

    for(int i = 0; i <= n; i++)
    {
        int cur = (powMod(a, i, m) * b) % m;
        if(Hash.count(cur))
        {
             int ans = Hash[cur] * n - i;
            if(ans < m)
                return ans;
        }
    }
    return -1;
}

/// This program finds all numbers x such that x^k = a (mod n)
vector<int> discrete_root(int n, int k, int a)
{
    if (a == 0) return vector<int>(1, 0);

    int g = primitive_root(n);

    /// Baby-step giant-step discrete logarithm algorithm
    int sq = (int) sqrt (n + .0) + 1;
    vector < pair<int,int> > dec (sq);
    for (int i=1; i<=sq; ++i)
        dec[i-1] = make_pair (powMod (g, int (i * sq * 1LL * k % (n - 1)), n), i);
    sort (dec.begin(), dec.end());
    int any_ans = -1;
    for (int i=0; i<sq; ++i)
    {
        int my = int (powMod (g, int (i * 1LL * k % (n - 1)), n) * 1LL * a % n);
        vector < pair<int,int> >::iterator it =
            lower_bound (dec.begin(), dec.end(), make_pair (my, 0));
        if (it != dec.end() && it->first == my)
        {
            any_ans = it->second * sq - i;
            break;
        }
    }
    if (any_ans == -1) return vector<int>();

    int delta = (n-1) / gcd (k, n-1);
    vector<int> ans;
    for (int cur=any_ans%delta; cur<n-1; cur+=delta)
    {
        ans.push_back (powMod (g, cur, n));
        break;
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
 //   freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    matrix ank(n, n);
    for(int i = 0; i < n; i++) cin >> ank.a[0][i];
    for(int j = 1; j < n; j++) ank.a[j][j - 1] = 1;
    int k,x;
    cin >> k >> x;
    ank = ank.power(k - n);
    int pw = ank.a[0][0];
    auto res = discrete_root(M, pw, x);
    if(res.empty()) res.push_back(-1);
    cout <<res.front()<<endl;
    return 0;
}
