#include<bits/stdc++.h>
using namespace std;
const int maxn = 505;
int a[maxn][maxn], b[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> b[i][j];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] != b[i][j]){
                if(i == n || j == m){
                    cout << "No\n";
                    return 0;
                }
                a[i][j] ^= 1;
                a[i+1][j] ^= 1;
                a[i][j+1] ^= 1;
                a[i+1][j+1] ^= 1;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}
