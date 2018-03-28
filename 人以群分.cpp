#include <bits/stdc++.h>

using namespace std;
int a[100005];
int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a, a + n);
    int sum1 = 0;
    for(int i = 0; i < n / 2; i++){
        sum1 += a[i];
    }
    printf("Outgoing #: %d\n", n - n / 2);
    printf("Introverted #: %d\n", n / 2);
    printf("Diff = %d\n", sum - 2 * sum1);
    return 0;
}
