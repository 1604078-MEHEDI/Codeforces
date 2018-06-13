#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;
    vector<int>v(n);

    for(int i = 0; i < n; i++){
            int a;
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0;
    while(v.size())
    {
        int uniq = v.back();

        while(v.size() && v.back() == uniq)
        {
            ans++;
            v.pop_back();
        }
        while(v.size() &&  v.back() >= uniq - k)
        {
            uniq = v.back();
            v.pop_back();
        }
    }
    cout<<ans<<endl;
}
