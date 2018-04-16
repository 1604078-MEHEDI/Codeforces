#include<bits/stdc++.h>
using namespace std;

const int infinity = 1234567890;


int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    vector<pair<int, int> >a(n);
    for(int i=0; i<n; i++)
        cin>>a[i].first>>a[i].second;

    int m;
    cin>>m;
    vector<pair<int, int> >b(m);
    for(int i=0; i<m; i++)
        cin>>b[i].first>>b[i].second;

    int min1 = infinity, max1 = -infinity;
    int min2 = infinity, max2 = -infinity;

    for(int i=0; i<n; i++)
    {
        max1 = max(max1, a[i].first);
        min1 = min(min1, a[i].second);
    }

    for(int i=0; i<m; i++)
    {
        max2 = max(max2, b[i].first);
        min2 = min(min2, b[i].second);
    }

    int res = max(max2 - min1, max1 - min2);

    cout<<max(res, 0);
    return 0;
}
