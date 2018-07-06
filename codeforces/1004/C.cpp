#include<bits/stdc++.h>
using namespace std;
int a[123456];
set<int>s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[x] = s.size();
        s.insert(x);
    }
    long long sum=0;
    for(int i = 0; i < 100001; i++){
        sum += a[i];
    }
    cout<<sum<<endl;
    return 0;
}
