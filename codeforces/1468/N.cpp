#include <bits/stdc++.h>

#define       pb                 push_back
#define       sf                 scanf
#define       pf                 printf
#define       sz                 100005
#define       MOD                1000000007
#define       optimize           ios::sync_with_stdio(0);cin.tie(0);
#define       inf                0x3f3f3f3f
#define       READ               freopen("in.txt", "r", stdin);
#define       WRITE              freopen("out.txt", "w", stdout);

using namespace std;

typedef       long long int      ll;

int main()
{
    // READ
    optimize

    int tc;
    
    cin >> tc;
    
    while(tc--)
    {
    	int c1, c2, c3, a1, a2, a3, a4, a5, flag = 0;

    	cin >> c1 >> c2 >> c3 >> a1 >> a2 >> a3 >> a4 >> a5;

    	if(c1>=a1) c1 -= a1;
    	else flag = 1;

    	if(c2>=a2) c2 -= a2;
    	else flag = 1;

    	if(c3>=a3) c3 -= a3;
    	else flag = 1;

    	if(flag) cout << "NO" << endl;
    	else
    	{
    		a4 = max(0, a4-c1);
    		a5 = max(0, a5-c2);

    		// cout << a4 << " " << a5 << " " << c2 << endl;

    		if(a4+a5<=c3) cout << "YES" << endl;
    		else cout << "NO" << endl;
    	}
    }


    return 0;
}