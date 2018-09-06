#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    //  string s;
    //cin >> s;
    map<char, int>m;
    int mn = 1e6;
    for(int i = 0; i < n; i++)
    {
        char s;
        cin >> s;
        m[s]++;
    }
    int j = 0;
    for(char i = 'A' ; i <= 'Z'  ; i++)
    {
        if(j >= k)break;
        mn = min(m[i], mn);
        j++;
    }
    cout<<mn*k<<endl;
    return 0;
}
