#include<bits/stdc++.h>
using namespace std;
const int maxn = 500005;

int parent[maxn], Rank[maxn];

void Initialization(int n)
{
    for(int i = 0; i <= n; i++)
        parent[i] = i, Rank[i] = 1;
}

int find_parent(int x)
{
    if(parent[x] == x)
    {
        return x;
    }
    return parent[x] = find_parent(parent[x]);
}

void make_union(int x, int  y)
{
    int p = find_parent(x);
    int q = find_parent(y);
    if(p != q)
    {
        if(Rank[p] < Rank[q])
            swap(p,q);
        parent[q] = p;
        Rank[p] += Rank[q];
        // Rank[q] += Rank[p];
    }
}

bool isUnion(int x, int y)
{
    return find_parent(x) == find_parent(y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    Initialization(n);
    for(int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        int x;
        if(k) cin >> x;
        for(int j = 1; j < k; j++)
        {
            int y;
            cin >> y;
            if(!isUnion(x,y))
            {
                // cout << "enter---\n";
                make_union(x,y);
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << Rank[find_parent(i)] << " ";
    }
    return 0;
}
