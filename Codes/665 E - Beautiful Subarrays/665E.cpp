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

class Trie {
private:
    struct TrieNode {
        TrieNode* children[2];
        ll count;
        
        TrieNode() {
            for (ll i = 0; i < 2; i++)
                children[i] = nullptr;
            count = 0;
        }
    };
    
    TrieNode* root;
    const ll MAXBIT = 30;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(ll num) {
        TrieNode* node = root;
        for(ll i = MAXBIT; i >= 0; --i) {
            ll bit = (num >> i) & 1;
            if(!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
            node->count++;
        }
    }

    ll count(ll num, ll k) {
        TrieNode* node = root;
        ll result = 0;

        for(ll i = MAXBIT; i >= 0 && node; --i) {
            ll nb = (num >> i) & 1;
            ll kb = (k >> i) & 1;

            if(kb) {
                node = node->children[1 - nb];
            } else {
                if(node->children[1 - nb]) {
                    result += node->children[1 - nb]->count;
                }
                node = node->children[nb];
            }
        }

        if(node) {
            result += node->count;
        }
        
        return result;
    }
};

void solve()
{
    ll n, k;
    cin >> n >> k;

    Trie trie;
    trie.insert(0);

    ll ans = 0;
    ll pre = 0;
    for(ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        pre ^= a;
        
        ans += trie.count(pre, k);
        trie.insert(pre);

    }
    cout << ans << endl;
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