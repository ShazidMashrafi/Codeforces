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
ll power(ll x,ll y,ll m=LLONG_MAX) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

class DSU
{
private:
    vector<int> par;
    vector<int> size;
public:
    DSU(int n)
    {
        par = vector<int>(n);
        iota(par.begin(), par.end(), 0);
        size = vector<int>(n, 1);
    }
    
    int find(int u)
    {
        if (par[u] != u)
           par[u] = find(par[u]);
        return par[u];
    }
    
    bool connected(int u, int v)
    {
        u = find(u);
        v = find(v);
        return u == v;
    }
    
    bool join(int u, int v)
    {
        u = find(u);
        v = find(v);
        if(u == v) return false;
        if(size[u] <= size[v])
        {
            size[v] += size[u];
            par[u] = v;
        }
        else
        {
            size[u] += size[v];
            par[v] = u;
        }
        return true;
    }
};

void solve()
{
    int n;
    cin >> n;
    
    int root = -1;
    vector<int>a(n + 1);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(i == a[i]) {
            root = i;
        }
    }
    
    DSU dsu(n + 1);
    vector<int>cycles;
    for(int i = 1; i <= n; ++i) {
        if(dsu.find(i)== dsu.find(a[i])) {
            cycles.pb(i);
        } else {
            dsu.join(i, a[i]);
        }
    }
    
    if(root == -1) root = cycles[0];
    
    int ans = 0;
    for (int u : cycles) {
        if (a[u] != root) {
            a[u] = root;
            ans++;
        }
    }
    cout << ans << endl;
    for(int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
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