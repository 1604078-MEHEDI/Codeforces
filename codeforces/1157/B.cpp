#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100005;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int a[11];
    for(int i = 1; i <= 9; i++){
            cin >> a[i];
    }
    priority_queue<string>PQ;
    PQ.push(s);
    string tm = s;
    string mx = s;
int f = 0;
    for(int i = 0; i < n; i++){
        int x = s[i] - '0';
        if(x > a[x]){
if(f)break;
           s = tm;
        }
        else if(x<a[x]){
          f = 1;
            s[i]  = a[x] + '0';
            //cout << s[i] << endl;
          mx = max(mx, s);
            //PQ.push(s);
        }
    }
    cout << mx << endl;
    //cout << mx << " "<<s<<endl;
    return 0;
}