#include<bits/stdc++.h>
using namespace std;
int ar[12345];

void fone()
{
    for(int i = 0; i <= (1<<10); i++){
        ar[i] = __builtin_popcount(i);
        //cout<<ar[i]<<" ";
    }
}

int main()
{
    fone();
    string s1,s2;
    cin >> s1 >> s2;
    int cnt=0,p1=0,m1=0,p2=0,m2=0;
    for(int i = 0; i < s1.size(); i++)
    {
        if(s1[i] == '+')p1++;
        if(s1[i] == '-')m1++;
    }
    for(int i = 0; i < s2.size(); i++)
    {
        if(s2[i] == '+')p2++;
        if(s2[i] == '-')m2++;
        if(s2[i] =='?')cnt++;
    }
    //cout<<cnt<<endl;
    if(cnt)
    {
        int total = 1 << cnt;
        int p = p1 - p2;
        int q = m1 -m2;
        int match = 0;
      //  cout<<p<<" "<<q<<endl;
        for(int i = 0; i < total; i++)
        {
            int one = ar[i];
            int zero = cnt -  one;
                    if(p == one && q == zero)match++;
        }
       // cout<<match<<" "<<total<<endl;
        double ans = double(match)/double(total);
        cout<<fixed<<setprecision(12)<<double(ans)<<endl;
    //    printf("%.12lf\n",ans);
    }
    else
    {
        double ans = 0.0;
        if(m1 == m2 && p1 == p2)
        {
            ans = ans + 1.0;
        }
        cout<<fixed<<setprecision(12)<<ans<<endl;
    }
    return 0;
}
