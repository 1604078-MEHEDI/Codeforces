#include <bits/stdc++.h>
using namespace std;
int a[101],t=0;

// Function to print the divisors
void Divisors(int n)
{
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                a[t++] = i;
               // printf("%d ", i);

            else {// Otherwise print both
                a[t++] = i;
                a[t++] = n/i;
                //printf("%d %d ", i, n/i);
            }
        }
    }
    //cout<<endl;
}

/* Driver program to test above function */
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    cin >> n >> s;
    Divisors(n);
    sort(a, a+t);
//    for(int i = t-1; i >= 0; i--){
//            cout<<a[i]<<" ";}
//            cout<<endl;
    for(int i = 0; i < t; i++){
        int p = n - a[i];//cout<<" --"<<p<<endl;
	reverse(s.begin(), s.end() - p);
	//cout<<s<<endl;
}
cout<<s<<endl;
    return 0;
}
