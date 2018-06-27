#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n;
    cin >>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    while(1){
        for(int i = 0; i < n; i++){
            if(i + 1 > a[i]){
                cout<<i+1<<endl;
                return 0;
            }
            a[i] = a[i] - n;
        }
    }
    return 0;
}
