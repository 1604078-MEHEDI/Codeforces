#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int>a(n);
    for(int i  = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> ans = {a[0]};

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 31; j++)
        {
            int lx = a[i] - (1 << j);
            int rx = a[i] + (1 << j);
            bool l = binary_search(a.begin(), a.end(), lx);
            bool r = binary_search(a.begin(), a.end(), rx);
            if(l && r && ans.size() < 3)
            {
                ans = {lx, a[i], rx};
            }
            if(l && ans.size() < 2)
            {
                ans = {lx, a[i]};
            }
            if(r && ans.size() < 2)
            {
                ans = {a[i], rx};
            }
        }
    }
    cout << ans.size() <<endl;
    for(auto x: ans)
        cout << x << " ";
    cout << endl;
}
