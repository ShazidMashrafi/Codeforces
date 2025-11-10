#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include <debug.h>
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
    int n;
    cin >> n;
    int M = 2 * n;

    vector<int> a1(n + 1), a2(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a1[i];
    for (int i = 1; i <= n; ++i) cin >> a2[i];

    vector<int> mn1(n + 1), mx1(n + 1);
    mn1[1] = mx1[1] = a1[1];
    for (int i = 2; i <= n; ++i) {
        mn1[i] = min(mn1[i - 1], a1[i]);
        mx1[i] = max(mx1[i - 1], a1[i]);
    }

    vector<int> mn2(n + 2, INT_MAX), mx2(n + 2, INT_MIN);
    for (int i = n; i >= 1; --i) {
        mn2[i] = min(mn2[i + 1], a2[i]);
        mx2[i] = max(mx2[i + 1], a2[i]);
    }

    vector<pair<int, int>> v;
    for (int k = 1; k <= n; ++k) {
        int k1 = min(mn1[k], mn2[k]);
        int k2 = max(mx1[k], mx2[k]);
        v.pb({k2, k1});
    }
    sort(all(v));

    ll ans = 0;
    int mx = 0, idx = 0;

    for (int r = 1; r <= M; ++r) {
        while (idx < sz(v) && v[idx].ff <= r) {
            mx = max(mx, v[idx].ss);
            ++idx;
        }
        ans += min(r, mx);
    }
    cout << ans << endl;
}

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}