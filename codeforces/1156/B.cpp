#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 100005
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


/// array globaly declare korbo, kokhon a[n+2] evabe korbona
/// loop check korbo koto porjunto choltese
///n & m thakle duitai ki n & n nki porer ta m likhsi cheak korbo
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
    map<char, int>mp;
    int cnt = 0;
    for(char ch = 'a'; ch <= 'z'; ch++){
        mp[ch] = ++cnt;
        //cerr << ch << " "<<mp[ch]<<endl;
    }
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        //cerr << s << endl;
        string odd, even;
        for(int i = 0; i <(int) s.size(); i++){
            if(mp[s[i]]&1){
                //cerr << s[i]<<endl;
               // odd.push_back(s[i]);
                odd += s[i];
            }
            else{
                //cerr << s[i] <<endl;
               // even.push_back(s[i]);
                even += s[i];
            }
        }
        if(even.size() == 0){
            cout<< odd<< endl;
            continue;
        }
       else if(odd.size() == 0){
            cout << even <<endl;
                continue;
        }
        //cerr << odd.size() << " "<<even.size() << endl;
        sort(even.rbegin(), even.rend());
        sort(odd.rbegin(), odd.rend());
        int x,y;
         x = mp[even[0]];
         y = mp[odd[odd.size() - 1]];
        //cerr << even[0] << " "<<odd[odd.size() - 1] <<endl;
        //cerr << x << " "<<y<<endl;
        if(abs(x - y) == 1){
            x = mp[even[even.size() - 1]];
            y = mp[odd[odd.size() - 1]];
             if(abs(x - y) == 1){
              x = mp[even[even.size() - 1]];
              y = mp[odd[0]];
              if(abs(x - y) == 1){
              x = mp[even[0]];
              y = mp[odd[0]];
              if(abs(x - y) == 1){
                cout << "No answer\n";
               }
               else{
                for(int k = (int) odd.size() - 1; k >= 0; k--)cout << odd[k];
                   cout <<even <<endl;
               }
               }
               else{
                for(int k = (int) odd.size() - 1; k >= 0; k--)cout << odd[k];
                    for(int k = (int) even.size() - 1; k >= 0; k--)cout << even[k];
                      cout << endl;
               }
             }
           else{
            cout << odd;
            for(int k = (int) even.size() - 1; k >= 0; k--)cout << even[k];
              cout << endl;
           }
        }
        else{
            cout << odd << even<<endl;
        }
    }
    

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}