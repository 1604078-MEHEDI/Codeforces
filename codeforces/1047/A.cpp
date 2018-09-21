#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n;
    cin >> n;
    if((n - 2) % 3 != 0 ){
        cout<<1<<" "<<1<< " "<<(n-2)<<endl;
    }
    else if((n-3) % 3 != 0){
        cout<<1<<" "<<2<<" "<<(n-3)<<endl;
    }
    return 0;
}
