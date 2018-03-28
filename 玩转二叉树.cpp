#include <bits/stdc++.h>

using namespace std;
struct node
{
    int date;
    node *l, *r;
};
int qian[40];
int zhong[40];
node * creat(int qianl, int qianr, int zhongl, int zhongr)
{
    if(qianl > qianr) return NULL;
    int i = 0;
    while(zhong[i] != qian[qianl]) i++;
    node *now = new node;
    now->date = qian[qianl];
    now->l = now->r = NULL;
    now->l = creat(qianl + 1, qianl + i - zhongl, zhongl, i - 1);
    now->r = creat(qianl + i - zhongl + 1, qianr, i + 1, zhongr);
    return now;
}
void zhuan(node * r)
{
    if(!r) return;
    node * z = new node;
    z = r->l;
    r->l = r->r;
    r->r = z;
    zhuan(r->l);
    zhuan(r->r);
}
void bfs(node *root)
{
    queue <node *>Q;
    while(!Q.empty()) Q.pop();
    Q.push(root);
    int i = 0;
    while(!Q.empty()){
        node *now = Q.front();
        Q.pop();
        if(i == 0) printf("%d",now->date);
        else printf(" %d",now->date);
        if(now->l) Q.push(now->l);
        if(now->r) Q.push(now->r);
        i++;
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> zhong[i];
    for(int i = 0; i < n; i++)
        cin >> qian[i];
    node * root = creat(0, n - 1, 0, n - 1);
    zhuan(root);
    bfs(root);
    return 0;
}
