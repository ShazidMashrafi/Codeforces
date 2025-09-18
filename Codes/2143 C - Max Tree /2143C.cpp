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
    ll n;
    cin >> n;
    vector<vector<ll>> edges(n, vector<ll>(4));
    vector<pair<ll, ll>> vec;
    
    for(int i = 0; i < n - 1; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2] >> edges[i][3];
        ll d = abs(edges[i][2] - edges[i][3]);
        vec.pb({i, d});
    }

    sort(all(vec), [&](auto a, auto b) {
        return a.ss > b.ss;
    });

    vector<vector<ll>> g(n + 1);
    vector<ll> in(n + 1, 0);

    for(auto [i, d] : vec) {
        ll u = edges[i][0];
        ll v = edges[i][1];
        ll x = edges[i][2];
        ll y = edges[i][3];
        
        if (x > y) {
            g[v].pb(u);
            in[u]++;
        } else {
            g[u].pb(v);
            in[v]++;
        }
    }
    
    queue<ll> q;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) q.push(i);
    }
    
    vector<ll> order;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        order.pb(u);
        
        for (ll v : g[u]) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    
    vector<ll> ans(n + 1);
    for (int i = 0; i < n; ++i) {
        ans[order[i]] = i + 1;
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
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