#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn], c[maxn], carry = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     int k;
     string s,t;
    cin >> k >> s >> t;
    for(int i = 0; i < k; i++) a[i] = ( s[i] - 'a' );
    for(int i = 0; i < k; i++) b[i] = ( t[i] - 'a' );

    for(int i = 0; i < k; i++){
        c[i] = (a[i] + b[i]) / 2;
        c[i] += carry;
        int x = i;
        while(c[x] >= 26){ // ---
            c[x] -= 26;
            c[x - 1] += 1;
            x--;
        }
        if((a[i] + b[i]) % 2 == 1) carry = 13; //---
        else carry = 0;
    }
    for(int i = 0; i < k; i++)
        cout << (char)('a' + c[i]);
    cout << endl;
    return 0;
}
