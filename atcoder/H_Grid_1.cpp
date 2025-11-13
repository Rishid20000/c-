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
        int n,m;
        cin>>n>>m;
        vector<vector<char>>mat(n,vector<char>(m));

        for(auto &i:mat){
            for(auto &j:i)cin>>j;
        }

        vector<vector<long long >>dp(n+1,vector<long long>(m+1,0));
        vector<long long>newdp(m+1);
        for(int i=0;i<m;i++){ 
            if(mat[0][i]=='.') {
                newdp[i]=1;
            }else break;
        }

        for(int i=1;i<n;i++){
        //   if(mat[i][0]!='#')  dp[i][0] = dp[i-1][0];
            vector<long long>curr(m+1,0);
            if(mat[i][0]!='#') curr[0] = newdp[0];
            for(int j=1;j<m;j++){
                if(mat[i][j]=='#') continue;
                else{
                        curr[j] = (curr[j-1]+newdp[j])%mod;
                }
            }
            newdp = curr;
        }

        // for(auto i:dp){
        //     for(auto j:i)cout<<j<<" ";
        //     cout<<"\n";
        // }

        cout<<newdp[m-1]<<"\n";
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