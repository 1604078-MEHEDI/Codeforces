#include<bits/stdc++.h>

using namespace std;

/*

        Bismillahir Rahmanir Rahim
        Problem :
        Problem Link :
        Topics :
        Solver : Masud Parves
        I Love Code More than Sharks Love Blood <3
*/


#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define SZ(a)           (int)a.size()
#define all(a)  a.begin(), a.end()
#define allr(a)  a.rbegin(), a.rend()


#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)

#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define TEST_CASE(t) for(int zz=1 ; zz<=t ; zz++)
#define PRINT_CASE printf("Case %d: ",zz)
#define Debug(x)            cout<<#x " = "<<(x)<<endl
#define NOT_VISITED 0
#define IS_VISITED 1
#define WHITE 0
#define GRAY 1
#define BLACK 2



int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N  (1<<pos);}
//int Reset(int N,int pos){return N= N & ~(1<<pos);}
//bool Check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/


const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
vector <int>v;
map < int, int >m;


void split(string s){


    f0(i,SZ(s)){
        int ch=s[i]-48;
        v.pb(ch);
    }

}

int main() {
    CIN
   #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif 

    int digit;
    cin >> digit;

    string num;
    cin >> num;

    f1(i,9){
        int x;
        cin >> x;
        m[i]=x;
    }

    int st=0,ed=0;
    split(num);

    f0(i,SZ(v)){
        if(v[i]<m[v[i]]) {
            st=i;
            break;
        }
    }

    for(int i=st ; i<digit ; i++){
        if(v[i]<=m[v[i]]){
            ed++;
        }else break;
    }

    ed=ed+st-1;
    //cout << st <<" "<<ed<< endl;

    vector <int>ans;
    ///unchanged segment
    for(int i=0 ; i<st ; i++){
        ans.pb(v[i]);
    }

    ///changed segment
    for(int i=st ; i<=ed ; i++){
        ans.pb(m[v[i]]);
    }
    ///unchanged last segment
    for(int i=ed+1 ; i<digit ; i++){
        ans.pb(v[i]);
    }

    f0(i,digit){
        cout << ans[i];
    }
    cout << endl;


    return 0;
}
