#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--){
        long long n,a,b;
        cin >> n >> a >> b;
        long long one = n*a;
        long long two = (n/2)*b + (n%2)*a;
        //cout << one <<" ------ "<<two<<endl;
        cout << min(one,two)<<endl;
    }
    return 0;
}
