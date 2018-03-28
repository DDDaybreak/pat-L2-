#include <bits/stdc++.h>

using namespace std;
struct node
{
    int addr;
    int date;
    int next;
}f[100005];
vector<node>f1, f2;
int main()
{
    int st, n;
    f2.clear();
    cin >> st >> n;
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        f[a].date = b;
        f[a].next = c;
        f[a].addr = a;
    }
    for(int i = st; i != -1; i = f[i].next){
        f1.push_back(f[i]);
    }
    int l = 0;
    if(n % 2 == 0){
        for(int i = n - 1, j = 0; i >= (n + 1) / 2; i--, j++){
            if(i != j){
            f2.push_back(f1[i]);
            f2.push_back(f1[j]);
            }
            else f2.push_back(f1[i]);
        }
    }
    else {
        for(int i = n - 1, j = 0; ;i--, j++){
            if(i != j){
                f2.push_back(f1[i]);
                f2.push_back(f1[j]);
            }
            else {
                 f2.push_back(f1[i]);break;
            }
        }
    }
    for(int i = 0; i < n - 1; i++){
        printf("%05d %d %05d\n", f2[i].addr, f2[i].date, f2[i + 1].addr);
    }
    printf("%05d %d -1\n", f2[n - 1].addr, f2[n - 1].date);
    return 0;
}
