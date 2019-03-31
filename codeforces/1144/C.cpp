#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n+2];
    bool flag = false;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
        if(mp[a[i]] >=3 ) flag = true;
    }
    if(flag){
        cout << "NO\n";
        return 0;
    }
    sort(a,a+n);
    vector<int> dec, inc;
    cout << "YES\n";
    inc.push_back(a[0]);
    for(int i = 1; i < n; i++){
            if(a[i -1] == a[i]){
                dec.push_back(a[i]);
                continue;
            }
           // cout << " "<<a[i];
           inc.push_back(a[i]);
    }
    cout << inc.size()<<endl;
    for(int i = 0; i < inc.size(); i++) cout << inc[i] << " ";
    cout << endl;
    sort(dec.rbegin(), dec.rend());
    cout << dec.size()<<endl;
    for(int i =0; i < dec.size(); i++)
        cout << dec[i] << " ";
    return 0;
}
