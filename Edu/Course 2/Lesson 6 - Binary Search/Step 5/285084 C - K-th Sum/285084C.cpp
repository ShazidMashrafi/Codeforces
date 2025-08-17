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

ll count(ll x, vector<ll>& a, vector<ll>& b) {
    ll ct = 0;
    ll n = sz(a);
    
    for (ll i = 0; i < n; i++) {
        ll y = x - a[i] + 1;
        ll pos = lower_bound(all(b), y) - b.begin();
        ct += pos;
    }
    
    return ct;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    
    vector<ll> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    sort(all(b));
    
    ll left = a[0] + b[0];
    ll right = a[0] + b[0];
    for (ll i = 0; i < n; i++) 
    {
        left = min(left, a[i] + b[0]);
        right = max(right, a[i] + b[n-1]);
    }

    while (left < right) {
        ll mid = left + (right - left) / 2;
        
        if (count(mid, a, b) < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    cout << left << endl;
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