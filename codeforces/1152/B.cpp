#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 100005
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
    int x;
    cin >> x;
    vector<int> v;

    int pos;
        for(int i = 30; i >= 0; i--){
            if(x & (1 << i)){
                //cerr << (1 << i)<<endl;
                pos = i;
                break;
        }
    }
   // cerr << pos<<endl;
       int cnt;
       int op = 0;
        for(cnt = 1; cnt <= 40; cnt++){
           // bool flag;
            if(cnt%2 ==1){
                // flag = false;
                 int i;
            for( i = pos; i >= 0; i--){
                if( !( x & (1 << i) )){
                   // flag = true;
                    v.push_back(i+1);
                    int XOR = (1 << (i+1)) -1;
                    x = x ^ XOR;
                    op++;
                   // cerr << x << " "<<i << " "<<XOR<<endl;
                    break;
                }
            }
            //cerr << x  << " "<<__builtin_popcount(x) << endl;
            if(__builtin_popcount(x) == pos+1)
                {
                   // cout << "hocchena kno\n";
                    break;
                }
          }
          else{
            x += 1;
            op++;
            //cerr << "------------"<<x<<endl;
            //flag = false;
          }
        }
        cout << op << endl;
        for(int i = 0; i < (int)v.size(); i++){
            cout << v[i]<< " ";
        }
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}