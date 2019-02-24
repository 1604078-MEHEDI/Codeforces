#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = (n+1)/2;
    int neg = 0, posi = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x > 0)posi++;
        else if(x < 0)neg++;
    }
    if(posi >= ans)cout << 1<<endl;
    else if(neg >= ans)cout << "-1\n";
    else cout << "0\n";
    return 0;
}
