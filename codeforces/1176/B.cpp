#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while(q--){
        int cnt = 0;
        int n;
        cin >> n;
        int one = 0, two = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(x % 3 == 0) cnt++;
            else if(x % 3 == 1) one++;
            else if(x % 3 == 2) two++;
        }
        int mn = min(one, two);
        int ext_one = max(0, one - mn);
        int ext_two = max(0, two - mn);
        ext_one = ext_one/3;
        ext_two = ext_two/3;
        cout << (cnt + mn + ext_one + ext_two)<<endl;
    }
    return 0;
}
