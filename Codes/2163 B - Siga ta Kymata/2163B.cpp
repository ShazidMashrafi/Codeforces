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
    int n;
    cin >> n;
    vector<int>a(n + 1);
    int mn = 1, mx = 1;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(a[i] < a[mn])    mn = i;
        if(a[i] > a[mx])    mx = i;
    }
    string x;
    cin >> x;
    x = " " + x;
    if(x[1] == '1' || x[n] == '1' || x[mn] == '1' || x[mx] == '1') {
        cout << -1 << endl;
        return;
    }

    cout << 5 << endl;
    cout << 1 << " " << mn << endl;
    cout << 1 << " " << mx << endl;
    cout << mn << " " << n << endl;
    cout << mx << " " << n << endl;
    cout << min(mn, mx) << " " << max(mn, mx) << endl;
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