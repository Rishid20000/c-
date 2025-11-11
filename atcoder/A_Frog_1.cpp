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

void solve() {
        int n;
        cin>>n;
        vector<int>vec(n);
        for(auto &i:vec) cin>>i;
        vector<int>dp(n,0);
        dp[0] =0;
        dp[1] = abs(vec[0]-vec[1]);
        for(int i=2;i<n;i++){
            int cost = abs(vec[i]-vec[i-1]);
            int cost2 = abs(vec[i-2]-vec[i]);
            dp[i] =  min(dp[i-1]+cost,dp[i-2]+cost2);
        }
        cout<<dp[n-1]<<"\n";
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