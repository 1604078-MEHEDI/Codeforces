#include<bits/stdc++.h>
using namespace std;

map<int, int>m;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    long long cnt =0;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for(int j =0; j < 32; j++)
            if((1 << j) > x)
                cnt += m[(1 << j) - x];
        m[x]++;
    }
    cout<<cnt<<endl;
    return 0;
}
