#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[10005];
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int f = n / 2, k = n;
    for(int i = 1; i <= n; i++){

    }
    while(f > 0 && a[k] < a[f]){
        swap(a[k], a[f]);
        k = f; f = f / 2;
    }
    for(int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}
