// Problem: Exponentiation II
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1712
// Memory Limit: 512
// Time Limit: 1000
// Start: 16/02/2024 22:51

#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#define ll long long
#define ull unsigned ll
#define ld long double
#define range(a) a.begin(), a.end()
#define GO ios_base::sync_with_stdio(false);
#define FAST cin.tie(nullptr);
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tuple<ll, ll, ll> tll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;

#define MOD 1000000007

ll binpow(ll a, ll b, ll mod) {
  if (b == 0) {
    return 1;
  }
  ll r = binpow(a, b / 2, mod);
  r = r * r % mod;
  if (b & 1) {
    r = r * a % mod;
  }
  return r;
}

int main() {
  GO FAST;
  ll n;
  cin >> n;
  while (n--) {
    ll a, b, c;
    cin >> a >> b >> c;
    ll tmp = binpow(b, c, MOD - 1);
    cout << binpow(a, tmp, MOD) << '\n';
  }
  return 0;
}
