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
ll binpow(ll x,ll y,ll m=LLONG_MAX) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

struct BFS {
    vector<int> dist, par;

    BFS(int n, int src, auto& g) : dist(n + 1, -1), par(n + 1, -1) {
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto [v, c] : g[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    par[v] = u;
                    q.push(v);
                }
            }
        }
    }

    vector<int> get_path(int target) {
        if (dist[target] == -1) return {};
        vector<int> path;
        for (int v = target; v != -1; v = par[v]) path.push_back(v);
        reverse(path.begin(), path.end());
        return path;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,char>>>g(n + 1);
    for(int i = 0; i < m; ++i) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        g[u].pb({v, c});
        g[v].pb({u, c});
    }

    BFS bfs(n, n, g);
    int k = bfs.dist[1];
    
    fill(all(bfs.par), -1);
    vector<int>curr = {1};
    string ans;

    for(int i = 0; i < k; ++i) {
        char mn = 'z' + 1;
        for(int u : curr) {
            for(auto [v, c] : g[u]) {
                if(bfs.dist[v] == bfs.dist[u] - 1) {
                    mn = min(mn, c);
                }
            }
        }
        ans.pb(mn);

        vector<int>nxt;
        for(int u : curr) {
            for(auto [v, c] : g[u]) {
                if(bfs.dist[v] == bfs.dist[u] - 1 && c == mn) {
                    if(bfs.par[v] == -1) {
                        bfs.par[v] = u;
                        nxt.pb(v);
                    }
                }
            }
        }
        curr = nxt;
    }

    vector<int>path = bfs.get_path(n);
    cout << k << endl;
    for(int i = 0; i < sz(path); ++i) {
        cout << path[i] << " ";
    }
    cout << endl;
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