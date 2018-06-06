#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false),cin.tie(0);
#define ll long long
//vector<pair<int, int> > vp;

int main()
{
    IO
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    vector<int> v(m);
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        for(int j = 0; j < m; j++)
            if(s[i][j] == '1') ++v[j];
    }

    for(int i = 0; i < n; i++)
    {
        int ck = 1;
        for(int j = 0; j < m; j++)
        {
            if(s[i][j] == '1' && v[j] == 1)
                ck = 0;
        }
        if(ck)
        {
         cout<<"YES"<<endl;
         return 0;
        }
    }
cout<<"NO"<<endl;
return 0;
}
