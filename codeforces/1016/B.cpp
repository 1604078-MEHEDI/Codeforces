#include<bits/stdc++.h>
using namespace std;
int ck[12345];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);//,cout.tie(NULL);
    int n,m,q;
    cin >> n >> m >> q;
    string s,t;
    cin >> s >> t;
    for(int i = 0; i+m <= n; i++){
        string st(s.begin()+i, s.begin()+i+m);
        if(st == t)ck[i+1] = 1;
        ck[i+1] += ck[i];
    }

    while(q--)
    {
        int a,b;
        cin >> a >> b;
        b -= m - 1;
        if(a > b){
            cout<<0<<endl;
        }
        else{
            cout<<ck[b] - ck[a-1]<<endl;
        }
    }
}
