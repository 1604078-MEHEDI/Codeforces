#include<bits/stdc++.h>
using namespace std;

struct ank{
    int s,d,c,id;
}a[101];

int ans[101];
bool cmp(const ank &a, const ank &b)
{
    return a.d < b.d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a[i].s >> a[i].d >> a[i].c;
        ans[a[i].d] = m+1;
        a[i].id = i;
    }
    sort(a, a+m+1, cmp);

    for(int i = 1; i <= m; i++){
        for(int k = a[i].s; k < a[i].d && a[i].c; k++){
            if(ans[k] == 0){
                ans[k] = a[i].id;
                a[i].c--;
            }
        }
        if(a[i].c){
            cout << "-1\n";
            return 0;
        }
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
