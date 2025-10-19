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
    
    if (n == 0) {
        yn(1);
        return;
    }
    
    for (int len = 1; len <= 60; len++) {
        if (n >= (1LL << len)) continue;
        
        bool f = true;
        
        for (int i = 0; i < len; i++) {
            int j = len - 1 - i;
            bool bi = (n >> i) & 1;
            bool bj = (n >> j) & 1;
            
            if (i == j && bi == 1) {
                f = 0;
                break;
            }
            
            if (i < j && bi != bj) {
                f = 0;
                break;
            }
        }
        
        if (f) {
            yn(1);
            return;
        }
    }
    
    yn(0);
}

signed main() {
    FAST;
    
    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC) {
        solve();
    }
}