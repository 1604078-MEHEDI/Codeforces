#include<bits/stdc++.h>
using namespace std;
vector<int> odd, even;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        //int p = __builtin_popcount(x);
        if(x&1){
            odd.push_back(x);
        }
        else even.push_back(x);
    }
    //cout << odd.size() << " "<<even.size()<<endl;
    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());
    int s1 = odd.size();
    int s2 = even.size();
    //int mn = min(s1, s2);
    if((s1 - s2) == 1 || (s2 - s1) == 1){
        cout << 0 << endl;
        return 0;
    }
    long long ans = 0;
    if(s1 > s2)
    for(int  i = s2+1; i < odd.size(); i++) ans += odd[i];
    else
    for(int i = s1+1; i < even.size(); i++) ans += even[i];
    cout << ans<<endl;
    return 0;
}

