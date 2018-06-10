#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false),cin.tie(0);
#define ll long long

int main()
{
    IO
    string s;
    cin >> s;
    int x,y;
    if(s[0] == 'h' || s[0] == 'a')x = 2;
    else x = 3;

    if(s[1] == '1' || s[1] == '8')y = 2;
    else y = 3;
    cout<<(x * y) - 1<<endl;
    return 0;
}
