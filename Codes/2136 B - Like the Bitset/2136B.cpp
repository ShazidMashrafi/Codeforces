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
    string s;
    cin >> n >> k >> s;
    int ct = 0, mx = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '1') ct++;
        else {
            mx = max(mx, ct);
            ct = 0;
        }
    }
    mx = max(mx, ct);
    if(mx >= k)  {
        yn(0);
        return;
    }

    int val = n;
    vector<int>ans(n);
    for(int i = 0; i < n; ++i)    {
        if(s[i] == '0') ans[i] = val--;
    }
    for(int i = 0; i < n; ++i)    {
        if(s[i] == '1') ans[i] = val--;
    }
    yn(1);
    for(auto x : ans) cout << x << " ";
    cout << endl;
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