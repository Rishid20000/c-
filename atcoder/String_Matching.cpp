#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 + 7, inf = 1e9;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

template <typename T>
void printv(const vector<T> &v) {
    for (auto &e : v) cout << e << ' ';
    cout << '\n';
}

template <typename T>
void inputv(vector<T> &v) {
    for (auto &e : v) cin >> e;
}

vector<ll> sieve(ll n) {
    vector<ll> prime(n + 1, 1);
    prime[0] = prime[1] = 0;
    for (ll i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (ll j = i * i; j <= n; j += i)
                prime[j] = 0;
        }
    }
    vector<ll> primes;
    for (ll i = 2; i <= n; i++)
        if (prime[i]) primes.pb(i);
    return primes;
}

vector<ll> compute(auto &pat){
    int n = pat.size();
    vector<ll>lps(n);
    int i=1;
    int len=0;
    while(i<n){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
                if(len!=0) len = lps[len-1];
                else{
                    len=0;
                    lps[i]=0;
                    i++;
                }
        }
    }

    return lps;
}

ll count(auto lps,string text,string pat){
    int n = text.size(),m=pat.size();
    int i=0,j=0;
    ll cnt=0;
    while(i<n && j<m){
        if(text[i]==pat[j]){
            i++;
            j++;
            
        }else{
                if(j!=0) j = lps[j-1];
                else {
                        i++; 
                }   
        }

        if (j == m)
        {
            cnt++;
            j = lps[j-1];
        }
    }

    return cnt;
}

void solve() {
    string text;
    string pat;
    cin>>text>>pat;
    vector<ll> lps  = compute(pat);


    ll ans = count(lps,text,pat);
    cout<<ans<<"\n";


}

int main() {
    fast_io;
    int t;
    // cin >> t;
    t=1;
    while (t--) {
        solve();
    }
    return 0;
}