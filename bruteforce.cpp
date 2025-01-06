#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<bool> used;
vector<int> P;
int n;
void rec(int ind) {
    if (ind == n) {
        for (auto &x : P) {
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }
    for (int x = 1; x <= n; ++x) {
        if (used[x]) {
            continue;
        }
        P[ind] = x;
        used[x] = true;
        rec(ind + 1);
        used[x] = false;
    }
}
int main() {
    cin >> n;
    // used.resize(n + 1);
    P.resize(n);
    // rec(0);
    for (int i = 0; i < n; ++i) {
        P[i] = i + 1;
    }
    do {
        for (auto &x : P) {
            cout << x << ' ';
        }
        cout << '\n';
    } while (next_permutation(P.begin(), P.end()));
}