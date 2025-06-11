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

ll fun(auto &weight, auto &value, ll i, ll n, ll mx_w)
{
    if(i >= n || mx_w == 0)
        return 0;
    ll v1 = fun(weight, value, i + 1, n, mx_w);
    ll v2 = 0;
    if(weight[i] <= mx_w)
        v2 = value[i] + fun(weight, value, i + 1, n, mx_w - weight[i]);
    return max(v1, v2);
}

void solve()
{
    ll n, mx_w;
    cin >> n >> mx_w;
    vector<ll> weight(n), value(n);
    for(ll i = 0; i < n; ++i)
        cin >> weight[i] >> value[i];

    cout << fun(weight, value, 0, n, mx_w) << endl;
    
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