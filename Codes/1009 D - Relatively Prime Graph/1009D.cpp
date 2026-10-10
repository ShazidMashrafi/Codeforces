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
ll binpow(ll x,ll y,ll m=LLONG_MAX) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

void solve()
{
    int n, m;
    cin >> n >> m;
    if(m < n - 1) {
        cout << "Impossible" << endl;
        return;
    }
    vector<pair<int,int>> edges;
    for(int u = 1; u <= n; ++u) {
        for(int v = u + 1; v <= n; ++v) {
            if(gcd(u, v) == 1)  edges.pb({u, v});
            if(sz(edges) == m)  break;
        }
        if(sz(edges) == m)  break;
    }
    if(sz(edges) < m) {
        cout << "Impossible" << endl;
        return;
    }
    cout << "Possible" << endl;
    for(int i = 0; i < m && i < sz(edges); ++i) {
        cout << edges[i].ff << " " << edges[i].ss << endl;
    }
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