#include <bits/stdc++.h>
using namespace std;
#if defined(LOCAL) && !defined(ONLINE_JUDGE)
#include "debug.h"
#else
#define dbg(...)
#endif
#define  ll  long long
#define  endl  '\n'
#define  ff  first
#define  ss  second
#define  pb  push_back
#define  sz(x)  (int)(x).size()
#define  all(x)  x.begin(), x.end()
#define  Dpos(n) fixed << setprecision(n)
#define  yn(f)  f? cout<<"YES\n":cout<<"NO\n"
#define  FAST  (ios_base::sync_with_stdio(false), cin.tie(nullptr));
ll power(ll x,ll y,ll m=LLONG_MAX) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

void solve()
{
    string s;
    cin >> s;
    int n = sz(s);
    if (n == 3) {
        cout << 0 << endl;
        return;
    }

    int ans = 4;
    for (int i = 0; i <= n - 3; ++i) {
        if (s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]) {
            if (i == 0 || i == n - 3) {
                ans = min(ans, 1);
            } else {
                ans = min(ans, 2);
            }
        }
    }

    if (s[0] != s[1] && s[0] != s[n-1] && s[1] != s[n-1]) ans = min(ans, 2);
    if (s[0] != s[n-2] && s[0] != s[n-1] && s[n-2] != s[n-1]) ans = min(ans, 2);
    if (s[0] != s[1] || s[n-2] != s[n-1]) ans = min(ans, 3);

    for (int i = 1; i <= n - 3; ++i) {
        if (s[i] != s[i+1]) {
            if (s[0] != s[i] && s[0] != s[i+1]) ans = min(ans, 3);
            if (s[n-1] != s[i] && s[n-1] != s[i+1]) ans = min(ans, 3);
        }
    }

    cout << ans << endl;
}


signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int TCS = 1;
    // cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}