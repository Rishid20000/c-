#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 + 7, inf = 1e9;
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

template <typename T>
void printv(const vector<T> &v)
{
    for (auto &e : v)
        cout << e << ' ';
    cout << '\n';
}

template <typename T>
void inputv(vector<T> &v)
{
    for (auto &e : v)
        cin >> e;
}

vector<ll> sieve(ll n)
{
    vector<ll> prime(n + 1, 1);
    prime[0] = prime[1] = 0;
    for (ll i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (ll j = i * i; j <= n; j += i)
                prime[j] = 0;
        }
    }
    vector<ll> primes;
    for (ll i = 2; i <= n; i++)
        if (prime[i])
            primes.pb(i);
    return primes;
}

vector<ll>dp;

int frog(int index,vector<int>&vec,int &k){
        if(index==vec.size()-1) return 0;
        if(index>=vec.size()) return 1e15;
        if(dp[index]!=-1) return dp[index];
        ll mini = 1e9;
        for(int i=index+1;i<=(index+k);i++){
            ll cost = abs(vec[i]-vec[index]);
            ll jump = frog(i,vec,k);
            mini = min(mini,cost+jump);
        }

        return dp[index] = mini;

}

void solve()
{
    int n;
    cin >> n;
    int k;
    cin>>k;
    vector<int> vec(n);
    for (auto &i : vec)
        cin >> i;
    dp.resize(n+1,0);
    
    dp[n-1] = 0;
    for(int i=n-2;i>=0;i--){
        int mini =1e9;
        for(int j=(i+1);j<=(i+k) && j<n;j++){
                int cost = abs(vec[i]-vec[j]);
                int total = cost+dp[j];
                mini =min(mini,total);
        }
        dp[i] = mini;
    }

    cout<<dp[0]<<"\n";

}

int main()
{
    fast_io;
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}