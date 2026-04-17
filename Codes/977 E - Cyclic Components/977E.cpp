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

const int N = 2e5 + 10;
vector<int>g[N];
bool vis[N];
vector<int>deg(N);
vector<int>v;
 
void dfs(int vertex)
{
	vis[vertex] = true;
	v.push_back(vertex);
	for(int child : g[vertex]) {
		if(vis[child])	continue;
		dfs(child);
	}
}
 
void solve()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[v]++, deg[u]++;
	}
 
	int ct = 0;
	for(int i = 1; i <= n; ++i) {
		if(vis[i])	continue;
		dfs(i);
		bool ok = true;
		for(auto c : v) {
			ok &= (deg[c] == 2);
		}
		if(ok) ct++;
		v.clear();
	}
 
	cout << ct << endl;
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