#include <bits/stdc++.h>
using namespace std;
#if defined(LOCAL) && !defined(ONLINE_JUDGE)
#include "debug.h"
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
    ll n, t, s;
    cin >> n >> t >> s;
    string str;
    cin >> str;

    auto eval = [&](int m) -> ll {
        ll ct = 0, ans = 0;
        for (char c : str) {
            if (c == 'I') {
                if (ct < t) {
                    ct++;
                    ans++;
                }
            } else if (c == 'E') {
                if (ans < ct * s) ans++;
            } else {
                if (m > 0) {
                    m--;
                    if (ct < t) {
                        ct++;
                        ans++;
                    }
                } else {
                    if (ans < ct * s) ans++;
                }
            }
        }
        return ans;
    };

    int l = 0, r = 0;
    for (char c : str) {
        if (c == 'A') r++;
    }

    while (l < r) {
        int m = l + (r - l) / 2;
        ll x = eval(m);
        ll y = eval(m + 1);

        if (x < y) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    cout << eval(l) << endl;
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