#include<bits/stdc++.h>
using namespace std;

int ar[100001];

void afk(int k,int d)
{
    int i=0,p=0;
    while(p <= d)
    {
        i++;
        p = i*k;
        ar[p] = 1;
    }
}
void afl(int l, int d)
{
    int i=0,p=0;
    while(p <= d)
    {
        i++;
        p = i*l;
        ar[p] = 1;
    }
}
void afm(int m, int d)
{
    int i=0,p=0;
    while(p <= d)
    {
        i++;
        p = i*m;
        ar[p] = 1;
    }
}
void afn(int n, int d)
{
    int i=0,p=0;
    while(p <= d)
    {
        i++;
        p = i*n;
        ar[p] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k,l,m,n,d,count=0;
    cin>>k>>l>>m>>n>>d;
    afk(k,d);
    afl(l,d);
    afm(m,d);
    afn(n,d);
    for(int i=1; i<=d; i++)
    {
        if(ar[i]==0)count++;
    }

    cout<<d-count<<endl;

}
