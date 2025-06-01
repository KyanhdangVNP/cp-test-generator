#include <bits/stdc++.h>
#define boostcode ios_base::sync_with_stdio(0); cin.tie(0);
#define openf freopen("BAI2.INP", "r", stdin); freopen("BAI2.OUT", "w", stdout);

using namespace std;
typedef long long ll;

// 1 <= n <= 200
// 1 <= m[i] <= 10^6
// 1 <= t[i] <= 10^4
int n;
int b[10002];
int pos[10002];
ll res;
bool d[202];
queue<int> out; // Lưu những công việc ưu tiên làm trước

int main() {
    boostcode;
    openf;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t, m;
        cin >> t >> m;
        if (m > b[t]) {
            b[t] = m;
            pos[t] = i;
        }
    }
    for (int i = 1; i <= 10000; i++) {
        res += b[i];
        d[pos[i]] = true;
        if (pos[i]) out.push(pos[i]);
        //cout << i << ' ' << b[i] << ' ' << pos[i] << '\n';
    }
    while (out.size()) {
        cout << out.front() << '\n';
        out.pop();
    }
    for (int i = 1; i <= n; i++) {
        if (!d[i]) cout << i << '\n';
    }
    cout << res;

    return 0;
}
/* Test:
4
1 15
3 10
5 100
1 27
=>
4
2
3
1
137
Another test:
4
1 1
1 999
1 1
1 1
=>
2
1
3
4
999
*/
