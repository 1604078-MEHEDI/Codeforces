#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,z,t1,t2,t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;

    int t_floor = abs(x - y);
    int stair_time = t_floor * t1;
   // cout<<abs(x - z)*t2<<" "<<t3*3<<" "<<t_floor*t2<<endl;
    int elevator_time = abs(x - z)*t2 + t3*3 + t_floor*t2;
   // cout<<stair_time<<" "<<elevator_time<<endl;
    if(stair_time >= elevator_time)cout<< "YES\n";
    else cout<< "NO\n";
    return 0;
}
