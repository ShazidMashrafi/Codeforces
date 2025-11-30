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
    vector<ll>v(2 * n);
    map<ll, ll> mp;

    for (int i = 0; i < 2 * n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    
    ll ans = 0, ct = 0, odd = 0;
    for(auto [x, y] : mp) {
        if(y & 1) {
            ans += 1;
            odd++;
        } else {
            ll q = y / 2;
            if(q & 1) {
                ans += 2;
            } else {
                ct++;
            }
        }
    }
    // dbg(ans, ct, odd);
    if((ct & 1) && odd == 0) {
        cout << ans + 2 * (ct - 1) << endl;
    } else {
        cout << ans + 2 * ct << endl;
    }
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