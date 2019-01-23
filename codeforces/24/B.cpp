#include<bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define MAX 10005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);


 int p[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
 map <string, int> mp;
 string name[1010];
 int a[1000][1000], point[1000];
 vector<pair<string, int> > v;

 bool cmp1(int x, int y)
 {
    if(point[x] != point[y]) return (point[x] > point[y]);
    if(a[x][0] != a[y][0]) return (a[x][0] > a[y][0]);

    for(int i = 0; i < 100; i++) if(a[x][i] != a[y][i]) return a[x][i] > a[y][i];
    
    return true;
 }

 bool cmp2(int x, int y)
 {
    if(a[x][0] != a[y][0]) return (a[x][0] > a[y][0]);
    if(point[x] != point[y]) return (point[x] > point[y]);
    for(int i = 0; i < 100; i++) if(a[x][i] != a[y][i]) return a[x][i] > a[y][i];
    
    return true;
 }

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

   
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            v.push_back({s,i}); // string + position
        }
    }

    int N = 0;
    for(int i = 0; i < v.size(); i++){
        mp[v[i].first] = 0;
       // cerr<<v[i].first << " "<<v[i].second << endl;
    }
    for(auto it = mp.begin(); it != mp.end(); it++){
       // cerr << it->first << " "<<it->second << endl;
        name[N] = it->first;
        it->second = N;
        N++;
        // cerr << it->first << " "<<it->second << endl;
        //cerr << name[N-1]<< "\n";
    }

    for(int i = 0; i < v.size(); i++){
        int player = mp[v[i].first];
        int rank = v[i].second;
        a[player][rank]++;
        if(rank < 10) point[player] += p[rank];
    }

    /*for(int i =0; i < 10; i++){
        for(int j = 0; j < 10; j ++){
            cerr << setw(2) << a[i][j];
        }
        cerr << endl;
    }*/

    int cnt = 0, cnt2 = 0;
    for(int  i =0; i < N; i++){
        if(cmp1(i,cnt)) cnt = i;
        if(cmp2(i, cnt2)) cnt2 = i;
    }

    cout << name[cnt] << "\n" << name[cnt2] << "\n";
    

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}