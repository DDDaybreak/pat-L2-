#include <bits/stdc++.h>

using namespace std;
int f[100005];
int rankk[100005];
int n, k, s, bb;
double z, r, sum;
vector<int> Q, P;
vector<int> A[100005];
bool vis[100005];
void BFS()
{
    memset(vis, 0, sizeof(vis));
    queue<int>l;
    l.push(0);
    vis[0] = 1;
    while(!l.empty()){
        int a = l.front();
        l.pop();
        if(a != 0) rankk[a] = rankk[f[a]] + 1;
        int ll = A[a].size();
        for(int j = 0; j < ll; j++){
            if(!vis[A[a][j]] && A[a][j] <= n) {l.push(A[a][j]); vis[A[a][j]] = 1;}
        }
    }
}
int main()
{
    Q.clear();P.clear();
    for(int i = 0; i < 100005; i++){
        f[i] = i;rankk[i] = 0;
    }
    scanf("%d%lf%lf", &n, &z, &r);
    sum = z;
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        if(k == 0){
        Q.push_back(i);
        scanf("%d", &bb);
        P.push_back(bb);
        continue;
    }
        for(int j = 0; j < k; j++){
            int d;
            scanf("%d", &d);
            A[i].push_back(d);
            f[d] = i;
        }
    }
    BFS();
    double ans = 0;
    int l = Q.size();
    for(int i = 0; i < l; i++){
            sum = z;
        int b1 = rankk[Q[i]] ;
        while(b1--){
            sum = sum *(1 - 0.01 * r);
        }
        ans += sum * P[i];
    }
    printf("%d", (int)ans);
    return 0;
}
