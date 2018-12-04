#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{

    //double start_time = clock();
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  #endif

   int x;
   cin >> x;
   int a = x-1;
   int b = 2;
   for(int a = x; a >=  1; a--){
    for(int b = 2; b <= x; b++){
    if(a%b == 0 && (a*b) > x && (a/b) < x){
        cout << a << " " << b << endl;
        return 0;
    }
   }
   } 
   cout << "-1\n";
   return 0;
    
}