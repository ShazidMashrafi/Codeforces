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

ll cnt(ll x, vector<pair<ll, ll>>& segments) 
{
    ll count = 0;
    for (auto& seg : segments) 
    {
        ll l = seg.ff, r = seg.ss;
        if (x <= l) {
            count += 0;
        } else if (x > r) {
            count += (r - l + 1);
        } else {
            count += (x - l);
        }
    }
    return count;
}

void solve()
{
    int n;
    ll k;
    cin >> n >> k;
    
    vector<pair<ll, ll>> segments(n);
    ll mn = 2e9, mx = -2e9;
    
    for (int i = 0; i < n; i++) {
        cin >> segments[i].ff >> segments[i].ss;
        mn = min(mn, segments[i].ff);
        mx = max(mx, segments[i].ss);
    }
    
    ll left = mn;
    ll right = mx + 1;
    while (left < right) {
        ll mid = left + (right - left) / 2;
        
        if (cnt(mid, segments) <= k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    cout << left - 1 << endl;
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