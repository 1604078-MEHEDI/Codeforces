#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
            set<char>st;
        string s;
        cin >> s;
        int sz = s.size();
    for(int i = 0; i <sz; i++)st.insert(s[i]);
    if(st.size() == 1)cout << "-1\n";
    else{
        sort(s.begin(), s.end());
        cout << s<<endl;
     }
     st.clear();
    }
    return 0;
}
