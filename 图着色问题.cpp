#include <bits/stdc++.h>

using namespace std;
struct node
{
    int x, y;
};
vector<node>p;
set<int> q;
int vis[505];
int main()
{
    p.clear();
    int v, e, k, a, b;
    scanf("%d%d%d", &v, &e, &k);
    for(int i = 0; i < e; i++){
        scanf("%d%d", &a, &b);
        node now;
        now.x = a; now.y = b;
        p.push_back(now);
    }
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        bool flag = 0; q.clear();
        for(int j = 1; j <= v; j ++){
            int s;
            scanf("%d", &s);
            q.insert(s);
            vis[j] = s;
        }
        if(q.size() != k){
            printf("No\n"); continue;
        }
        for(int j = 0; j < e; j++){
            if(vis[p[j].x] == vis[p[j].y]){
                flag = 1;break;
            }
        }
        if(flag) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
