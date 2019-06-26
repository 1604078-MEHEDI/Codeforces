#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 1005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

const ll mod = 1e9 + 7;


string element[110]={"","H","He","Li","Be","B","C","N","O","F",
                     "Ne","Na","Mg","Al","Si","P","S","Cl","Ar",
                     "K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co",
                     "Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr",
                     "Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh",
                     "Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe",
                     "Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu",
                     "Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf",
                     "Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl",
                     "Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th",
                     "Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm"};


int n,m;
string s1[22], s2[22];
ll a[maxn], b[maxn];
ll dp[18][1 << 17], trace[18][1 << 17];
vector<ll> store[maxn];


int main()
{
    FASTIO
   // /*
    //double start_time = clock();
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
//*/
    int T;
    // cin >> T;
    T = 1;
    for(int cs = 1; cs <= T; cs++)
    {
        cin >> n >> m;
        
        for(int i = 0; i < n; i++){
          cin >> s1[i];
          a[i] = find(element, element+110, s1[i]) - element;
        }

        for(int i = 0; i < m; i++){
          cin >> s2[i];
          b[i] = find(element, element+110, s2[i]) - element;
        }

        for(int mask = 0; mask < (1 << n); mask++){
          ll sum = 0;
          for(int i = 0; i < n; i++){
            if(mask & (1 << i))
              sum += a[i];
          }
          if(sum > 110) continue;
          store[sum].push_back(mask);
        }

        dp[0][0] = 1;

        for(int i = 0; i < m; i++){
          for(int mask = 0; mask < (1 << n); mask++){
            if(!dp[i][mask]) continue;
            ll x = b[i];
            for(int j = 0; j <(int) store[x].size(); j++){
              ll t = store[x][j]; // maske 2
              if((mask & t) == 0 && !dp[i+1][mask | t]){
                dp[i+1][mask | t] = 1;
                trace[i+1][mask | t] = t;
              }
            }
          }
        }

        if(!dp[m][(1 << n) - 1]){
          cout << "NO\n";
          return 0;
        }

        cout << "YES\n";
        ll mask = (1 << n) - 1;
        for(int i = m; i > 0; i--){
          bool flag = false;
          for(int j = 0; j < n; j++){
            if(trace[i][mask] & (1 << j)){
              if(flag) cout << "+";
              flag = true;
              cout << s1[j];
            }
          }
          cout << "->"<<s2[i - 1]<<endl;
          mask &= ~trace[i][mask];
        }
    }

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}
