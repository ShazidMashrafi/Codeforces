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
    ll n, q;
    cin >> n >> q;
    deque<ll> d;
    ll mx = 0;
    for(int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        d.push_back(x);
        mx = max(mx, x);
    }

    vector<pair<ll, ll>> pairs;
    while(d.front() != mx)
    {
        ll a = d.front();
        d.pop_front();
        ll b = d.front();
        d.pop_front();
        pairs.push_back({a, b});

        if(a > b)
        {
            d.push_front(a);
            d.push_back(b);
        }
        else
        {
            d.push_front(b);
            d.push_back(a);
        }
    }

    vector<ll>cycle;
    for(int i = 1; i < sz(d); ++i)
        cycle.push_back(d[i]);

    while(q--)
    {
        ll m, i;
        cin >> m;
        if(m <= sz(pairs))
            cout << pairs[m - 1].ff << " " << pairs[m - 1].ss << endl;
        else
        {
            m -= sz(pairs);
            ll k = cycle[(m - 1) % sz(cycle)];
            cout << mx << " " << k << endl;
        }
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