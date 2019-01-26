#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define MAX 100005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const int Max = 1e5 + 7;

vector<int> v[Max];

bool cmp(vector<int> & a, vector<int> & b){
    return (a.size() > b.size());
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

    int n, m;
    cin >> n >> m;
    for(int i = 0; i< n; i++)
    {
        int s, r;
        cin >> s >> r;
        v[s].push_back(r);
    }
    for(int i = 1; i <= m; i++) sort(v[i].rbegin(), v[i].rend());

    /*for(int i = 1; i <= m; i++)
    {
        ll sum = 0;
        for(int j = 0; j < v[i].size(); j++)
        {
            sum += v[i][j];
            v[i][j] = sum;
            //cerr << v[i][j] << " ";
        }
        //cerr << "enter---*8\n";
        //cerr << endl;
    }*/
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j < v[i].size(); j++){
            v[i][j] += v[i][j-1];
           // cerr << v[i][j]<< " ";
        }
        //cerr << endl;
    }
    sort(v+1, v+1+m, cmp);
    int mx = 0;
    for(int i = 1; i <= n; i++){
        int cur = 0;
        for(int j = 1; j <= m; j++){
            if(v[j].size() < i) break;
            if(v[j][i-1] > 0) cur += v[j][i-1];
        }
        mx = max(mx, cur);
    }
    cout << mx<<endl;


    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}