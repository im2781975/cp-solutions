//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repeq(i, a, b) for (int i = a; i <= b; i++)
#define repn(i, n) for (int i = 0; i < n; i++)

typedef long long ll;
//SORT STRING TO SOLVE
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    cout << s << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}