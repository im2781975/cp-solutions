#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming/tree/master/CodeForces
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...) 42
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<string> s(n), t(m);
    for (ll i = 0; i < n; ++i) cin >> s[i];
    for (ll i = 0; i < m; ++i) cin >> t[i];
    ll q, qq;
    cin >> q;
    while (q--) {
        cin >> qq;
        cout << s[(qq - 1) % n] << t[(qq - 1) % m] << '\n';
    }
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}