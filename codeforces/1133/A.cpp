#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int h1,h2,m1,m2;
    char c;
    cin >> h1 >> c >> m1;
    cin >> h2 >> c >> m2;
    int d_h, d_m;
    if(h2 >= h1) d_h = h2 - h1;
    else{
        d_h = 24 - (h1 - h2);
    }
    if(m2 >= m2){
        d_m = m2 - m1;
    }
    else{
            d_h -= 1;
        d_m = 60 - (m1 - m2);
    }
    int total_mn = (d_h/2)*60 + (d_m/2);
    if(d_h & 1) total_mn += 30;
    total_mn += h1*60 + m1;
    int f_h, f_m;
    int tem_h = total_mn/60;
    int total_m = total_mn % 60;
    f_h = tem_h;
    if(tem_h > 23) f_h = tem_h - 24;
    if(f_h < 10)cout << "0"<<f_h<<":";
    else cout <<f_h<<":";
    if(total_m < 10)cout << "0"<<total_m<<endl;
    else cout << total_m<<endl;
  //  cout << f_h << ":"<<total_m<<endl;
    return 0;
}
