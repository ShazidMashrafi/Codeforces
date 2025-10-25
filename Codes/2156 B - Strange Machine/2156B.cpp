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
    int n, q;
    string s;
    cin >> n >> q >> s;
    
    while(q--) {
        ll a;
        cin >> a;
        
        ll t = 0;
        while(a > 0) {
            ll b = a;
            for(int i = 0; i < n; i++) {
                if(s[i] == 'A') {
                    a--;
                } else {
                    a /= 2;
                }
                if(a == 0) {
                    t += i + 1;
                    break;
                }
            }
    
            if(a == 0) break;
            
            t += n;
            ll r = b - a;
            
            if(r > 0 && a > r) {
                ll c = (a - 1) / r;
                t += c * n;
                a = a - c * r;
            }
        }
        cout << t << endl;
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