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
    ll n, ans;
    cin >> n;
    vector<ll>v(n);
    for(auto && i : v)  cin >> i;

    if(n == 1)
    {
        cout << 1 << endl;
        return;
    }

    sort(all(v));
    if(n & 1)
    {
        ll ans = 1e18;

        for(ll i = 0; i < n; ++i)
        {
            vector<ll>temp;
            for(ll j = 0; j < n; ++j)
            {
                if(i == j)  continue;
                temp.push_back(v[j]);
            }

            ll mx = 0;
            for(ll j = 1; j < sz(temp); j +=2)
                mx = max(mx, temp[j] - temp[j - 1]);
            
            ans = min(ans, mx);
        }

        cout << ans << endl;
    }
    else
    {
        ll mx = 0;
        for(ll i = 1; i < n; i +=2)
            mx = max(mx, v[i] - v[i - 1]);
        
        cout << mx << endl;
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