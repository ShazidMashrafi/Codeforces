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

int dfs(int u, auto& left, auto& right, auto& s)
{
    int l = left[u];
    int r = right[u];

    if(l == 0 && r == 0) {
        return 0;
    }

    int res = 1e9;
    if(l != 0) {
        res = min(res, dfs(l, left, right, s) + (s[u - 1] != 'L'));
    }
    if(r != 0) {
        res = min(res, dfs(r, left, right, s) + (s[u - 1] != 'R'));
    }
    return res;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int>left(n + 1), right(n + 1);
    for(int i = 1; i <= n; ++i) {
        cin >> left[i] >> right[i];
    }

    cout << dfs(1, left, right, s) << endl;
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