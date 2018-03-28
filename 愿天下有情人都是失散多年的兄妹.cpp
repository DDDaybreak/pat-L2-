#include <bits/stdc++.h>

using namespace std;
int f[100005][2];
char sex[100005];
set<int> Q;
struct node
{
    int num;
    int step;
};
queue<node> P;
int main()
{
    memset(f, -1, sizeof(f));
    int n, a, af, am;
    char asex;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        getchar();
        scanf("%c", &sex[a]);
        scanf("%d%d", &af, &am);
        if(af != -1) {f[a][0] = af; sex[af] = 'M';}
        if(am != -1) {f[a][1] = am; sex[am] = 'F';}
    }
    int k, x, y;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d%d", &x, &y);
        if(sex[x] == sex[y]){
            printf("Never Mind\n");
            continue;
        }
        bool flag = 0;
        Q.clear();
        while(!P.empty()) P.pop();
        node x1, y1;
        x1.num = x, x1.step = 1;
        y1.num = y, y1.step = 1;
        P.push(x1); P.push(y1);
        while(!P.empty()){
            node now = P.front();
            P.pop();
            if(Q.count(now.num) == 1){
                flag = 1; break;
            }
            else Q.insert(now.num);
            node n1, n2;
            n1.num = f[now.num][0]; n1.step = now.step + 1;
            n2.num = f[now.num][1]; n2.step = now.step + 1;
            if(n1.step <= 5 && n1.num != -1) P.push(n1);
            if(n2.step <= 5 && n2.num != -1) P.push(n2);
        }
        if(!flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
/**#include <bits/stdc++.h>

using namespace std;
bool flag = 0;
bool vis[100005];
int f[100005], m[100005];
void dfs(int x, int step, int model)
{
    if(step > 5) return ;
    if(!vis[x] && !model){
        vis[x] = 1;
    }
    if(vis[x] && model){
        flag = 1; return ;
    }
    if(f[x] != -1 && !flag) dfs(f[x], step + 1, model);
    if(m[x] != -1 && !flag) dfs(m[x], step + 1, model);
}
int main()
{
    int n, a;
    char sex[100005], c;
    memset(f, -1, sizeof(f));
    memset(m, -1, sizeof(m));
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %c", &a, &c);
        sex[a] = c;
        scanf("%d%d", &f[a], &m[a]);
        if(f[a] != -1) sex[f[a]] = 'M';
        if(m[a] != -1) sex[m[a]] = 'F';
    }
    int k, x, y;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d%d", &x, &y);
        if(sex[x] == sex[y]){
            printf("Never Mind\n");
            continue;
        }
        memset(vis, 0, sizeof(vis));
        flag = 0;
        dfs(x, 1, 0);
        dfs(y, 1, 1);
        if(!flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}*/
