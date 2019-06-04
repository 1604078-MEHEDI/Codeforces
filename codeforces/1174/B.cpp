#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    int odd = 0, even = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x&1)odd++;
        else even++;
        a.push_back(x);
    }
    if(odd > 0 && even > 0) sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
