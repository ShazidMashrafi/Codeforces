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
    ll n, mx = 1;
    cin >> n;
    for(ll i = 2; i <= n; ++i)
        mx *= i;

    deque<ll> a, b;

    ll k;
    cin >> k;
    for(ll i = 0; i < k; ++i)
    {
        ll x;
        cin >> x;
        a.push_back(x);
    }

    cin >> k;
    for(ll i = 0; i < k; ++i)
    {
        ll x;
        cin >> x;
        b.push_back(x);
    }
    // dbg(a, b);

    ll ct = 0;
    while(!a.empty() && !b.empty())
    {
        ll x = a.front();
        ll y = b.front();
        // dbg(x, y);
        a.pop_front();
        b.pop_front();
        if(x > y)
        {
            a.push_back(y);
            a.push_back(x);
        }
        else
        {
            b.push_back(x);
            b.push_back(y);
        }
        ct++;

        if(ct > mx)
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << ct << " " << (a.empty() ? 2 : 1) << endl;
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