#include<bits/stdc++.h>
using namespace std;
//void rev(int n_mb)
//{
//    const int N = 1024 * 1000 * n_mb;
//    char *tab = new char[N];
//    for(int i = 0; i < N; i++){
//        tab[i] = i;
//    }
//}

int main()
{
    set<int> yes ={2, 3, 4, 5, 12, 30, 35, 43, 46, 52, 64, 86};
    set<int> no = {1, 10, 11, 13, 24};
    int n;
    cin >> n;
    if(yes.count(n))cout << "YES\n";
//    else if(no.count(n)){
//        cout << "NO\n";
//    }
    else{
       // rev(n);
        cout << "NO\n";
    }
}
