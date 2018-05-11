#include<bits/stdc++.h>
using namespace std;
int main () {
    int n, k;
    set < int > s;
    for(int i = 0; i<4; i++)
    {
        cin >> n;
        s.insert(n);
    }
    cout << 4-s.size();
    return 0;
}

