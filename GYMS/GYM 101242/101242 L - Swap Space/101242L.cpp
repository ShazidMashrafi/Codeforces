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

bool can(auto &good, auto &bad, ll x) {
    for (auto [a, b]: good) {
        if (x < a) return false;
        x = x - a + b;
    }
    for (auto [a, b]: bad) {
        if (x < a) return false;
        x = x - a + b;
    }
    
    return true;
}

void solve()
{
    int n;
    cin >> n;
    
    vector<pair<ll, ll>> drives(n);
    for(auto &[a, b] : drives)   cin >> a >> b;

    vector<pair<ll, ll>> good, bad;
    for (auto [a, b]: drives) {
        if (b >= a) {
            good.pb({a, b});
        } else {
            bad.pb({a, b});
        }
    }
    
    sort(all(good), [](auto x, auto y) {
        return x.ff < y.ff;
    });
    sort(all(bad), [](auto x, auto y) {
        return x.ss > y.ss;
    });
    
    ll left = 0, right = 2e18, ans = 0;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (can(good, bad, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
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
    // cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}