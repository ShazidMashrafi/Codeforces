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
    vector<ll>a(n + 1);
    for(ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<ll>pre(n + 1, 0);
    for(ll i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }

    for(ll l = 1; l < n - 1; ++l) {
        for(ll r = l + 1; r < n; ++r) {
            ll s1 = pre[l] % 3;
            ll s2 = (pre[r] - pre[l]) % 3;
            ll s3 = (pre[n] - pre[r]) % 3;

            if(s1 == s2 && s2 == s3) {
                cout << l << " " << r << endl;
                dbg(s1, s2, s3);
                return;
            }
            if(s1 != s2 && s2 != s3 && s1 != s3) {
                dbg(s1, s2, s3);
                cout << l << " " << r << endl;
                return;
            }
        }
    }
    cout << 0 << " " << 0 << endl;
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