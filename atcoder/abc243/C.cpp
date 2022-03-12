#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n;
    cin >> n;
    map<ll, vector<pair<ll, ll>>> mp;  // {x, {y, i}}
    for (ll i = 0, u, v; i < n; ++i) {
        cin >> u >> v;
        mp[v].push_back({u, i});
    }
    string s;
    cin >> s;
    for (auto &[y, v] : mp) {
        bool R = false;
        sort(all(v));
        for (auto &[x, i] : v) {
            if (s[i] == 'R' && !R) R = true;
            if (s[i] == 'L' && R) return void(cout << "Yes\n");
        }
    }
    cout << "No\n";
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    std::cout.rdbuf(cout.rdbuf()), std::cin.rdbuf(cin.rdbuf());
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
