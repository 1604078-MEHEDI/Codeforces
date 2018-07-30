#include<bits/stdc++.h>
using namespace std;
int a[12345],b[12345];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int n;
    cin >> n;
    int s1=0,s2=0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s1 += a[i];
    }
    for(int i =0; i < n; i++){
        cin >> b[i];
        s2 += b[i];
    }
    if(s1>= s2){
            cout<<"Yes"<<endl;
        }
    else{
        cout<<"No"<<endl;
    }
    return 0;
    }

