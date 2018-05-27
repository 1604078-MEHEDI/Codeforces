#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(0),cin.tie(0);
#define ll long long
bool isPalRec(string str,int s, int e)
{
    if (s == e)
    return true;


    if (str[s] != str[e])
    return false;

    if (s < e + 1)
    return isPalRec(str, s + 1, e - 1);

    return true;
}

bool isPalindrome(string str)
{
int n = str.length();
if (n == 0)
    return true;

return isPalRec(str, 0, n - 1);
}
map<char,int>m;
int main()
{
    IO
    string s;
    cin>>s;

    for(int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
    }
    if(m.size() == 1)
    {
        cout<<0<<endl;
        return 0;
    }
    if(isPalindrome(s))
        cout<<s.length()-1;
    else
        cout<<s.length();
}
