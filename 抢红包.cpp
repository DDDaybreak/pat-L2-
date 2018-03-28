#include <bits/stdc++.h>

using namespace std;
struct ren
{
    int num;
    int val;
    int numhongbao;
};
int cmp(ren a, ren b)
{
    if(a.val != b.val) return a.val > b.val;
    if(a.numhongbao != b.numhongbao) return a.numhongbao > b.numhongbao;
        return a.num < b.num;
}
int main()
{
    ren w[10005];
    for(int i = 0; i < 10005; i++){
        w[i].numhongbao = 0;
        w[i].num = i;
        w[i].val = 0;
    }
    int n, N;
    cin >> n;
    N = n;
    for(int i = 1; i <= n; i++){
        int vis[10005] = {0};
        int nu, sum = 0, k, ave;
        cin >> nu;
        for(int j = 0; j < nu; j++){
            cin >> k >> ave;
            if(vis[k] == 1) continue;
            vis[k] = 1;
            w[i].val -= ave; w[k].val += ave; w[k].numhongbao++;
        }
    }
    sort(w + 1, w + n + 1, cmp);
    for(int i = 1; i <= n; i++){
        printf("%d %.2f\n", w[i].num, w[i].val / 100.0);
    }
    return 0;
}
