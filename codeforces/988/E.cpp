#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll     long long

ll cmp(string s1, string s2)
{
    ll p1,p2,flag = 0, swp = 0, sz = s1.size();

    for(int i = sz - 1; i >= 0; i--)
    {
        if(s1[i] == s2[1])
        {
            flag = 1;
            p1 = i;
            break;
        }
    }
    if(!flag)return 1e10;

    for(int i = p1; i < sz - 1; i++)
    {
        swap(s1[i], s1[i+1]);
      //  cout<<s1<<endl;
        swp++;
    }

    for(int i = sz - 2; i >= 0; i--)
    {
        if(s1[i] == s2[0])
        {
            flag = 0;
            p2 = i;
            break;
        }
    }
    if(flag) return 1e10;
    for(int i = p2; i < sz - 2; i++)
    {
        swap(s1[i], s1[i+1]);
        swp++;
    }

    if(s1[0] != '0')return swp;
    else
    {
        for(int i = 1; i < sz - 2; i++)
        {
            swp++;
            if(s1[i] != '0')
            {
                flag = 1;
                break;
            }
        }
        if(flag) return swp;
        else return 1e10;
    }

}


int main()
{
   IO
   string s;
   cin >>s;
   ll mn = 1e10;
   mn = min(mn, cmp(s, "00"));
      mn = min(mn, cmp(s, "25"));
         mn = min(mn, cmp(s, "50"));
            mn = min(mn, cmp(s, "75"));
            if(mn == 1e10)
                cout<<"-1\n";
            else
                cout<<mn<<endl;
            return 0;
}
