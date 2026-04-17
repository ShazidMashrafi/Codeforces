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

const int MOD = 1e9 + 7;
vector<int>divisors[2010];
vector<vector<ll>> dp(2010, vector<ll>(2010, -1));

ll give(ll n, ll k) 
{
    if(k == 1)  return 1;
    if(dp[n][k] != -1)  return dp[n][k];

    ll ans = 0;
    for(int i = 0; i < sz(divisors[n]); ++i) {
        ans += give(divisors[n][i], k - 1);
        ans %= MOD;
    }
    dp[n][k] = ans;
    return ans;
}

void solve()
{
    ll n, k, ans = 0;
    cin >> n >> k;

    for(int i = 1; i <= n; ++i) {
        ans += give(i, k);
        ans %= MOD;
    }
    cout << ans << endl;
}

signed main()
{
    FAST;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    for(int i = 1; i < 2010; ++i) {
        for(int j = i; j < 2010; j += i) {
            divisors[j].push_back(i);
        }
    }

    int TCS = 1;
    // cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}