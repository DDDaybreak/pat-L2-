#include <bits/stdc++.h>

using namespace std;

struct node
{
    int v;
    int next;
}w[100005];
struct node2
{
    int addr;
    int v;
}del[100005];

int num=1;
bool vis[100005];
int T, n, st, tst, v, tnext;

void fun(int pre, int s)
{
    int f = 0;
    if(s == -1) return ;
    if(!vis[abs(w[s].v)]){
        vis[abs(w[s].v)] = 1;
    }
    else{
        w[pre].next = w[s].next;
        del[num].addr = s;
        del[num].v = w[s].v;
        f = 1;num++;
    }
    if(f) fun(pre,w[s].next);
    else fun(s,w[s].next);
}

void print(int s)
{
    if(s == -1) return ;
    if(w[s].next == -1) printf("%05d %d %d\n", s, w[s].v, w[s].next);
    else printf("%05d %d %05d\n", s, w[s].v, w[s].next);
    print(w[s].next);
}

void pdel()
{
    for(int i = 1; i < num - 1; i++){
        printf("%05d %d %05d\n", del[i].addr, del[i].v, del[i+1].addr);
    }
    printf("%05d %d -1\n", del[num-1].addr, del[num-1].v);
}

int main()
{
    memset(vis, 0, sizeof(vis));
    scanf("%d%d", &st, &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &tst, &v, &tnext);
        w[tst].v=v;
        w[tst].next=tnext;
    }
    fun(-1, st);
    print(st);
    if(num > 1) pdel();
    return 0;
}
