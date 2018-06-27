#include<bits/stdc++.h>
using namespace std;
//vector<pair<char, int> > vp;
//map<char, int>mp;
int pt[123456],vs[123456];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int n,m;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        pt[a] = i+1;
       // vs[a] = n - i;
    }
//    sort(pt+1, pt+n+1);
//    int p = n;
//    for(int i = 1; i <= n; i++){
//        vs[p--] = i;
//    }
    cin >> m;
    long long s_pt = 0, s_vs = 0;
    for(int i = 0; i < m; i++){
        int q;
        cin >>q;
        s_pt += pt[q];
        s_vs += n - pt[q] + 1;
    }
    cout<<s_pt<<" "<<s_vs<<endl;
    return 0;

}
