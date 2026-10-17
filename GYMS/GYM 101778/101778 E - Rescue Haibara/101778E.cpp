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
    int n, x, y;
    cin >> n >> x >> y;
    vector<pair<int, pair<int,int>>> v(n);
    for(int i = 0; i < n; ++i) {
        v[i].ff = i + 1;
        cin >> v[i].ss.ff >> v[i].ss.ss;
    }

    sort(all(v), [&](auto a, auto b) {
        if(a.ss.ff == b.ss.ff && a.ss.ss == b.ss.ss) return a.ff < b.ff;
        if(a.ss.ff == b.ss.ff) return a.ss.ss > b.ss.ss;
        return a.ss.ff < b.ss.ff; 
    });
    // dbg(v);
    for(int i = 0; i < n; ++i) {
        if(v[i].ss.ff <= x && v[i].ss.ss >= y) {
            cout << v[i].ff << endl;
            return;
        }
    }
    cout << -1 << endl;
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
