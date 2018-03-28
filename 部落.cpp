#include <bits/stdc++.h>

using namespace std;
int f[10005];
set<int>Q;
int findd(int x)
{
    return x == f[x] ? x : f[x] = findd(f[x]);
}
void merge(int x, int y)
{
    x = findd(x);
    y = findd(y);
    if(x != y) f[x] = y;
}
int main()
{
    for(int i = 0; i < 10005; i++) f[i] = i;
    int n, k, d1, d;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
            if(j == 0){
                scanf("%d", &d1);
                Q.insert(d1);
            }
            else {
                scanf("%d", &d);
                merge(d1, d);
                Q.insert(d);
            }
        }
    }
    int a, b, num = 0, N;
    set<int>::iterator it;

    for(it = Q.begin(); it != Q.end(); it++){
        if(f[*it] == *it) num ++;
        ///printf("%d %d\n", f[*it], *it);
    }
    printf("%d %d\n", Q.size(), num);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d%d", &a, &b);
        if(findd(a) == findd(b)) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
