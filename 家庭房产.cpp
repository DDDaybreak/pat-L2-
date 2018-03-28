#include <bits/stdc++.h>
using namespace std;
const int maxx = 10005;
struct ren
{
    int f,m;
    int son[10];
    int sonnum;
    int fang;
    int mian;
}w[maxx];
struct jia
{
    int num;
    int minno;
    double fang;
    double mian;
}na[maxx];
int vis[maxx], dvis[maxx], f[maxx], num, fang, mian, minno, jz[maxx];
int cmp(jia a, jia b)
{
    if(a.mian != b.mian) return a.mian > b.mian;
    return a.minno < b.minno;
}
int find(int x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x != y) f[y] = x;
}
void dfs(int i)
{
    if(dvis[i] || i == -1) return;
    if(i < minno) minno = i;
    num ++;
    dvis[i] = 1;
    if(jz[i]){
        fang += w[i].fang;
        mian += w[i].mian;
        dfs(w[i].f);
        dfs(w[i].m);
        for(int j = 0; j < w[i].sonnum; j++)
            dfs(w[i].son[j]);
    }
}
int main()
{
    memset(jz, 0, sizeof(jz));
    int n, a, b, c, k, cnn = 0;
    cin >> n;
    for(int i = 0; i < maxx; i++) f[i] = i;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        jz[a] = 1;
        w[a].f = b;
        w[a].m = c;
        if(b != -1){vis[b] = 1; merge(a, b);}
        if(c != -1){vis[c] = 1; merge(a, c);}
        cin >> k;
        w[a].sonnum = k;
        vis[a] = 1;
        for(int j = 0; j < k; j++){
            cin >> w[a].son[j];
            vis[w[a].son[j]] = 1;
            merge(a, w[a].son[j]);
        }
        cin >> w[a].fang >> w[a].mian;
    }
    int sum = 0;
    int ans[maxx], cnt = 0;
    for(int i = 0; i < maxx; i++){
        if(f[i] == i && vis[i]){
            sum++;
            ans[cnt++] = i;
        }
    }
    printf("%d\n", sum);
    memset(dvis, 0, sizeof(dvis));
    for(int i = 0; i < cnt; i++){
        mian = fang = num = 0;
        minno = 20000;

        int ff = find(ans[i]);
        for(int j = 0; j < maxx; j++){
            if(find(j) == ff) dfs(j);
        }
        na[cnn].minno = minno;
        na[cnn].num = num;
        na[cnn].fang = fang * 1.0 / num;
        na[cnn++].mian = mian * 1.0 / num;
    }
    sort(na, na + cnt, cmp);
    for(int i = 0; i < cnt; i++)
        printf("%04d %d %.3f %.3f\n",na[i].minno, na[i].num, na[i].fang, na[i].mian);
    return 0;
}
