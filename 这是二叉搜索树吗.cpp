#include <bits/stdc++.h>

using namespace std;
struct node
{
    int v;
    node *l;
    node *r;
    node(int v):v(v),l(NULL),r(NULL){}
};
int a[1005], z[1005], k =0;
bool flag1 = true, flag2 = true, p = false;
void build(node * &rt, int a)
{
    if(!rt){
        rt = new node(a);
        return;
    }
    if(a < rt->v) build(rt->l, a);
    else build(rt->r, a);
}
void zhong1(node *rt)
{
    if(a[k++] != rt->v) flag1 = 0;
    if(!flag1) return;
    if(rt->l) zhong1(rt->l);
    if(rt->r) zhong1(rt->r);
}
void zhong2(node *rt)
{
    if(a[k++] != rt->v) flag2 = 0;
    if(!flag2) return;
    if(rt->r) zhong2(rt->r);
    if(rt->l) zhong2(rt->l);
}
void print1(node * &rt)
{
    if(!rt) return;
    else{
    print1(rt->l);
    print1(rt->r);
    if(!p){
        printf("%d",rt->v);
        p = 1;
    }
    else printf(" %d",rt->v);
    }
}
void print2(node * &rt)
{
    if(!rt) return;
    else{
    print2(rt->r);
    print2(rt->l);
    if(!p){
        printf("%d",rt->v);
        p = 1;
    }
    else printf(" %d",rt->v);
    }
}
int main()
{
    node *root = NULL;
    int n,nn;
    cin >> n;
    for(int i =0 ;i < n; i++){
        cin >> a[i];
        build(root, a[i]);
    }
    zhong1(root);
    k = 0;
    zhong2(root);
    if(flag1){
        printf("YES\n");
        print1(root);
        return 0;
    }
    if(flag2){
        printf("YES\n");
        print2(root);
        return 0;
    }
    printf("NO\n");
    return 0;
}
/**#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int v;
    node* left;
    node* right;
    node(int v):v(v),left(NULL),right(NULL){}
};

int k = 0, flag1 = 0, flag2 = 0, pflag = 0, n, a[1010];;

void build(node* &root, int v)
{
    if(root == NULL)
    {
        root = new node(v);
        return;
    }
    if(v < root->v) build(root->left, v);
    else build(root->right, v);
}

void preOrder(node* rt)
{
    if(a[k++] != rt->v) flag1 = 1;
    if(flag1) return;
    if(rt->left) preOrder(rt->left);
    if(rt->right) preOrder(rt->right);
}

void preOrder2(node* rt)
{
    if(a[k++] != rt->v) flag2 = 1;
    if(flag2) return;
    if(rt->right) preOrder2(rt->right);
    if(rt->left) preOrder2(rt->left);
}

void print(node* rt)
{
    if(rt->left) print(rt->left);
    if(rt->right) print(rt->right);
    if(!pflag) {printf("%d", rt->v);pflag = 1;}
    else printf(" %d", rt->v);
}

void print2(node* rt)
{
    if(rt->right) print2(rt->right);
    if(rt->left) print2(rt->left);
    if(!pflag) {printf("%d", rt->v);pflag = 1;}
    else printf(" %d", rt->v);
}


int main()
{
    node *root = NULL;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        build(root, a[i]);
    }
    preOrder(root);
    k = 0;
    preOrder2(root);
    if(!flag1 || !flag2)
    {
        printf("YES\n");
        if(!flag1) print(root);
        else print2(root);
        printf("\n");
    }
    else printf("NO\n");
    return 0;
}*/
