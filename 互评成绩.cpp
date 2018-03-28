#include <bits/stdc++.h>

using namespace std;
double a[10005], p[15];

int main()
{
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    for(int i = 0; i < n; i++){
           double sum = 0;
        for(int j = 0; j < k; j++){
            scanf("%lf", &p[j]);
        }
        sort(p, p + k);
        for(int j = 1; j < k - 1; j++){
            sum += p[j];
        }
    sum /= (k - 2);
    a[i] = sum;
    }
    sort(a, a + n);
    for(int i = n - m; i < n; i++){
        if(i == n - m) printf("%.3f", a[i]);
        else printf(" %.3f", a[i]);
    }
    return 0;
}
