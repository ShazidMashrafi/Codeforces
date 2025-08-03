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
    vector<ll>x(n), v(n);
    for(auto &i : x) cin >> i;
    for(auto &i : v) cin >> i;

    double low = 0, high = 1e18, ans = 1e18;
    for(int itr = 0; itr < 100; ++itr)
    {
        double mid = (low + high) / 2;
        double l = -1e20, r = 1e20;
        for(int i = 0; i < n; ++i)
        {
            l = max(l, x[i] - v[i] * mid);
            r = min(r, x[i] + v[i] * mid);
        }
        if(l <= r)
        {
            ans = mid;
            high = mid;
        }
        else
            low = mid;
    }
    cout << Dpos(12) << ans << endl;
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