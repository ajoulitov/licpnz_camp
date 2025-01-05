/**
 *    author:  tulizh
 *    created: 2025-01-05 09:50:12
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define eb emplace_back
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define ff first
#define ss second
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
// using ld = long double;
const long long INF = 1'000'000'000'000'000'000LL;

template<typename T>
T sqr(T x) {
  return x * x;
}
template<typename T>
bool asmn(T &a, const T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

template<typename T>
bool asmx(T &a, const T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template<typename T>
ostream& operator<<(ostream &out, vector<T> vec) {
    for (auto &x : vec)
        out << x << ' ';
    out << '\n';
    return out;
}
template<typename T>
istream& operator>>(istream &in, vector<T> &vec) {
    for (auto &x : vec)
        in >> x;
    return in;
}
void solve();
 
int32_t main() {
#ifdef tulizh
  freopen("in", "r", stdin);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int t = 1;
  // cin >> t;
  while (t--)
  solve();
}

// int get(int x1, int y1, int x2, int y2, const vector<vector<int>> &S) {
//     ++x2, ++y2;
//     return S[x2][y2] - S[x2][y1] - S[x1][y2] + S[x1][y1];
// }
// void solve() {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> A(n, vector<int> (m));
//     for (auto &x : A) {
//         for (auto &y : x)
//             cin >> y;
//     }
//     vector<vector<int>> S(n + 1, vector<int> (m + 1));
//     // S[i][j] - сумма до i, j-ой клетки не включая её
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= m; ++j) {
//             S[i][j] = A[i - 1][j - 1] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
//         }
//     }
// }

void print(const vector<int> &a) {
    for (auto &x : a) {
        cout << x << ' ';
    }
    cout << '\n';
}
vector<int> make_pref(vector<int> &a) {
    int n = (int)a.size();
    vector<int> s(n);
    s[0] = a[0];
    for (int i = 1; i < n; ++i) {
        s[i] = s[i - 1] + a[i];
    }
    return s;
}
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> ans(n), add_a(n), add_d1(n), add_d2(n);
    for (int iter = 0; iter < q; ++iter) {
        int a, d, l, r; // l, r, a, d,
        cin >> l >> r >> a >> d;
        // добавим a на отрезке
        add_a[l] += a;
        if (r != n - 1) {
            add_a[r + 1] -= a;
        }
        // добавим d на отркезке
        add_d1[l + 1] += d;
        if (r != n - 1) {
            add_d1[r + 1] -= d;
        }
        add_d2[r + 1] += -(r - l) * d;
    }
    add_a = make_pref(add_a);
    // print(add_a);
    add_d1 = make_pref(add_d1);
    vector<int> total_d(n);
    for (int i = 0; i < n; ++i) {
        total_d[i] = add_d1[i] + add_d2[i];
    }
    total_d = make_pref(total_d);
    for (int i = 0; i < n; ++i) {
        ans[i] = add_a[i] + total_d[i];
    }
    print(ans);
}