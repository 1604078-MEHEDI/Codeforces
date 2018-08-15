#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int q;
    cin >> q;
    while(q--)
    {
        int l,r,k;
        cin >> l >> r >> k;
        string s1 = s.substr(0, l-1);
        string s2 = s.substr(l-1, r-l+1);
        string s3 = s.substr(r, s.length());
       //  cout<<" ---------- "<<s2<<endl;
        int ck = s2.length();
        int x = k%ck;
        string sp1 = s2.substr(s2.length() - x, s2.length());
        string sp2 = s2.substr(0, s2.length()-x);
        //cout<<sp1<<" "<<sp2<<endl;
        s2 = sp1 + sp2;
         //cout<<s2<<endl;
        s = s1+s2+s3;
          // cout<<s<<endl;
    }
    cout<<s<<endl;
}
