#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> four, eight, fifteen, sixteen, twntythree, fortytwo;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(x == 4) four.push(i);
        if(x == 8) if(four.size() > eight.size())eight.push(i);
        if(x == 15) if(eight.size() > fifteen.size())fifteen.push(i);
        if(x == 16) if(fifteen.size() > sixteen.size())sixteen.push(i);
        if(x == 23) if(sixteen.size() > twntythree.size())twntythree.push(i);
        if(x == 42) if(twntythree.size() > fortytwo.size())fortytwo.push(i);
    }
    int cnt = n - 6*fortytwo.size();
    cout << cnt << endl;
    return 0;
}

