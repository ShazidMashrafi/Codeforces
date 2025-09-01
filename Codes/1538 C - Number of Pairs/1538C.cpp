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
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll>a(n);
    for(auto &i : a)    cin >> i;
    sort(all(a));

    ll cnt = 0;
    for(ll i = 0; i < n; ++i) {
        ll left = upper_bound(a.begin() + i + 1, a.end(), l - a[i] - 1) - a.begin();
        ll right = upper_bound(a.begin() + i + 1, a.end(), r - a[i]) - a.begin() - 1;

        if(left <= right) {
            cnt += right - left + 1;
        }
    }

    cout << cnt << endl;
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