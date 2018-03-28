#include <bits/stdc++.h>

using namespace std;

struct node
{
    int date;
    struct node * l;
    struct node * r;
};
int zhong[35], hou[35];
int n;
struct node * f(int zhongl, int zhongr, int houl, int hour)
{
    if(houl > hour) return NULL;
    node * w = new node;
    w->date = hou[hour];
    w->l = NULL;
    w->r = NULL;
    int i = 0;
    while(zhong[i] != hou[hour]) i++;
    w->l = f(zhongl, i - 1, houl, houl + i - zhongl - 1);
    w->r = f(i + 1, zhongr, houl + i - zhongl, hour - 1);
    return w;
}
void BFS(struct node * root)
{
    queue<node *> Q;
    int i = 0;
    Q.push(root);
    while(!Q.empty()){
        struct node * a = Q.front();
        Q.pop();
        if(i == 0) printf("%d",a->date);
        else printf(" %d",a->date);
        if(a->l) Q.push(a->l);
        if(a->r) Q.push(a->r);
        i++;
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> hou[i];
    for(int i = 0; i < n; i++)
        cin >> zhong[i];
    node * root = f(0, n - 1, 0, n - 1);
    BFS(root);
    return 0;
}
