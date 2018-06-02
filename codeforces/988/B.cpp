#include<bits/stdc++.h>
using namespace std;
/**
#define mem(a,b) memset(a, b, sizeof(a) )
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))
**/
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

vector<pair<int, string> > vp;

int main()
{
    IO
    int n;
    string s,str,ss;
    cin >>n;
    int mx = 0;
    for(int i =0; i < n; i++)
    {
        cin >> s;
        int l = s.length();
       /* if(l > mx)
        {
            mx = l;
            str = s;
        }*/
        vp.push_back(make_pair(l, s));
    }
    sort(vp.begin(), vp.end());
   // cout<<str<<endl;
    for(int i = 0; i < n - 1; i++)
    {
         ss = vp[i].second;
         str = vp[i+1].second;
        //cout<<ss<<endl;
        if (str.find(ss) != string::npos)continue;
        else
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for(int i =0; i < n; i++)
    {
        cout<<vp[i].second<<endl;
    }
    return 0;
}
