#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
      //  freopen("in.txt", "r", stdin);
        string s;
        cin >> s;
        int n = s.size();
        sort(s.begin(), s.end());
        bool flag = true;
        for(int i = 0; i < n - 1; i++)
        {
            int x = s[i] - 'a';
            int y = s[i+1] - 'a';
            if(y - x != 1) flag = false;
        }
        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
