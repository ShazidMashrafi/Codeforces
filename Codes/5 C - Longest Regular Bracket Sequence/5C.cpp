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
    string s;
    cin >> s;
    ll n = sz(s);

    vector<int> opens(n, -1), start(n, -1);
    stack<int>st;

    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '(') st.push(i);
        else
        {
            if(!st.empty())
            {
                ll open = st.top();
                st.pop();
                opens[i] = open;
                if(open > 0 && s[open - 1] == ')' && start[open - 1] != -1)
                    start[i] = start[open - 1];
                else
                    start[i] = open;
            }
        }
    }

    ll mx = 0, len = 0;
    map<ll, ll> mp;
    for(int i = 0; i < n; ++i)
    {
        if(start[i] != -1)
        {
            len = i - start[i] + 1;
            mx = max(mx, len);
            mp[len]++;
        }
    }
    
    if(mx == 0)
        cout << "0 1" << endl;
    else
        cout << mx << " " << mp[mx] << endl;
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