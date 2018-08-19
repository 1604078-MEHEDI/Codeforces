#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int n;
    cin >> n;
    int cnt = 0;
    map<char, int>c;
    for(int i = 0; i<n; i++){
        char ak;
        cin >> ak;
        c[ak]++;
        if(c[ak] >= 2){
             cnt++;
        }
    }
    if(n == 1){
        cout<<"Yes\n";
        return 0;
    }
    if(cnt)cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
