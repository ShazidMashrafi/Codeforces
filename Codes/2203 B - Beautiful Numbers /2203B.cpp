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
    string x;
    cin >> x;
    int sum = 0;
    for (char c : x) {
        sum += c - '0';
    }

    if (sum <= 9) { 
        cout << 0 << endl; 
        return; 
    }

    int diff = sum - 9;
    vector<int> v;
    for (int i = 0; i < sz(x); i++) {
        int d = x[i] - '0';
        v.pb(i ? d : d - 1);
    }
    sort(all(v), greater<int>());

    int ans = 0, tot = 0;
    for (int r : v) {
        if (tot >= diff) break;
        tot += r;
        ans++;
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