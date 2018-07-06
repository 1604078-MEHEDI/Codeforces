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
    set<int>::iterator it;
    for(it = s.begin(); it != s.end(); it++){
        sum += a[*it];
    }
    cout<<sum<<endl;
    return 0;
}
