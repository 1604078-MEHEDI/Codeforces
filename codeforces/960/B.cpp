#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5;
LL a[maxn], b[maxn];
priority_queue<LL> PQ;
int main()
{
    LL n,k1,k2;

    cin >> n >> k1 >> k2;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++){
        LL Er = abs(a[i] - b[i]);
        PQ.push(Er);
    }
    int k = k1 + k2;
    while(k > 0){
        LL Er = PQ.top();
        PQ.pop();
        Er = abs(Er - 1);
        k--;
        PQ.push(Er);
    }
    LL ans = 0;
    while(!PQ.empty()){
        LL E = PQ.top();
        PQ.pop();
        ans += (E * E);
    }
    cout << ans << endl;
    return 0;
}
