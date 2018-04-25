#include<math.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //  cin.tie(NULL);

    int k,n,s,p,t,result;
    cin>>k>>n>>s>>p;

// int t = ceil(n/s) * k;
    if(n%s==0) t = (n/s)*k;
    else
        t = (n/s + 1)*k;
    // int result = ceil(t/p);
    if(t%p == 0) result = t/p;
    else
        result = t/p +1;
    cout<<result<<"\n";
    return 0;
}
