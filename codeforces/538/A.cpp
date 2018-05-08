#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l,n;
    string cf = "CODEFORCES";
    n = cf.length();

    string str;

    cin >> str;
    l = str.length();

    if(l >= n)
    {
        for(int i = 0; i <= n; ++i)
        {
           // cout<<str.substr(0,i)<<" "<<str.substr(l - (n - i))<<endl;
            if(str.substr(0, i) + str.substr(l - (n - i)) == cf)
            {
                cout<<"YES";
                return 0;
            }
        }
    }

    cout<<"NO";
    return 0;
}


