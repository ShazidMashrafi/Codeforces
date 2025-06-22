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
    ll q;
    cin >> q;
    deque<ll>d, rd;
    ll riz = 0, r_riz = 0, tot = 0, n = 0;
    while(q--)
    {
        ll s;
        cin >> s;
        if(s == 1)
        {
            ll k = d.back();
            d.pop_back();
            d.push_front(k);
            riz -= n * k;
            riz += k;
            riz += (tot - k);

            k = rd.front();
            rd.pop_front();
            rd.push_back(k);
            r_riz -= k;
            r_riz += n * k;
            r_riz -= (tot - k);

        }
        else if(s == 2)
        {
            swap(riz, r_riz);
            swap(d, rd);
        }
        else
        {
            n++;
            ll k;
            cin >> k;
            tot += k;
            
            d.push_back(k);
            riz += n * k;

            rd.push_front(k);
            r_riz += k;
            r_riz += (tot - k);
        }
        cout << riz << endl;
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