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

const int INF = 1e9;
map<pair<ll,ll>, ll> memo;

ll fun(ll n, ll k)
{   
    if(k > n)   return INF;
    if(k == n)  return 0;
    auto it = memo.find({n,k});
    if (it != memo.end()) return it->second;

    ll a = n / 2;
    ll b = n - a;
    ll ans = INF;

    if(k <= a) {
        ans = min(ans, 1 + fun(a, k));
    }
    if(k <= b) {
        ans = min(ans, 1 + fun(b, k));
    }
    return memo[{n,k}] = ans;
}


void solve()
{
    int n, k;
    cin >> n >> k;
    memo.clear();
    ll res = fun(n, k);
    if(res >= INF)  {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
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