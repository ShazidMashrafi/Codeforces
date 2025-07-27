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

bool check(ll d, auto &stalls, ll k)
{
    ll p = stalls[0], ct = 1;
    while(true)
    {
        auto it = lower_bound(all(stalls), p + d);
        if(it == stalls.end()) break;
        p = *it;
        ct++;
        if(ct >= k) break;
    }
    return ct >= k;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll>stalls(n);
    for(auto &i : stalls)    cin >> i;
    ll low = 0, high = stalls.back() - stalls.front(), ans = 0;
    while(low <= high)
    {
        ll mid = low + (high - low) / 2;
        if(check(mid, stalls, k))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << ans << endl;
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