#include<bits/stdc++.h>
using namespace std;
int ar[1000],br[1000];

int main()
{
    int n;
    cin >>n;
    for(int i =1; i <= n/2; i++)
    {
        int x;
        cin >>x;
        ar[i] = x;
    }
    sort(ar+1, ar+n/2+1);
    int odd=0;
   int i,x=1;
    for(i=1;i<=n;i=i+2)
    {
        odd=odd+abs(ar[x++]-i);
    }
    int even=0;
    x=1;
    for(i=2;i<=n;i=i+2)
    {
        even=even+abs(ar[x++]-i);
    }
    cout<<min(odd,even)<<endl;
}
