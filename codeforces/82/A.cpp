#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    n--;

    while(n >= 5)
    {
        n = (n - 5)/2;
    }
    if(n==0)puts("Sheldon");
    else if(n==1)puts("Leonard");
    else if(n==2)puts("Penny");
    else if(n==3)puts("Rajesh");
    else if(n==4)puts("Howard");
    return 0;
}
