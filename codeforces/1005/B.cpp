#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    string s,t;
    getline(cin, s);
    getline(cin, t);
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int len = min(s.size(), t.size());
    long long cnt= s.size() + t.size();
    for(int i = 0; i < len; i++){
            if(s[0] != t[0])break;
        if(s[i] == t[i]) cnt -= 2;
        else break;
    }
    cout<<cnt<<endl;
    return 0;
}
