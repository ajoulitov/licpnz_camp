/**
 *    author:  tulizh
 *    created: 2025-01-04 15:52:50
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

void solve() {
   
}