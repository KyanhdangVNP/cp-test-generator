#include <bits/stdc++.h>
#define boostcode ios_base::sync_with_stdio(0); cin.tie(0);
#define openf freopen("BAI2.inp", "r", stdin); freopen("BAI2.ans", "w", stdout);

// Nguồn: https://chvoj.edu.vn/problem/python_xepviec

using namespace std;
typedef long long ll;

int n;
pair<pair<int, int>, int> a[100002];
int p[100002];
ll f[100002][2];
// f[i][1]: Max kết quả khi có chọn việc làm thứ i
// f[i][0]: Max kết quả khi không chọn việc làm thứ i
int vet[100002][2]; // Để truy vết thứ tự công việc được chọn
// vet[i][1]: Có chọn việc làm thứ i
// vet[i][0]: Không chọn việc làm thứ i
bool d[100002]; // Để đánh dấu công việc hoàn thành đúng hạn
queue<int> out;

int main() {
    boostcode;
    openf;

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first.first >> a[i].first.second;
    for (int i = 1 ; i <= n; i++) a[i].second = i;
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++) {
        int j = lower_bound(a+1, a+i+1, make_pair(make_pair(a[i].first.first, -1), -1))-a-1;
        p[i] = j;
        //cout << i << ' ' << a[i].first.first << ' ' << a[i].first.second << '|' << j << '\n';
    }
    // Nhận xét: Với mỗi i:
    // - Nếu chọn việc thứ i thì f[i] = f[p[i]] + a[i].first
    // - Nếu không chọn việc thứ i thì f[i] = f[i-1]
    for (int i = 1; i <= n; i++) {
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        if (f[i-1][0] >= f[i-1][1]) {
            f[i][0] = f[i-1][0];
            vet[i][0] = vet[i-1][0];
        } else {
            f[i][0] = f[i-1][1];
            vet[i][0] = vet[i-1][1];
        }
        if (f[p[i]][1] >= f[i-1][0]) {
            f[i][1] = f[p[i]][1];
            vet[i][1] = p[i];
        } else {
            f[i][1] = f[i-1][0];
            vet[i][1] = vet[i-1][0];
        }
        f[i][1] = max(f[p[i]][1], f[i-1][0]) + a[i].first.second;
        //cout << i << ' ' << f[i][0] << ' ' << f[i][1] << '\n';
    }
    //for (int i = 1; i <= n; i++) cout << vet[i][0] << ' ' << vet[i][1] << '\n';
    for (int i = n; i != 0;) {
        if (f[i][0] >= f[i][1]) {
            i = vet[i][0];
            continue;
        }
        d[i] = true;
        i = vet[i][1];
    }
    for (int i = 1; i <= n; i++) {
        if (d[i]) cout << a[i].second << '\n';
    }
    for (int i = 1; i <= n; i++) {
        if (!d[i]) cout << a[i].second << '\n';
    }
    cout << max(f[n][0], f[n][1]);

    return 0;
}
// Test:
/*
4
1 15
3 10
5 100
1 27
*/
