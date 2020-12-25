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
    	string s;

    	cin >> s;

    	vector <pair <int, int>> v;

    	int n = s.size(), x = 0, y = 0, ansx = 0, ansy = 0;

    	// cout << n << endl;

    	for(int i = 0; i < n; i++)
    	{
    		if(s[i]=='U') y++;
			else if(s[i]=='D') y--;
			else if(s[i]=='L') x--;
			else x++;

			v.pb({x, y});
    	}

    	for(auto a: v)
    	{
    		int xx =  a.first;
    		int yy = a.second;

    		// cout << xx << " " << yy << endl;

    		x = y = 0;

    		for(int i = 0; i < n; i++)
    		{
    			if(s[i]=='U') y++;
    			else if(s[i]=='D') y--;
    			else if(s[i]=='L') x--;
    			else x++;

    			if(x==xx and y==yy)
    			{
    				if(s[i]=='U') y--;
	    			else if(s[i]=='D') y++;
	    			else if(s[i]=='L') x++;
	    			else x--;
    			}
    		}

    		if(x==0 and y==0)
    		{
    			ansx = xx;
    			ansy = yy;
    			break;
    		}
    	}

    	cout << ansx << " " << ansy << endl;
    }


    return 0;
}