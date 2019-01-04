#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    string s1,s2,s3,s4,s5;
    cin >> s1>> s2 >> s3 >> s4 >> s5;
    if(str[0] == s1[0] || str[0] == s2[0] || str[0] == s3[0] || str[0] == s4[0] || str[0] == s5[0])
        cout << "YES\n";
    else if(str[1] == s1[1] || str[1] == s2[1] || str[1] == s3[1] || str[1] == s4[1] || str[1] == s5[1])
        cout << "YES\n";
        else
            cout << "NO\n";
        return 0;
}
