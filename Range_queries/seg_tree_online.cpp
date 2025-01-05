//#include <bits/stdc++.h>
#include <iostream>
#include <array>
#include <vector>
using namespace std;
const int N = 1 << 17;
// const int N = 1 << 17; // 100'000
// int t[2 * N]; 
// array<int, 2 * N> t;
int t[2 * N];
void build(const vector<int> &a) {
    for (int i = 0; i < (int)a.size(); ++i) {
        t[i + N] = a[i];
    }
    for (int i = N - 1; i > 0; --i) {
        t[i] = t[i * 2] + t[i * 2 + 1];
    }
}
void update(int i, int x) {
    // for (t[i += N] = x, i /= 2; i; i /= 2) {
    //     t[i] = t[i * 2] + t[i * 2 + 1];
    // }
    i += N;
    t[i] = x;
    i /= 2;
    while (i > 0) {
        t[i] = t[i * 2] + t[i * 2 + 1];
        i /= 2;
    }
}

// [l; r], но можно [l; r)
int get(int ql, int qr, int l, int r, int v) {
    if (ql >= r || l >= qr) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return t[v];
    }
    int mid = (l + r) / 2;
    return get(ql, qr, l, mid, v * 2) + get(ql, qr, mid, r, v * 2 + 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A) {
        cin >> x;
    }
    build(A);
    int q;
    cin >> q;
    for (int iter = 0; iter < q; ++iter) {
        int type;
        cin >> type;
        if (type == 1) { // update
            int i, x; // i - 0-инд
            cin >> i >> x;
            update(i, x);
        } else { // get
            int l, r;
            cin >> l >> r;
            cout << get(l, r + 1, 0, N, 1) << '\n';
        }
    }
}
