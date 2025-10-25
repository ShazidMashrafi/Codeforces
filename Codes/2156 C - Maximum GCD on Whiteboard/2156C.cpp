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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> freq(n + 1, 0);
    
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    
    vector<ll> pre(n + 1, 0);
    for(ll i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + freq[i];
    }
    
    ll ans = 1;

    for(ll d = n; d >= 1; d--) {

        ll lim = min(n, 4 * d - 1);
        ll ct = pre[lim];
        
        ll valid = freq[d];
        if(2 * d <= n) valid += freq[2 * d];
        if(3 * d <= n) valid += freq[3 * d];

        if(ct - valid <= k) {
            ans = d;
            break;
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
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}