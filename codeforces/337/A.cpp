#include<bits/stdc++.h>
using namespace std;
int ar[10001];

int main()
{
    int n,m,p=10000,x,q;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++)
    {
        scanf("%d", &ar[i]);
    }
    sort(ar, ar+m);

    for(int i=0; i<m-1; i++)
    {
        q = n+i-1;
        x = ar[q] - ar[i];
        //cout<<"X "<<x<<" = "<<ar[q]<<" -"<<ar[i]<<"// I & Q "<<i<<" "<<q<<endl;
       // cout<<x<<endl;
        if(q>=m)break;
        if(p>x)p = x;
    }

    printf("%d", p);
}
