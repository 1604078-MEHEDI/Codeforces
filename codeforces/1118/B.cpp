#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long a[maxn];
long long odd[maxn], even[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;
    long od = 0, ev = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(i&1)
        {
            od += a[i];
            odd[i] += od;
            even[i] = ev;
        }
        else
        {
            ev += a[i];
            even[i] += ev;
            odd[i] += od;
        }
    }
    /*for(int i = 1; i <= n; i++)
    {
        cout << odd[i] << " ";
    }
    cout << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << even[i] << " ";
    }
    cout << endl;*/
    long long odd_sum, even_sum;
    int cnt = 0;
    if(n&1)
    {
        even_sum = odd[n] - odd[1];
        odd_sum = even[n-1];
       // cout << odd_sum << " "<<even_sum<<endl;
        if(even_sum == odd_sum)cnt++;
    }
    else
    {
        odd_sum = even[n];
        even_sum = odd[n-1] - odd[1];
        if(even_sum == odd_sum)cnt++;
    }
    //cout << odd_sum << " "<<even_sum<<endl;
    for(int i = 2; i <= n; i++)
    {
        odd_sum = 0;
        even_sum = 0;
        if(i&1)
        {
            even_sum = even[i-1];
            odd_sum = odd[i-1];
           // cout << odd_sum << " "<<even_sum<<endl;
            if(n&1)
            {
                even_sum += odd[n] - odd[i];
                odd_sum += even[n-1] - even[i];
                 //cout << odd_sum << " "<<even_sum<<endl;
                if(even_sum == odd_sum)cnt++;
            }
            else
            {
                odd_sum += even[n] - even[i];
                even_sum += odd[n-1] - odd[i];
                // cout << odd_sum << " "<<even_sum<<endl;
                if(even_sum == odd_sum)cnt++;
            }
        }
        else
        {
            odd_sum = odd[i-1];
            even_sum = even[i-1];
            //cout << odd_sum << " ------- "<<even_sum<<endl;
             if(n&1)
            {
                even_sum += odd[n] - odd[i];
                odd_sum += even[n-1] - even[i];
               //  cout << odd_sum << " ------------ "<<even_sum<<endl;
                if(even_sum == odd_sum)cnt++;
            }
            else
            {
                odd_sum += even[n] - even[i];
                even_sum += odd[n-1] - odd[i];
                 //cout << odd_sum << " ----------------- "<<even_sum<<endl;
                if(even_sum == odd_sum)cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
