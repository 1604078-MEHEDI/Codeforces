#include<bits/stdc++.h>
using namespace std;
//vector< pair<int, int> >v;
vector<int>v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n;
    cin >> n;
    int t1=0,t2=0;
    long long p=1e10,q=0;
    for(int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        if(a >= b)
        {
            if(p >= a)
            {
                p = a;
                v.push_back(p);
            }
            else if(p >= b)
            {
                    p = b;
                    v.push_back(p);
            }
            else{
                t1++;
            }
        }
        else
        {
            if(p >= b)
            {
                p = b;
                v.push_back(p);
            }
            else if (p >= a)
            {
                    p = a;
                    v.push_back(p);
            }
            else{
                t2++;
            }
        }
        //cout<<p<<endl;
    }
if(t1 > 0 || t2 > 0){
    cout<<"NO"<<endl;
    return 0;
}
    cout<<"YES"<<endl;
    return 0;
}

