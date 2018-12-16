#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        if(x%2 == 0){
            cout << (x/2)<<endl;
            continue;
        }
        else{
                int cnt = 3;
                while(1){
                    if(x%cnt == 1){
                        cnt += 2;
                    }
                    else{
                        cout << (x/cnt)+ (x%cnt)/2<<endl;
                        break;
                    }
                }
        }
    }
    return 0;
}
