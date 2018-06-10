#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false),cin.tie(0);
#define ll long long

int main()
{
    IO
    ll n,m,a,b;
    cin >> n >> m >> a  >> b;
    if(n % m == 0){
        cout<<0<<endl;
        return 0;
    }
    ll p = n, q = n;

    ll c1 = (p + m - 1)/m;
    ll c2 = q % m;
    ll crt = (c1 * m) -  n;
    crt = crt *a;
    ll des = c2 * b;
    cout<<min(des, crt)<<endl;
   // if(crt < des)cout<<crt;
    //else if(des < crt)cout<<des;
    return 0;
}
