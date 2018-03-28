#include <bits/stdc++.h>

using namespace std;
int f[505], a[5005], b[5005];
bool vis[505];
int findd(int x)
{
    return f[x] == x ? x : f[x] = findd(f[x]);
}
void merge(int x, int y)
{
    x = findd(x);
    y = findd(y);
    if(x != y) f[x] = y;
}
int main()
{
    memset(vis, 0, sizeof(vis));
    int n, m, sum = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        f[i] = i;
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        merge(a[i], b[i]);
    }
    for(int i = 0; i < n; i++){
        if(f[i] == i) sum ++;
    }
    int k, q;
    cin >> k;
    for(int i = 0; i < k; i++){
            int ans1 = 0;
        cin >> q;
        vis[q] = 1;
        for(int j = 0; j < n; j++)
            f[j] = j;
        for(int j = 0; j < n; j++){
            if(!vis[a[j]] && !vis[b[j]]) merge(a[j], b[j]);
        }
        for(int j = 0; j < n; j++){
            if(f[j] == j && !vis[j]) ans1 ++;
        }
        if(ans1 <= sum) printf("City %d is lost.\n", q);
        else printf("Red Alert: City %d is lost!\n", q);
        sum = ans1;
    }
    sum = 0;
    for(int j = 0; j < n; j++){
        if(vis[j]) sum++;
    }
    if(sum == n) printf("Game Over.\n");
    return 0;
}
