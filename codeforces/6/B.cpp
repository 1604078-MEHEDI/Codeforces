#include<bits/stdc++.h>
using namespace std;
char ck [101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int n,m;
    char c;
    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> ck[i][j];
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(ck[i][j] == '.')continue;
            if(ck[i][j] == c)
            {
                if(ck[i][j+1] >= 'A' && ck[i][j+1] <= 'Z' && ck[i][j+1] != c)
                {
                    cnt++;
                    char test = ck[i][j+1];
                    for(int i = 1; i <= n; i++)
                    {
                        for(int j = 1; j <= m; j++)
                        {
                            if(ck[i][j] == '.')continue;
                            if(test == ck[i][j])ck[i][j] = '.';
                        }
                    }

//                 if(test == ck[i][j-1])ck[i][j-1] = '.';
//                 if(test == ck[i-1][j])ck[i-1][j] = '.';
//                 if(test == ck[i+1][j])ck[i+1][j] = '.';
                }
                if(ck[i][j-1] >= 'A' && ck[i][j-1] <= 'Z' && ck[i][j-1] != c)
                {
                    cnt++;
                    char test = ck[i][j-1];
                    for(int i = 1; i <= n; i++)
                    {
                        for(int j = 1; j <= m; j++)
                        {
                            if(ck[i][j] == '.')continue;
                            if(test == ck[i][j])ck[i][j] = '.';
                        }
                    }
//                        if( test == ck[i][j+1])ck[i][j+1] = '.';
//                        if(test == ck[i-1][j] )ck[i-1][j] = '.';
//                        if(test == ck[i+1][j])ck[i+1][j] = '.';
                }
                if(ck[i-1][j] >= 'A' && ck[i-1][j] <= 'Z' && ck[i-1][j] != c)
                {
                    cnt++;
                    char test = ck[i-1][j];
                    for(int i = 1; i <= n; i++)
                    {
                        for(int j = 1; j <= m; j++)
                        {
                            if(ck[i][j] == '.')continue;
                            if(test == ck[i][j])ck[i][j] = '.';
                        }
                    }
//                        if(test == ck[i][j-1] )ck[i][j-1] = '.';
//                        if(test == ck[i][j+1])ck[i][j+1] = '.';
//                        if(test == ck[i+1][j])ck[i+1][j] = '.';
                }
                if(ck[i+1][j] >= 'A' && ck[i+1][j] <= 'Z' && ck[i+1][j] != c)
                {
                    cnt++;
                    char test = ck[i+1][j];
                    for(int i = 1; i <= n; i++)
                    {
                        for(int j = 1; j <= m; j++)
                        {
                            if(ck[i][j] == '.')continue;
                            if(test == ck[i][j])ck[i][j] = '.';
                        }
                    }
//                        if(test == ck[i][j-1] )ck[i][j-1] = '.';
//                        if(test == ck[i-1][j] )ck[i-1][j] = '.';
//                        if(test == ck[i][j+1])ck[i][j+1] = '.';
                }
                //cout<<ck[i][j];
            }
        }
        //cout<<endl;
    }
    cout<<cnt<<endl;
    return 0;
}
