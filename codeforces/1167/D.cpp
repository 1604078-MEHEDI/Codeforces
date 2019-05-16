#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans(n, '0');

    stack<int>st;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') st.push(i);
        else{
            int x = st.top();
            st.pop();
            ans[i] = ans[x] = st.size() % 2 + '0';
        }
    }
    cout << ans << endl;
    return 0;
}
