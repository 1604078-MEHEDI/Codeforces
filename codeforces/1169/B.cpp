#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;

    cin >> n >> m;
    if(m == 1)
    {
        cout << "YES\n";
        return 0;
    }
    map<pair<int,int>, int> mp;
    map<int,int> ans;
    int x,y;
    for(int i = 1; i <= m; i++)
    {
        int a,b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        if(i == 1)
        {
            x = a;
            y = b;
        }
        ans[a]++;
        ans[b]++;
        mp[ {a,b}]++;
    }
    int tm_x = x;
    int tm_y = y;
    for(int i = 1; i <= n; i++)
    {
        x = tm_x;
        y = tm_y;
        int t = i;
        if(t > x) swap(t,x);
        //cout << t << " "<<x << " "<<ans[t] << " "<<ans[x] << " "<<mp[ {t,x}]<< " --> "<<i<<endl;
        if(t != x && (ans[t] + ans[x] - mp[ {t,x}]) == m )
        {
            //  cout << t << " "<<x << " "<<ans[t] << " "<<ans[x] << " "<<mp[ {t,x}]<<endl;
            cout << "YES\n";
            return 0;
        }
        int p = i;
        if(p > y) swap(p,y);
        //cout << p << " ** "<<y << " ** "<<ans[p] << " ** "<<ans[y] << " ** "<<mp[ {p,y}] << " --> "<<i<<endl;
        if(p != y && (ans[p] + ans[y] - mp[ {p,y}]) == m )
        {
            //cout << p << " "<<y << endl;
            //cout << p << " ** "<<y << " ** "<<ans[p] << " ** "<<ans[y] << " ** "<<mp[ {p,y}]<<endl;
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
