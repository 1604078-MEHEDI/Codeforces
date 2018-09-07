#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n";

const int N = 1e5+5;
ll n;
ll a[N],b[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)cin >>a[i];
    for(int i = 1; i <= n; i++)cin >> b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    reverse(a+1, a+n+1);
    reverse(b+1, b+n+1);
    ll  i = 1, j = 1, player = 0, m = 0, A = 0, B = 0;
    while(m < 2*n){
        m++;
        if(!player){
            if(a[i] >= b[j]){
                A += a[i];
                i++;
            }
            else j++;
        }
        else{
            if(b[j] >= a[i]){
                B += b[j];
                j++;
            }
            else i++;
        }
        player ^= 1;
    }
    cout<<A - B<<endl;
    return 0;
}
