#include<bits/stdc++.h>
using namespace std;

bool ck(string s, int k)
{
    for(int i = 0; i < s.size(); i++)
        if(s[i] != s[i % k])
        return false;

    return true;
}

int cnt(string a, string b)
{
    int ct = 0;
    int n = a.size();
    int m = b.size();
    for(int i = 1; i <= min(n,m); i++)
    {
        if(n % i == 0 && m % i == 0)
        {

            if(a.substr(0, i) == b.substr(0, i))
            {
                if(ck(a, i) && ck(b, i))
                    ct++;
            }
        }
    }
    return ct;
}

int main()
{
    string s,t;
    cin >> s >> t;
    cout << cnt(s,t)<<endl;
    return 0;
}
