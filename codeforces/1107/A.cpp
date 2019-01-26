#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define MAX 10005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;


int main()
{
    FASTIO
    ///*
    //double start_time = clock();
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    //*/

    int q;
    cin >> q;
    while(q--){
        int n;
        string s;
        cin >> n >> s;
        if(n == 2){
            int first = s[0] - '0';
            int last = s[1] - '0';
            if(first >= last)
                cout << "NO\n";
            else{
                cout << "YES\n";
                cout << 2 << endl;
                cout << first <<  " "<<last<<endl;
            }
        }
        else{
            cout << "YES\n";
            cout << 2 << endl;
            cout << s[0] << " ";
            for(int i = 1; i < n; i++)
                cout << s[i];
            cout << "\n";
        }
    }
    

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}