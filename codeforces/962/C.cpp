#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool sq(int x)
{
    int test = sqrt(x + 1e-6);
    return test*test == x;
}

int main()
{
    IO
    string s;
    cin >>s;
    int l = s.length();

    int mx = 0;

    for(int i = 0; i < (1 << l); i++)
    {
        string sub;
        for(int j = 0; j < l; j++)
        {
            if (i & (1 << j))
                sub += s[j];
        }

        if(sub.empty() || sub[0] == '0')continue;
        //cout<<"---"<<sub<<endl;

        stringstream str;
        str << sub;
       // cout<<"---"<<str<<endl;
        int x;
        str >> x;
      //  cout<<"---"<<x<<endl;

        int k = sub.size();
        if(sq(x)) mx = max(mx, k); //cout<<"---"<<mx<<endl;
    }
    if(mx == 0)cout<<-1<<endl;
    else cout<<l - mx<<endl;
    return 0;
}
