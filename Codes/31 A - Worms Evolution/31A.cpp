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
    vector<pair<int, int>> v;
    for(int i = 0; i < n; ++i) {
    	int x;
    	cin >> x;
    	v.pb({x, i + 1});
    }
    sort(all(v), greater<pair<int, int>>());
    for(int i = 0; i < n - 2; ++i) {
    	for(int j = i + 1; j < n - 1; ++j) {
    		for(int k = j + 1; k < n; ++k) {
    			if(v[i].ff == v[j].ff + v[k].ff) {
    				cout << v[i].ss << " " << v[j].ss << " " << v[k].ss << endl;
    				// cout << v[i].ff << " " << v[j].ff << " " << v[k].ff << endl;
    				return;
    			}
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
    // cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}