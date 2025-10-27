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
    ll n, p, l, r;
    cin >> n >> p >> l >> r;
    if(l == 1 && r == n) {
        cout << 0 << endl;
        return;
    }

    if(l == 1) {
        cout << abs(p - r) + 1 << endl;
        return;
    }

    if(r == n) {
        cout << abs(p - l) + 1 << endl;
        return;
    }

    ll ans = 2, d = r - l;
    if(p <= l) {
        ans += l - p + d;
    } else if(p >= r) {
        ans += p - r + d;
    } else {
        ll d1 = abs(p - l);
        ll d2 = abs(p - r);
        if(d1 < d2) {
            ans += p - l + d;
        } else {
            ans += r - p + d;
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