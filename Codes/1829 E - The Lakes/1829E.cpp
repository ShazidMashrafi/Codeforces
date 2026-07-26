#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif
#define  int  long long
#define  ll  long long
#define  endl  '\n'
#define  ff  first
#define  ss  second
#define  pb  push_back
#define  sz(x)  (int)(x).size()
#define  all(x)  x.begin(), x.end()
#define  yn(f)  f? cout<<"YES\n":cout<<"NO\n"
#define  Dpos(n) fixed << setprecision(n)
#define  FAST  (ios_base::sync_with_stdio(false), cin.tie(nullptr));
ll power(ll x,ll y,ll m=LLONG_MAX) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

int fun(int i, int j, int n, int m, auto &grid, auto &vis) 
{
    if(vis[i][j] || grid[i][j] == 0)   return 0;
    vis[i][j] = true;
    int sum = grid[i][j];
    if(i > 0) {
        sum += fun(i - 1, j, n, m, grid, vis);
    }
    if(i + 1 < n) {
        sum += fun(i + 1, j, n, m, grid, vis);
    }
    if(j > 0) {
        sum += fun(i, j - 1, n, m, grid, vis);
    }
    if(j + 1 < m) {
        sum += fun(i, j + 1, n, m, grid, vis);
    }
    return sum;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    // dbg(grid);
    // dbg(vis);
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(!vis[i][j] && grid[i][j] > 0) {
                int tot = fun(i, j, n, m, grid, vis);
                // dbg(i, j, tot);
                ans = max(ans, tot);
            }
        }
    }
    cout << ans << endl;
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