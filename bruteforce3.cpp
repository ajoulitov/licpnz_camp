#include <iostream>
#include <bitset>

using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     int set;
//     cin >> set;
//     for (int mask = 0; mask < (1 << n); ++mask) {

//         for (int smask = set; ; smask = (smask - 1) & set) {
//         //    cout << bitset<8>(smask) << '\n';
//         if (!smask) {
//             break;
//         }
//     }
//     }
//     // 11111111
//     // 00100110
//     cout << bitset<8>(set) << '\n';
    
// }


const int N = 5000 + 69;
int dp[N];
int a, b, c;
int rec(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    if (dp[n] != -2) {
        return dp[n];
    }
    int a_ = rec(n - a), b_ = rec(n - b), c_ = rec(n - c);
    if (a_ != -1) {
        dp[n] = max(dp[n], a_ + 1);
    }
    if (b_ != -1) {
        dp[n] = max(dp[n], b_ + 1);
    }
    if (c_ != -1) {
        dp[n] = max(dp[n], c_ + 1);
    }
    return dp[n];
}

int main() {
    fill(dp, dp + N, -2);

}