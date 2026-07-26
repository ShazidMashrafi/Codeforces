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
    int n, k;
    cin >> n >> k;
    
    int b = n - k;
    for (int ch = 0; ch <= 1; ch++) {
        int b0, b1;
        if (ch == 0) {
            b0 = (b + 1) / 2;
            b1 = b / 2;
        } else {
            b1 = (b + 1) / 2;
            b0 = b / 2;
        }
        
        vector<pair<int, int>> v;
        if (n % 2 == 0) {
            v.push_back({n / 2, n / 2});
        } else {
            v.push_back({(n + 1) / 2, (n - 1) / 2});
            v.push_back({(n - 1) / 2, (n + 1) / 2});
        }
        
        for (auto [c0, c1] : v) {
            if (b0 == 0 && c0 > 0) continue;
            if (b1 == 0 && c1 > 0) continue;
            
            if (c0 >= b0 && c1 >= b1) {
                vector<int> blk0(b0, 1), blk1(b1, 1);
                if (b0 > 0) blk0[0] += (c0 - b0);
                if (b1 > 0) blk1[0] += (c1 - b1);
                
                string s = "";
                int idx0 = 0, idx1 = 0;
                int curr = ch;
                for (int i = 0; i < b; i++) {
                    if (curr == 0) {
                        while(blk0[idx0]--) {
                            s.pb('0');
                        }
                        idx0++;
                        curr = 1;
                    } else {
                        while(blk1[idx1]--) {
                            s.pb('1');
                        }
                        idx1++;
                        curr = 0;
                    }
                }
                cout << s << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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