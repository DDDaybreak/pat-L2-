/**#include <bits/stdc++.h>

using namespace std;
int INF = 0x3f3f3f3f;
int a[50005];
int main()
{
    int n;
    int q, cnt = 0;
    memset(a, INF, sizeof(a));
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> q;
        if(cnt == 0 || a[cnt - 1] < q){
            a[cnt++] = q;continue;
        }
        int qian = 0, hou = cnt;
        while(hou - qian > 1){
            int mid = (qian + hou) / 2;
            if(a[mid] > q) hou = mid;
            if(a[mid] < q) qian = mid;
        }
        if(a[qian] > q) a[qian] = q;
        else a[hou] = q;
    }
    printf("%d", cnt);
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int>Q;
    Q.clear();
    int n, t;
    scanf("%d", &n);
    set<int>::iterator it;
    for(int i = 0; i < n; i++){
        scanf("%d", &t);
        if(i == 0) Q.insert(t);
        else{
            it = Q.lower_bound(t);
            if(it == Q.end()) Q.insert(t);
            else{
                Q.erase(it);
                Q.insert(t);
            }
        }
    }
    printf("%d", Q.size());
    return 0;
}
