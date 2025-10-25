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

const ll MAXBIT = 30;

class Trie {
private:
    struct TrieNode {
        TrieNode* children[2];
        ll maxIndex;
        
        TrieNode() {
            maxIndex = -1;
            for (ll i = 0; i < 2; i++)
                children[i] = nullptr;
        }
    };
    
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(ll num, ll index) {
        TrieNode* node = root;
        node->maxIndex = max(node->maxIndex, index);

        for(int i = MAXBIT; i >= 0; --i) {
            bool bit = (num >> i) & 1;
            if(!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
            node->maxIndex = max(node->maxIndex, index); 
        }
    }

    ll find(ll num, ll k) {
        TrieNode* node = root;
        ll result = -1;

        for(ll i = MAXBIT;  i >= 0; --i) {
            if(!node)   break;

            bool nb = (num >> i) & 1;
            bool kb = (k >> i) & 1;

            if(kb) {
                node = node->children[nb ^ 1];
            } else {
                if(node->children[nb ^ 1]) {
                    result = max(result, node->children[nb ^ 1]->maxIndex);
                }
                node = node->children[nb];
            }
        }

        if(node) {
            result = max(result, node->maxIndex);
        }

        return result;
    }
};

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll>a(n);
    for(auto &i : a)    cin >> i;

    if(k == 0) {
        cout << 1 << endl;
        return;
    }

    Trie trie;
    ll ans = INT_MAX;

    for(ll i = 0; i < n; ++i) {
        ll idx = trie.find(a[i], k);
        
        if(idx != -1) {
            ans = min(ans, i - idx + 1);
        }

        trie.insert(a[i], i);
    }

    cout << (ans == INT_MAX ? -1 : ans) << endl;
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