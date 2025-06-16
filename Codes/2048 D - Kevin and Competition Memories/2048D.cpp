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
    ll n, m, INF = 1e18;
    cin >> n >> m;
    vector<ll>a(n), b(m);
    for(auto &&i : a) cin >> i;
    for(auto &&i : b) cin >> i;

    ll kevin = a[0];
    vector<ll>p, cnt(m);

    for(ll i = 1; i < n; ++i)
    {
        if(a[i] > kevin) p.push_back(a[i]);
    }
    sort(all(p));

    for(int i = 0; i < m; ++i)
    {
        if(b[i] <= kevin) b[i] = INF;
        auto it = lower_bound(all(p), b[i]);
        cnt[i] = p.end() - it;
    }
    sort(all(cnt));

    for(int k = 1; k <= m; ++k)
    {
        int contest = m / k;
        ll sum = 0;
        for(int i = k - 1; i < contest * k; i += k)
        {    
            ll rank = 1 + cnt[i];
            dbg(rank);
            sum += rank;
        }
        dbg("HI");
        cout << sum << " ";
    }
    cout << endl;
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