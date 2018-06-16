#include<bits/stdc++.h>
using namespace std;

int nr[11],mr[11],ck1[25],res[12],ck2[25];
int main()
{
    int n,m;
    cin >> n >> m;
    //memset(nr, -1, sizeof nr);
    //memset(mr, -1, sizeof mr);
    for(int i = 0; i < n; i++){
        cin >> nr[i];
        ck1[nr[i]] = i;
       // cout<<ck1[nr[i]]<<"* ";
        ck2[nr[i]] = 1;
        //cout<<ck2[nr[i]]<<"* ";
    }
    int j = 0;
    for(int i = 0; i < m; i++)
    {
        cin >> mr[i];
        ck2[mr[i]]++;
        if(ck2[mr[i]] > 1)
        {
            res[j++] = ck1[mr[i]];
           // cout<<res[j-1]<<" ";
        }
    }
    for(int i = 0; i < n; i++)//cout<<ck1[i]<<" ";
    sort(res, res+j);
    for(int i = 0; i < j; i++){
        cout<<nr[res[i]]<<" ";
    }
    return 0;
}
