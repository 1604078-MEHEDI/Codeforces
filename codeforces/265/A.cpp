#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2;

    cin >> s1 >> s2;
    int l = 0, count = 1;
    for(int i = 0; i < s2.length(); i++)
    {
        if(s1[l] == s2[i])
        {
            count++;
            l++;
        }
    }

    cout << count<<"\n";
    return 0;
}
