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

const ll MOD = 998244353;
vector<vector<ll>> dp;
vector<ll> a, b;
int n;

ll fun(int i, bool f)
{
    if(i == n) return 1;
    if(dp[i][f] != -1)
        return dp[i][f];
    
    ll ct = 0;
    
    ll p_a = 0, p_b = 0;
    if(f && i) {
        p_a = b[i - 1];
        p_b = a[i - 1];
    } else if(i) {
        p_a = a[i - 1];
        p_b = b[i - 1];
    }
    
    if(i == 0 || (a[i] >= p_a && b[i] >= p_b)) {
        ct = (ct + fun(i + 1, false)) % MOD;
    }
    if(i == 0 || (b[i] >= p_a && a[i] >= p_b)) {
        ct = (ct + fun(i + 1, true)) % MOD;
    }
    
    return dp[i][f] = ct;
}

void solve()
{
    cin >> n;
    a.resize(n);
    b.resize(n);
    for(auto &e: a) cin >> e;
    for(auto &e: b) cin >> e;
    
    dp.assign(n, vector<ll>(2, -1));
    
    ll ans = fun(0, false);
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