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

bool check(vector<ll>&v, ll x, ll tot)
{
    ll ct = 0, n = sz(v);
    double h_avg = (tot + x) / (n * 2.0);
    for(ll i = 0; i < n; ++i)
    {
        ll w = v[i];
        if(i == n - 1) w += x;
        if(w < h_avg) ct++;
    }
    return ct > n / 2;
}

void solve()
{
    ll n, tot = 0;
    cin >> n;
    vector<ll>v(n);
    for(auto &i : v)    
    {
        cin >> i;
        tot += i;
    }
    sort(all(v));

    ll low = 0, high = 1e12, ans = -1;
    while(low <= high)
    {
        ll mid = low + (high - low) / 2;
        if(check(v, mid, tot))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
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