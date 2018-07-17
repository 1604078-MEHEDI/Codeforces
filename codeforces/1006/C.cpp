#include<bits/stdc++.h>
using namespace std;
long long a[1234567];//,sum1[12345],sum3[12345];
////vector<pair<int, int> > v;
//stack<int>st;
//queue<int>q;
//map<long long, long long>m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int n;
    cin >> n;
    long long sum1 = 0,sum3 = 0,sum=0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    long long ans = 0,j = n - 1,k=0;
    for(int i = 0; i <= n; i++){
       // if(j <= 0 || k > n-1)break;
           // cout<<sum1 <<" "<<sum3<<endl;
         //  if(sum1 *2 > sum || sum3 *2 > sum)break;
            if(sum1 > sum3){
                sum3 += a[j];
                j--;
            }
            else if(sum1 < sum3){
                sum1 += a[k];
                k++;
            }
            else if(sum1 == sum3 && sum >= 2*sum1){
                ans = max(ans, sum1);
                if(a[k] > a[j]){
                    sum3 += a[j];
                    j--;
                }
                else if(a[k] < a[j]){
                    sum1 += a[k];
                    k++;
                }
                else if(a[k] == a[j]){
                     sum3 += a[j];
                    j--;
                    sum1 += a[k];
                    k++;
                }
            }
    }
    cout<<ans<<endl;
    return 0;
}
