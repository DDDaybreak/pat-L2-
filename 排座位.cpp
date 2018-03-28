#include <bits/stdc++.h>

using namespace std;
int f[105];
int d[105][105];
int findd(int x)
{
    return f[x] == x ? x : f[x] = findd(f[x]);
}
int merge(int x, int y)
{
    x = findd(x);
    y = findd(y);
    if(x != y) f[x] = y;
}
int main()
{
    int n, m, k;
    int a, b, c;
    memset(d, 0, sizeof(d));
    for(int i = 0; i < 105; i++)
        f[i] = i;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        if(c == -1){
            d[a][b] = 1;
            d[b][a] = 1;
        }
        else{
            merge(a, b);
        }
    }
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        if(findd(a) == findd(b) && d[a][b] == 0) printf("No problem\n");
        else if(findd(a) != findd(b) && d[a][b] == 0) printf("OK\n");
        else if(findd(a) == findd(b) && d[a][b] == 1) printf("OK but...\n");
        else if(findd(a) != findd(b) && d[a][b] == 1) printf("No way\n");
    }
    return 0;
}
