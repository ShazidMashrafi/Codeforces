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

void solve()
{
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(auto &i : a)    cin >> i;
    ll sum = accumulate(all(a), 0ll);
    ll mx = *max_element(all(a));
    auto check = [&](ll mid)
    {
        return mid * (n - 1) >= sum && mid >= mx;
    };
    
    ll low = 0, high = 1;
    while(!check(high))
        high *= 2;
    
    ll ans = high;

    while(low <= high)
    {
        ll mid = low + (high - low) / 2;
        if(check(mid))
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
    // cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}