#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int a;
        cin >> a;
        int b = 0;
        bool flag = false;
        for(int  j = 0; j < 31; j++){
                int x = 1 <<j;
                if(x < a){
                    if(!(x&a)){
                            flag = true;
                        b += x;
                    }
                }
                else break;
        }
        if(flag)
        cout <<__gcd((a^b), (a&b))<<endl;
        else
            {
                int ans = 1;
                for(int i = 2; i <= sqrt(a); i++){
                    if(a%i == 0)
                    {
                        ans = (a/i);
                        break;
                    }
                }
                cout << ans <<endl;
            }
    }
    return 0;
}
