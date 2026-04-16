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
    map<int, int> mp;
    for(int i = 0; i < 6; ++i) {
        int x;
        cin >> x;
        mp[x]++;
    }

    int mx = 0;
    for(auto [x, ct] : mp) {
        mx = max(mx, ct);
    }

    if(mx < 4) {
        cout << "Alien" << endl;
        return;
    }

    if(mx == 4) {
        if(sz(mp) == 2) {
            cout << "Elephant" << endl;
        } else {
            cout << "Bear" << endl;
        }
    } 
    else if(mx == 5) {
        cout << "Bear" << endl;
    }
    else {
        cout << "Elephant" << endl;
    }
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