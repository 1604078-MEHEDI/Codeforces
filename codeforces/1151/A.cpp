#include<bits/stdc++.h>
using namespace std;;

int main()
{
    int n;
    string s;
    string ans = "ACTG";
    map<pair<char, char>, int> mp;
    mp[{'A', 'Z'}] = 2;
    cin >> n >> s;
    int mn = 99999;
    for(int i = 0; i < n - 3; i++){
            int t = min(abs(s[i] - ans[0]), 26 - abs(s[i] - ans[0]) )+ min( abs(s[i+1] - ans[1]), 26 - abs(s[i+1] - ans[1]))+ min(abs(s[i+2] - ans[2]),  26 - abs(s[i+2] - ans[2]))+ min(abs(s[i+3] - ans[3]), 26 - abs(s[i+3] - ans[3]));
        mn = min(mn, t);
    }
    cout << mn << endl;
    return 0;
}
