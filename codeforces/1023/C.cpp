#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    stack<char> checker;
    queue<char> ans;
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int p = n;
    if(n == k)
    {
        cout<<s<<endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            checker.push(s[i]);
//            ans.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if(p == k)
            {
                checker.push(s[i]);
                continue;
            }
            p -= 2;
            checker.pop();
            //  ans.push(s[i]);
        }
    }
    string str;
    while(!checker.empty())
    {
        str += checker.top();
        checker.pop();
    }
    reverse(str.begin(), str.end());
    cout<<str<<endl;
    return 0;
}

