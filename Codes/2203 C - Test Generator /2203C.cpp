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

bool fun(ll s, ll m, ll n)
{
    ll rem = s;
    for(int j = 60; j >= 0; j--) {
        if((m >> j) & 1) {
            ll use = min(n, rem >> j);
            rem -= use * (1LL << j);
        }
    }
    return rem == 0;
}

void solve()
{
    ll s, m;
    cin >> s >> m;
    if(!fun(s, m, s)) {
        cout << -1 << endl;
        return;
    }
    ll low = 1, high = s;
    while(low < high) {
        ll mid = low + (high - low) / 2;
        if(fun(s, m, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
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