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
    ll n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<ll> prob(n);
    for(ll i = 0; i < n; ++i)  cin >> prob[i];

    ll ans = 0;
    for(ll mask = 0; mask < (1 << n); mask++)
    {
        ll ct = 0, sum = 0, mx = 0, mn = INT_MAX;
        for(int i = 0; i < n; ++i)
        {
            if(mask & (1 << i))
            {
                ct++;
                sum += prob[i];
                mn = min(mn, prob[i]);
                mx = max(mx, prob[i]);
            }
        }
        if(ct >= 2 && sum >= l && sum <= r && mx - mn >=x) ans++;
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