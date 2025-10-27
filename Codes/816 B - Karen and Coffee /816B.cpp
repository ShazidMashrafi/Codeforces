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
    const ll N = 200000;
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll>freq(N + 10, 0), p(N + 10, 0);
    for(ll i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        freq[x]++;
        freq[y + 1]--;
    }

    for(ll i = 1; i <= N; ++i) {
        p[i] = freq[i] + p[i - 1];
    }

    vector<int>v(N + 10, 0), pre(N + 10, 0);
    for(ll i = 0; i <= N; ++i) {
        if(p[i] >= k) {
            v[i] = 1;
        }
    }

    for(ll i = 1; i <= N; ++i) {
        pre[i] = v[i] + pre[i - 1];
    }

    while(q--) {
        ll l, r;
        cin >> l >> r;
        cout <<  pre[r] - pre[l - 1] << endl;
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