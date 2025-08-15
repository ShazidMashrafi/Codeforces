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
    int n, m, d;
    cin >> n >> m >> d;
    int mx = 0;
    vector<vector<pair<int, int>>> g(n + 1);
    for(int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        mx = max(mx, c);
    }

    auto bfs = [&](int lim) -> vector<int>
    {
        vector<int> dist(n + 1, INT_MAX), par(n + 1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto e : g[u])
            {
                int v = e.ff, cost = e.ss;
                if(cost > lim ) continue;
                if(dist[v] > dist[u] + 1)
                {
                    dist[v] = dist[u] + 1;
                    par[v] = u;
                    q.push(v);
                }
            }
        }

        if(dist[n] > d) return {};
        vector<int> path;
        int cur = n;
        while(cur != -1)
        {
            path.push_back(cur);
            cur = par[cur];
        }
        reverse(all(path));
        return path;
    };

    int low = 0, high = mx, ans = -1;
    vector<int>best;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        auto path = bfs(mid);
        if(!path.empty())
        {
            ans = mid;
            best = path;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    if(best.empty()) 
    {
        cout << -1 << endl;
        return;
    }

    cout << sz(best) - 1 << endl;
    for(int x : best) cout << x << " ";
    cout << endl;
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