#include <vector>
#include <iostream>
#define int long long
const int A = 1'000'000 + 69;
int lastd[A];
void sieve() {
    for (int i = 0; i < A; ++i) {
        lastd[i] = i;
    }
    for (int i = 2; i < A; ++i) {
        if (lastd[i] != i) {
            continue;
        }
        if (1ll * i * i > 1ll * A) {
            continue;
        }
        for (int j = i; j < A; j += i) {
            lastd[j] = i;
        }
    }
}
std::vector<int> factor(int x) {
    std::vector<int> f;
    while (x != 1) {
        f.push_back(lastd[x]);
        x /= lastd[x];
    }
    return f;
}
signed main() {
    sieve();
    int n;
    std::cin >> n;
    std::vector<int> f = factor(n);
    for (auto &x : f) {
        std::cout << x << '\n';
    }

}