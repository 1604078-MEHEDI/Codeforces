#include<bits/stdc++.h>
using namespace std;
//vector<pair<double, int>vp;
vector<double>a;
double ar[12345];

int main()
{
    int n,v;
    cin >> n >> v;
    double ing = 0.0;
    for(int i  = 0; i < n; i++){
        cin >> ar[i];
        ing += ar[i];
    }
    double mx = (double)(v/ing);
    for(int i = 0; i < n; i++){
        double x;
        cin >> x;
        double ans = (double)(x/ar[i]);
        a.push_back(ans);
        //vp.push_back(make_pair(x,ar[i]));
    }
    sort(a.begin(), a.end());
    double ck = (double)(a[0]);
    //cout<<ck<<" "<<mx<<endl;
    if(mx > ck){
        cout<<fixed<<setprecision(12)<<ck*ing<<endl;
    }
    else{
        cout<<fixed<<setprecision(12)<<mx*ing<<endl;
    }
    return 0;
}
