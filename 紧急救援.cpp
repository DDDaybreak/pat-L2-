#include <bits/stdc++.h>

using namespace std;
const int maxx = 505;
int INF = 0x3f3f3f3f;
int arr[505][505], people[505], human[505], road[505], last[505], d[505];
bool vis[505];
int main()
{
    int n, m, s, dt;
    cin >> n >> m >> s >> dt;
    fill(d, d + maxx, INF);
    fill(vis, vis + maxx, 0);
    ///memset(vis, 0, sizeof(vis));
    memset(arr, -1, sizeof(arr));
    for(int i = 0; i < n; i++){
        int aa;
        cin >> aa;
        people[i] = aa;
        human[i] = aa;
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = c;
        arr[b][a] = c;
    }
    road[s] = 1;
    last[s] = -1;
    d[s] = 0;
    while(true){
        int u = -1;
        for(int i =0; i < n; i++){
            if(!vis[i] && (u == -1 || d[i] < d[u])) u = i;
        }
        if(u == -1) break;
        vis[u] = true;
        for(int i = 0; i < n; i++){
            if(arr[i][u] != -1){
            if(d[u] + arr[u][i] < d[i]){
                d[i] = d[u] + arr[u][i];
                human[i] = human[u] + people[i];
                last[i] = u;
                road[i] = road[u];
            }
            else if(d[u] + arr[u][i] == d[i]){
                if(human[i] < human[u] + people[i]){
                    human[i] = human[u] + people[i];
                    last[i] = u;
                }
                road[i] += road[u];
            }
        }
        }
    }
    printf("%d %d\n",road[dt], human[dt]);
    return 0;
}
