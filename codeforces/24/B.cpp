#include<bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define MAX 10005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);


 int p[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
 map <string, int> mp;
 vector <string> name;
 int a[1000][1000], point[1000];
 vector<pair<string, int> > v;

 int get_number(string s)
 {
    for(int i = 0; i < name.size(); i++)
        if(s == name[i]) return i;

    name.push_back(s);
    return name.size() - 1;
 }

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
            int num = get_number(s);
            a[num][i]++;
            if(i < 10)point[num] += p[i];
        }
    }
    int idx1 = 0, idx2 = 0;
    for(int i = 0; i < name.size(); i++){
        if(cmp1(i, idx1)) idx1 = i;
        if(cmp2(i, idx2)) idx2 = i;
    }

    cout << name[idx1] << "\n" << name[idx2] << "\n";
    

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}