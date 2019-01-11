#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    int idx;
    int flag = 0;
    int ok = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '['){
            flag = 1;
            ok++;
        }
        else if(flag == 1 && s[i] == ':'){
            idx = i;
            ok++;
            break;
        }
    }
    flag = 0;
    int t;
     for(int i = n-1; i >=0 ; i--){
        if(s[i] == ']'){
            flag = 1;
            ok++;
        }
        else if(flag == 1 && s[i] == ':'){
            t = i;
            ok++;
            break;
        }
    }
    if(ok < 4 || idx >= t){
        cout << "-1\n";
        return 0;
    }
    int mx = ok;
    int cnt = 0;
    for(int i = idx + 1; i < t; i++){
        if(s[i] == '|'){
            cnt++;
        }
    }
    cout << (cnt+4)<<endl;
    return 0;
}
