#include<bits/stdc++.h>
#define LL long long
#define IO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define MAX 9000007
int ar[MAX];

int main()
{
  //   IO
    LL n,t,sum = 0,result;
    cin>>t;

    while(t--)
    {
        cin >> n;
        result = 0;
        sum = 0;
        result = (n+1)*n/2;
        int p = log2(n);
      //  cout<<p<<">>"<<endl;
        for(int i = 0; i <= p; i++)
        {
            sum += pow(2, i);
          //  cout<<" S:: "<<sum<<endl;
        }
        result -=  (sum*2);
        cout<<result<<"\n";
    }
}
