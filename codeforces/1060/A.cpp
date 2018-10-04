#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '8')cnt++;
    }
    int number = n/11;
    int ans = min(number, cnt);
    cout<<ans<<endl;
    return 0;
}
