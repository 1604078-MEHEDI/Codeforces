#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,x,y;
    cin >> n >> x >> y;
    long long white = max(abs(x - 1), abs(y - 1));
    long long black = max(abs(n-x), abs(n-y));
    //cout << white << " "<<black<<endl;
    if(black >= white)cout << "White\n";
    else cout << "Black\n";
    return 0;
}
