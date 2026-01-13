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
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    vector<int> depth(n + 1, -1);
    queue<int> q;
    q.push(1);
    depth[1] = 0;
    
    map<int, int> mp;
    int mx = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        mp[depth[u]]++;
        
        int child = 0;
        for (int v : g[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                q.push(v);
                child++;
            }
        }
        mx = max(mx, child);
    }

    int ans = 0;
    for (auto& p : mp) {
        ans = max(ans, p.ss);
    }
    ans = max(ans, mx + 1);
    cout << ans << endl;
}

signed main()
{
    FAST;

    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        solve();
    }
}