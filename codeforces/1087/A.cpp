#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size() - 1;
    int idx = n/2;
    //cout << idx << endl;
    int r = 1, l = 0;
    for(int i = 1; i <= n+1; i++){
        if(i&1){
            cout << s[idx - l];
            l++;
        }
        else{
            cout << s[idx+r];
            r++;
        }
    }
    return 0;
}
