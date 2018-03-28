#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[1005];
    gets(a);
    int ans = 0;
    int l = strlen(a);
    for(int i = 0; i < l; i++){
        for(int j = 0; i - j >= 0 && i + j < l; j++){
            if(a[i - j] != a[i + j]) break;
            if(2 * j + 1 > ans) ans = 2 * j + 1;
        }
        for(int j = 0; i - j >= 0 && i + j + 1 < l; j++){
            if(a[i - j] != a[i + j + 1]) break;
            if(2 * j + 2 > ans) ans = 2 * j + 2;
        }
    }
    printf("%d",ans);
    return 0;
}
