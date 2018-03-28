#include <bits/stdc++.h>

using namespace std;
struct bing
{
    double kucun;
    double jiaqian;
    double junjia;
};
int cmp(bing a, bing b)
{
    return a.junjia > b.junjia;
}
int main()
{
    int n;
    double maxx;
    cin >> n >> maxx;
    struct bing a[1005];
    for(int i = 0; i < n; i++){
        cin >> a[i].kucun;
    }
    for(int i = 0; i < n; i++){
        cin >> a[i].jiaqian;
        a[i].junjia = a[i].jiaqian / a[i].kucun;
        ///printf("%.2f ",a[i].junjia);
    }
    sort(a, a+n, cmp);
    double ans = 0;
    for(int i = 0; i < n; i++){
            if(maxx == 0) break;
        if(a[i].kucun > maxx){
            ans += maxx * a[i].junjia;
            maxx = 0;
        }
        else{
            ans += a[i].jiaqian;
            maxx -= a[i].kucun;
        }
    }
    printf("%.2f",ans);
    return 0;
}
