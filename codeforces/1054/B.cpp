#include<bits/stdc++.h>
using namespace std;

int a[123456];
map<int,bool>M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(a[0] == 0){
        M[0] = true;
    }
    else{
        cout<<1<<endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(M[a[i]])continue;
        else if( M[a[i] - 1]){
            M[a[i]] = true;
        }
        else{
            //int ans = a[i-1] + 2;
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
