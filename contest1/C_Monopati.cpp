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

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<int> preMin(n), preMax(n);
    preMin[0] = preMax[0] = a[0][0];
    for (int j = 1; j < n; j++)
    {
        preMin[j] = min(preMin[j - 1], a[0][j]);
        preMax[j] = max(preMax[j - 1], a[0][j]);
    }

    vector<int> sufMin(n), sufMax(n);
    sufMin[n - 1] = sufMax[n - 1] = a[1][n - 1];
    for (int j = n - 2; j >= 0; j--)
    {
        sufMin[j] = min(sufMin[j + 1], a[1][j]);
        sufMax[j] = max(sufMax[j + 1], a[1][j]);
    }

    vector<pair<int, int>> path(n);
    for (int j = 0; j < n; j++)
    {
        int L = min(preMin[j], sufMin[j]);
        int R = max(preMax[j], sufMax[j]);
        path[j] = {L, R};
    }

    int mx = 2 * n;
    vector<vector<int>> mp(mx + 1);
    for (auto [L, R] : path)
        mp[L].push_back(R);

    multiset<int> s;
    long long ans = 0;

    for (int l = mx; l >= 1; l--)
    {
        for (int R : mp[l])
            s.insert(R);
        int mnR = s.empty() ? mx + 1 : *s.begin();
        int start = max(l, mnR);
        if (start <= mx)
            ans += (mx - start + 1);
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

