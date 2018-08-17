#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    int k = s.find('*');
  //  cout<<k<<endl;
    if(k>= 0 && k< n)
    {
        for(int i = 0; i <k; i++)
        {
            if(s[i] == t[i])continue;
            else
            {
                cout<<"NO\n";
                return 0;
            }
        }
        int j = m-1;
        for(int i = n-1; i >k; i--)
        {
            if(s[i] == t[j]){
                    j--;
                    if(j < k-1){
                        cout<<"NO\n";
                        return 0;
                    }
                    continue;
            }
            else
            {
                cout<<"NO\n";
                return 0;
            }
        }
        cout<<"YES\n";
        return 0;
    }
    else
    {
        if(s == t)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}
