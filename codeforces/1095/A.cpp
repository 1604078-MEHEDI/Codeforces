#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int idx = 1;
    for(int i = 0; i < n; i += idx){
        cout << s[i];
        idx++;
    }
    return 0;
}
