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
    string a,b;
    cin>>a>>b;
    int n = a.size(),m=b.size();
    vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=n,j=m;
    string lcs;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            lcs+=a[i-1];
            i--,j--;
        }else{
             if(dp[i-1][j]>dp[i][j-1]){
                i--;
             }else{
                    j--;
             }
        }
    }
    reverse(lcs.begin(),lcs.end());
    cout<<lcs<<"\n";
}

int main() {
    fast_io;
    int t;
    // cin >> t;t
    t=1;
    while (t--) {
        solve();
    }
    return 0;
}