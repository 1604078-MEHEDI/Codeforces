#include<bits/stdc++.h>
using namespace std;
map<string, int>mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n;
    cin >> n;
    string s;
    for(int i = 0; i< n; i++){
        cin >> s;
        mp[s]++;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        string st;
        cin >> st;
        if(mp[st] >0){
            mp[st]--;
        }
        else cnt++;
    }
    cout<<cnt<<endl;
    return 0;

}
