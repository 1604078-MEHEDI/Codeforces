#include<bits/stdc++.h>
using namespace std;

struct node
{
    int a , b;
} ar[30];

int cmp (node a, node b)
{
    return a.b > b.b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,sum;
    cin >> n >> m;
        for(i = 0; i < m; i++)cin >> ar[i].a >> ar[i].b;
        sort(ar, ar+m, cmp);
//        cout<<"after sort\n";
//        for(i = 0; i < m; i++){
//            cout<<ar[i].a <<" "<<ar[i].b<<endl;
//        }
        sum = 0;
        for(i = 0; i < m; i++){
            if(ar[i].a >= n){
                sum += n*ar[i].b;
                break;
            }
            else{
                sum += ar[i].a * ar[i].b;
                n -= ar[i].a;
            }
        }
        cout<<sum<<endl;
    return 0;
}
