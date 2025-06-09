#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll power(ll x,ll y,ll m=1e9+7){ll ans=1;x%=m;while(y){if(y&1)ans=(ans*x)%m;x=(x*x)%m;y>>=1;}return ans;}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int mn = min({a/3, b/2, c/2});
    a -= 3 * mn;
    b -= 2 * mn;
    c -= 2 * mn;

    //cout << a << " " << b << " " << c << endl;
    
    int mx = 0;
    for(int i = 0; i < 7; ++i)
    {
        int ct = 0, j = i, k = 7;
        int ta = a, tb = b, tc = c;
        while(k--)
        {
            //cout << i << " " <<  j << " " << ta << " " << tb << " " << tc << " " << ct << endl; 
            if((i + j) % 7 == 0 && ta > 0)
            {
                ta--;
                ct++;
            }
            else if((i + j) % 7 == 1 && ta)
            {
                ta--;
                ct++;
            }
            else if((i + j) % 7 == 2 && tb)
            {
                tb--;
                ct++;
            }
            else if((i + j) % 7 == 3 && tc)
            {
                tc--;
                ct++;
            }
            else if((i + j) % 7 == 4 && ta)
            {
                ta--;
                ct++;
            }
            else if((i + j) % 7 == 5 && tc > 0)
            {
                tc--;
                ct++;
            }
            else if((i + j) % 7 == 6 && tb)
            {
                tb--;
                ct++;
            }
            else break;
            j++;
        }
        //cout << ct << " " << mx << endl;
        mx = max(mx, ct);
        //cout << mx << endl; 
    }

    int ans = mn * 7 + mx;
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int TCS = 1;
    // cin >> TCS;
    for (int TC = 1; TC <= TCS; ++TC)
    {
        // cout<<"Case "<<TC<<": ";
        solve();
    }
}