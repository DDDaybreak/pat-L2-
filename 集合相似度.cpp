#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;
    int x, y;
    vector<int> a[55];
    set<int> b[55];
    set<int> Q;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> m;
        a[i].clear();
        b[i].clear();
        for(int j = 0; j < m; j++){
            cin >> k;
            a[i].push_back(k);
            b[i].insert(k);
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        int num = 0;
        int size1 = b[x].size();
        int size2 = b[y].size();
        set<int> ::iterator it;
        for(it = b[x].begin(); it != b[x].end(); it++){
            if(b[y].count(*it) == 1) num++;
        }
        int nc = num;
        int nt = size1 + size2 - num;
        double lv = (nc*1.0) / (nt*1.0) * 100;
        printf("%.2f%%\n",lv);
    }
    return 0;
}
