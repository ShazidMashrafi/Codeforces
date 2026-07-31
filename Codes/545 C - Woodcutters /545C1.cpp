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

const ll N = 1e5 + 10;
ll n;
vector<ll> pos(N), height(N);
ll memo[N][2];

ll fun(ll i, ll state)
{
    if (i == n) return 0;
    if (memo[i][state] != -1) return memo[i][state];

    ll prev = -2e9 - 7;
    if (i > 0) {
        if (state == 0) {
            prev = pos[i - 1];
        } else {
            prev = pos[i - 1] + height[i - 1];
        }
    }

    ll ans = 0;
    if (pos[i] - height[i] > prev) {
        ans = max(ans, 1 + fun(i + 1, 0));
    }

    if (i == n - 1 || pos[i] + height[i] < pos[i + 1]) {
        ans = max(ans, 1 + fun(i + 1, 1));
    }
    
    ans = max(ans, fun(i + 1, 0));

    return memo[i][state] = ans;
}

void solve()
{
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> pos[i] >> height[i];
    }
    memset(memo, -1, sizeof(memo));
    cout << fun(0, 0) << endl;
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