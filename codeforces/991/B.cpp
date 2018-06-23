#include<bits/stdc++.h>
using namespace std;
int ar[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,j=0;
    cin >> n;
    double sum = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a != 5)ar[j++] = a;
        sum += a;
    }
    sort(ar, ar+j);
    int cnt = 0,k=0;
    while(1){
        double res = round(sum/n); //cout<<"--"<<res<<endl;
        if(res == 5){
            cout<<cnt<<endl;
            return 0;
        }
        else
        {
            if(ar[k] != 5){
                sum += 5 - ar[k];
                k++;
                    cnt++;
            }
            else break;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
