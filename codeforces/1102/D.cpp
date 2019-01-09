#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int zero = 0, one = 0, two = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0')zero++;
        else if(s[i] == '1')one++;
        else two++;
    }
    int single = n/3;
    //for zero using 2
    for(int i = 0; i < n; i++){
        if(zero >= single)break;
        if(s[i] == '2' && two > single){
            s[i] = '0';
            two--;
            zero++;
        }
    }
    // for zero using 1
    for(int i = 0; i < n; i++){
        if(zero >= single)break;
        if(s[i] == '1' && one > single){
            s[i] = '0';
            one--;
            zero++;
        }
    }

     // for 2 using 0
    for(int i = n-1; i >= 0; i--){
        if(two >= single)break;
        if(s[i] == '0' && zero > single){
            s[i] = '2';
            zero--;
            two++;
        }
    }

    // for 2 using 1
     for(int i = n-1; i >= 0; i--){
        if(two >= single)break;
        if(s[i] == '1' && one > single){
            s[i] = '2';
            one--;
            two++;
        }
    }

    // for 1 using 2
    for(int i = 0; i < n; i++){
        if(one >= single)break;
        if(s[i] == '2' && two > single){
            s[i] = '1';
            two--;
            one++;
        }
    }
    //for 1 using 0
    for(int i = n-1; i >= 0; i--){
        if(one >= single)break;
        if(s[i] == '0' && zero > single){
            s[i] = '1';
            zero--;
            one++;
        }
    }
    cout << s << endl;
    return 0;
}
