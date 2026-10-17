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

struct DSU {
    vector<int> par, siz;
    int comps;

    DSU(int n) {
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
        siz.assign(n + 1, 1);
        comps = n;
    }

    int find(int u) {
        return par[u] == u ? u : par[u] = find(par[u]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        if (siz[u] < siz[v]) swap(u, v);
        par[v] = u;
        siz[u] += siz[v];
        comps--;
        return true;
    }

    int size(int u) {
        return siz[find(u)];
    }
};

void solve()
{
    int n;
    cin >> n;
    DSU dsu(n);
    
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        dsu.unite(i, x);
    }

    cout << dsu.comps << endl;
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