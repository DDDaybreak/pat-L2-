#include <bits/stdc++.h>

using namespace std;
struct node
{
   int num;
   char name[10];
   double adj;
}w[105];
set<int>Q;
int cmp(node a, node b)
{
    if(a.num != b.num) return a.num > b.num;
    return a.adj < b.adj;
}
int main()
{
    int n, k, z, sum, su;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        Q.clear();sum = 0; su = 1;
        cin >> w[i].name;
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
           scanf("%d", &z);
           Q.insert(z);
        }
        w[i].num = Q.size();
        w[i].adj = (double)k / (double)Q.size();
    }
    sort(w, w + n, cmp);
    for(int i = 0; i < min(3, n); i++){
       if(i == 0) printf("%s", w[i].name);
       else printf(" %s", w[i].name);
    }
    if(n < 3){
       for(int i = 0; i < 3 - n; i++){
          printf(" -");
       }
    }
    return 0;
}
