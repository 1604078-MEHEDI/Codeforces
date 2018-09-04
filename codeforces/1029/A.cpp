#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    string t,s,str,ck,ans;
    cin >> t;
    str = t;
    s = t;
    ck = t;
    int flag = 0;
    //reverse(s.begin(), s.end());
    int idx = 0;
    for(int j = 1; j < s.length(); j++)
    {
        t = str;
        s = str;
        ck = str;
        //cout<<t.substr(j)<<" "<< s.substr(0, n-j)<<" "<<ck.substr(n-j)<<endl;
        if(t.substr(j) == s.substr(0, n-j))
        {
            ans = ck.substr(n-j);
            flag = 1;
            break;
        }
    }
    //cout<<s<<"--"<<idx<<endl;
//    for(int l = idx; l < t.length(); l++)
//    {
//        str += t[l];
//        // cout<<t[l];
//    }
    //cout<<s<<" "<<str<<endl;
    if(flag)
    {
        for(int i = 1; i < k; i++)
        {
            s += ans;
        }
    }
    else
    {
        for(int i = 1; i < k; i++)
        {
            s += str;
        }
    }
    cout<<s<<endl;
}
