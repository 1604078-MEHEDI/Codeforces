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
    int n;
    cin >> n;
    set<int>s;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        s.insert(x);
    } 

    if(s.size() == 1){
        cout << 0<<endl;
        return 0;
    }
    set<int>st1, st2;
    int sz = s.size();
    for(int i = 1; i <= 100; i++){
        auto t = *s.begin() + i;
        int c1 = 0, c2 = 0, c3 = 0;
    for(auto x: s){
        //cerr << i<<endl;
        if(c1 == 0){
        c1++;
        continue;
       }
        if((x - i) == t || (x+i) == t || x == t)c1++;
    }
    auto tt = *s.begin() - i;
    for(auto x: s){
       if(c2 == 0){
        c2++;
        continue;
       }
       if((x - i) == tt || (x+i) == tt || x == t)c2++;
    }
    auto ttt = *s.begin();
    for(auto x: s){
       if(c3 == 0){
        c3++;
        continue;
       }
       if((x - i) == ttt || (x+i) == ttt || x == ttt)
        {
            cerr << x - i<< " "<<ttt<<endl;
            c3++;
        }
    }
    if(sz == c1 || sz == c2 || sz == c3){
        //cerr << c1 << " "<<c2 << " "<<c3<<endl;
        cout << i<<endl;
        return 0;
    }
}

cout << -1<<endl;
return 0;
    

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}