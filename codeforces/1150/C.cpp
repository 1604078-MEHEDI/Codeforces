#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
//#define maxn 100005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
const int dx4[] = { -1, 0, 1, 0 }; // 4 direction i
const int dy4[] = { 0, 1, 0, -1 }; // 4 direction j
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; // 8 direction i
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; // 8 direction j
const int dxk[] = { -2, -2, -1, -1, 1, 1, 2, 2 }; // knight direction i
const int dyk[] = { -1, 1, -2, 2, -2, 2, -1, 1 }; // knight direction j
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

const int maxn = 2*200005;
int a[maxn];
int prime[maxn];
vector<int> p;

void seive()
{
    memset(prime, 0, sizeof(prime));
    prime[0] = prime[1] = 1;
    for(int i = 4; i < maxn; i += 2) prime[i] = 1;

    for(int i = 3; i*i < maxn; i += 2){
        if(prime[i] == 0){
            for(int j = i*i; j < maxn; j += i)
                prime[j] = 1;
        }
    }
    for(int i = 2; i < maxn; i++){
        if(prime[i] == 0) p.push_back(i);
    }
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
    int n;
    cin >> n;
    int one = 0, two = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1)one++;
        else two++;
    }
    int sum = one + 2*two;
    seive();
    int sz = p.size();
   // cerr << one << " "<<two <<endl;
    sum = 0;
    for(int i = 0; i < sz; i++){
        int x = p[i];
        //cerr << x << endl;
        int ans = x - sum;
        sum += ans;
        while(ans >= 0){
           // cerr << x << " "<<p[i]<<endl;
            if(ans >= 2 && two > 0){
                cout << "2 ";
                ans -= 2;
                two--;
            }
            else if(ans >= 1 && one > 0){
                cout << "1 ";
                ans -= 1;
                one--;
            }
            else break;
            //cerr << one << "------"<<two <<endl;
        }
    }
    while(one > 0){
        cout << "1 ";
        one--;
    }
    while(two > 0){
        cout << "2 ";
        two--;
    }
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}