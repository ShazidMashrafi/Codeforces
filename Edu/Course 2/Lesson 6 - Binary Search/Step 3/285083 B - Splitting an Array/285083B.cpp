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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &x : a) cin >> x;

    ll low = *max_element(all(a)), high = accumulate(all(a), 0ll), ans = high;
    while(low <= high)
    {
        ll mid = low + (high - low) / 2;
        int cnt = 1;
        ll cur_sum = 0;
        for(int i = 0; i < n; ++i)
        {
            if(cur_sum + a[i] > mid)
            {
                cnt++;
                cur_sum = 0;
            }
            cur_sum += a[i];
        }
        if(cnt <= k)
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