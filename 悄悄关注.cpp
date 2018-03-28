#include <bits/stdc++.h>

using namespace std;
set<string>Q;
map<string, int>m;
int main()
{
    int n, b;
    string a;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        cin >> a;
        Q.insert(a);
    }
    scanf("%d", &n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        m[a] = b;
        sum += b;
    }
    map<string, int> :: iterator it;
    int N = 0;
    sum = sum / n;
    for(it = m.begin(); it != m.end(); it++){
        if(it->second > sum && Q.count(it->first) == 0){
            cout << it->first << endl;
            N++;
        }
    }
    if(N == 0) printf("Bing Mei You\n");
    return 0;
}
