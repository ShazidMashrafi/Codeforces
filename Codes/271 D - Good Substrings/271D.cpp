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
        TrieNode* children[26];
        bool isMarked;

        TrieNode() {
            isMarked = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };
    
    TrieNode* root;
    ll distinct = 0;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string &s, string &t, ll k, ll i) {
        TrieNode* node = root;
        ll ct = 0;
        for(ll j = i; j < sz(s); ++j) {
            char ch = s[j];
            if(t[ch - 'a'] == '0')  ct++;
            if(ct > k)  break;

            int index = ch - 'a';
            if(!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];

            if(!node->isMarked) {
                node->isMarked = true;
                distinct++;
            }
        }
    }

    ll getCount() {
        return distinct;
    }
};

void solve()
{
    string s, t;
    ll k;
    cin >> s >> t >> k;
    Trie trie;

    for(ll i = 0; i < sz(s); ++i) {
        trie.insert(s, t, k, i);
    }
    
    cout << trie.getCount() << endl;
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