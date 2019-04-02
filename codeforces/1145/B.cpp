#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<int> yes ={2, 3, 4, 5, 12, 30, 35, 43, 46, 52, 64, 86};
//    set<int> no = {1, 10, 11, 13, 24};
    int n;
    cin >> n;
    if(yes.count(n))cout << "YES\n";
    else{
        cout << "NO\n";
    }
}
