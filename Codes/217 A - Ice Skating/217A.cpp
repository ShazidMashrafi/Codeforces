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
        if(par[u] != par[par[u]])
            par[u] = find(par[par[u]]);        
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
    vector<pair<int, int>> drifts(n);
    for(auto &i: drifts)
        cin >> i.ff >> i.ss;
    
    DSU dsu(n);
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(drifts[i].ff == drifts[j].ff || drifts[i].ss == drifts[j].ss)    
                dsu.join(i, j);
        }
    }

    set<int> st;
    for(int i = 0; i < n; ++i)
        st.insert(dsu.find(i));

    cout << sz(st) - 1 << endl;
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