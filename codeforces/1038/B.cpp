#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if(n == 1 || n == 2)
    {
        cout<< "No\n";
        return 0;
    }
    else
    {
        cout<<"Yes\n";
        cout<<n/2<<" ";
        for(int i = 2; i <= n; i += 2)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    if(n % 2 == 0)cout<<n/2<<" ";
    else  cout<<(n/2)+1<<" ";
        for(int i = 1; i <= n; i += 2)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}
