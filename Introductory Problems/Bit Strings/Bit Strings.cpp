// Problem: Bit Strings
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1617
// Memory Limit: 512
// Time Limit: 1000
// Start: 10/12/2023 17:35

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

ll binpow(ll base, ll exponent, ll mod) {
  base %= mod;
  ll result = 1;
  while (exponent > 0) {
    if (exponent & 1)
      result = result * base % mod;
    base = base * base % mod;
    exponent >>= 1;
  }
  return result;
}

int main() {
  GO FAST;
  int n;
  cin >> n;
  cout << binpow(2, n, (ll)1e9 + 7);
  return 0;
}
