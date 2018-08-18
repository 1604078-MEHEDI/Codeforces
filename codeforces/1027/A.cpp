#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        string st = s;
        reverse(st.begin(), st.end());
        int flag = 0;
        //cout<<s<<endl;
        //cout<<st<<endl;
        if(s == st){
            cout<<"YES\n";
            continue;
        }
        for(int i = 0; i < n; i++)
        {
            if(st[i] == s[i])continue;
            char ss = s[i];
            char tt = st[i];
            if( (++tt) == (++ss))continue;
            --tt;
            --ss;
            //cout<<tt<<" "<<ss<<endl;
            if((--tt) == (--ss))continue;
            ++tt;
            ++ss;
           // cout<<tt<<" "<<ss<<endl;
            if((--tt) == (++ss))continue;
            ++tt;
            --ss;
           // cout<<tt<<" "<<ss<<endl;
            if((++tt) == (--ss))continue;
            else
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
}
