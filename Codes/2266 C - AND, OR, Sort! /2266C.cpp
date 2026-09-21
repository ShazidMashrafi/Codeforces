#include <bits/stdc++.h>
using namespace std;
#if defined(LOCAL) && !defined(ONLINE_JUDGE)
#include <debug.h>
#else
#define dbg(...)
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
    string s;
    cin >> n >> s;
    if(s[0] == '1') {
        cout << count(all(s), '0') << endl;
        return;
    }

    int i = 0, j = n - 1;
    while (i < n && s[i] == '0') i++;
    while (j >= 0 && s[j] == '1') j--;

    int o = 0, z = 0;
    for (int k = i; k <= j; ++k) {
        if (s[k] == '0') {
            z++;
        }
    }

    int best = z;
    for(int k = i; k <= j; ++k) {
        if(s[k] == '0') z--;
        else o++;
        best = min(best, o + z);
    }
    cout << best << endl;
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