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
    char c;
    string s;
    cin >> n >> c >> s;
    bool same = true;
    for(auto x : s)
    {
        if(x != c)
        {
            same = false;
            break;
        }
    }
    if(same)
    {
        cout << 0 << endl;
        return;
    }

    for(int i = 1; i <= n; ++i)
    {
        bool valid = true;
        for(int j = i; j <= n; j += i)
        {
            if(s[j - 1] != c)
            {
                valid = false;
                break;
            }
        }
        if(valid)
        {
            cout << 1 << endl << i << endl;
            return;
        }
    }

    cout << 2 << endl << n << " " << n - 1 << endl;
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