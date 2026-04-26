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
   	vector<int>v1(3), v2(3);
   	cin >> v1[0] >> v1[1] >> v1[2] >> v2[0] >> v2[1] >> v2[2];
   	int ans = 0, ct;

   	// dbg(v1, v2);
   	
   	ct = min(v1[2], v2[1]);
   	ans += 2 * ct;
   	v1[2] -= ct;
   	v2[1] -= ct;

   	ct = min(v1[0], v2[2]);
   	v1[0] -= ct;
   	v2[2] -= ct;

   	ct = min(v1[1], v2[0]);
   	v1[1] -= ct;
   	v2[0] -= ct;

   	ans -= 2 * min(v1[1], v2[2]);

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