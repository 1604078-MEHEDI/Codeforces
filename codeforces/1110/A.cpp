#include<bits/stdc++.h>
using namespace std;

int main()
{
    int b,k;
    cin >> b >> k;
    int odd = 0;
    //int flag = 0;
    //if(b%1)flag = 1;
    for(int i = 0; i < k; i++){
            int x;
          cin >> x;
            if(i == k-1){
            if(x&1)odd++;
          }
          else if(b&1){
            if(x&1)odd++;
          }
    }
    //cout << odd << endl;
    if(odd&1)cout << "odd\n";
    else cout << "even\n";
    return 0;
}
