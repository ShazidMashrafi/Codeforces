#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include <debug.h>
#endif
#define  int  long long
#define  ll  long long
#define  endl  '\n'
#define  ff  first
#define  ss  second
#define  ins  insert
#define  pb  push_back
#define  ppb  pop_back
#define  sz(x)  (int)(x).size()
#define  all(x)  x.begin(), x.end()
#define  rep(i,a,b)  for(int i=a; i<b; ++i)
#define  rrep(i,a,b) for(int i=a; i>=b; --i)
#define  yn(f)  f? cout<<"YES\n":cout<<"NO\n"
#define  FAST  (ios_base::sync_with_stdio(false), cin.tie(nullptr));
ll pow(ll x,ll y,ll m=1e9+7) {ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    if(s[0] != 'M' || s[n - 1] != 'T')
    {   
        yn(0);
        return;
    }
    for(auto c: s)
    {
        if(c != 'M' && c != 'I' && c!= 'T')
        {
            yn(0);
            return;
        }
    }
    for(int i=1; i<n; ++i)
    {
        if(s[i] == s[i-1])
        {
            yn(0);
            return;
        }
        if(s[i]=='M' && s[i-1]!='T')
        {
            yn(0);
            return;
        }
        if(s[i]=='I')
        {
            if(s[i-1]!='M' && s[i-1]!='T')
            {
                yn(0);
                return;
            }
        }
        if(s[i]=='T' && s[i-1] !='I')
        {
            yn(0);
            return;
        }
    }
    yn(1);
}

signed main()
{
    FAST;
    int TCS = 1;
    cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}