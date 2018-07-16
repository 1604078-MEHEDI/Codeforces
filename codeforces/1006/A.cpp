#include<bits/stdc++.h>
using namespace std;
int a[12345];
//queue<char>q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
            int x;
    cin >> x;
        if( x % 2 == 0) a[i] = x - 1;
        else a[i] = x;
    }
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
