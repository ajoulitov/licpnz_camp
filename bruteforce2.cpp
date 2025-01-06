#include <iostream>
#include <vector>

using namespace std;

// выводим все двоичные последовательности без двух 1 подряд

int n;
vector<char> A;
int cnt = 0;
void rec(int ind) {
    if (ind == n) {
        for (auto &x : A) {
            cout << x << ' ';
        }
        cout << '\n';
        cnt ++;
        return;
    }

    A[ind] = '0';
    rec(ind + 1);

    if (ind == 0 || A[ind - 1] != '1') {
        A[ind] = '1';
        rec(ind + 1);
    }
}

int main() {
    cin >> n;
    A.resize(n);
    rec(0);
    cerr << cnt << '\n';
}