#include<bits/stdc++.h>
using namespace std;
int ar[12345];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n;
    cin >> n;
    int mx = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        ar[a]++;
        mx = max(ar[a], mx);
    }
    cout<<mx<<endl;
    return 0;
}
