#include<bits/stdc++.h>
#define LL long long
#define IO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
//int ar[20000001];
map<char, int> m,my,mz,mm;

int ans(int n)
{
    mm.clear();
    int mx = 0;
    string s;
    cin >>s;
    int ss = s.size();
    for(int i = 0; i < ss; i++)
    {
        mm[s[i]]++;
        mx  = max(mm[s[i]], mx);
    }
  //  cout<<mx<<endl;
    if(ss == 1) return 1;

    if(mx == ss)
    {
        if(n == 1) return mx - 1;
        else return mx;
    }
    return min(ss, mx+n);
}

int main()
{
    IO
    //  cout<<'Z' - 'A' + 26<<endl;
    int n;
    cin >> n;
    int ar[3];
    ar[0] = ans(n);
    ar[1] = ans(n);
    ar[2] = ans(n);

    int mx = max(max(ar[0], ar[1]), ar[2]);
    int cnt = 0;
    for(int i = 0; i < 3; i++)if(ar[i] == mx)cnt++;
    if(cnt >= 2)
    {
        cout<<"Draw"<<"\n";
        return 0;
    }
    if(ar[0] == mx)
    {
        cout<<"Kuro"<<"\n";
    }
     if(ar[1] == mx)
    {
        cout<<"Shiro"<<"\n";
    }
     if(ar[2] == mx)
    {
        cout<<"Katie"<<"\n";
    }
}
