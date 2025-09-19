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

ll n, k;
vector<ll>a;

void unsort(auto &a, ll l, ll r)
{
    if(k <= 0 || l + 1 == r)    return;
    k -= 2;

    ll m = l + (r - l) / 2;
    swap(a[m-1], a[m]);
    
    unsort(a, l, m);
    unsort(a, m, r);
}

void solve()
{
    cin >> n >> k;
    
    a.resize(n);
    for(ll i = 0; i < n; ++i)   a[i] = i + 1;
    
    k--;
    unsort(a, 0, n);

    if(k) {
        cout << -1 << endl;
        return;
    }

    for(auto x : a)
        cout << x << " ";
    cout << endl;
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