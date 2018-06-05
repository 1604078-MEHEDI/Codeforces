#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll     long long

int main()
{
    IO
    int n;
    map<string, int> m;
    cin >> n;
    string str;
    int mx = 0;
    while(n--)
    {
      string s;
      cin >> s;
        m[s]++;
        if(m[s] > mx)
        {
            mx = m[s];
            str = s;
        }
    }
    cout<<str<<endl;
    return 0;
}
