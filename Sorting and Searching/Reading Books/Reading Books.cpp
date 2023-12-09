// Problem: Reading Books
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1631
// Memory Limit: 512
// Time Limit: 1000
// Start: 09/12/2023 19:43

#include <algorithm>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#define ll long long
#define ull unsigned ll
#define ld long double
#define F first
#define S second
#define FF F.F
#define FS F.S
#define SS S.S
#define SF S.F
#define range(a) a.begin(), a.end()
#define GO ios_base::sync_with_stdio(false);
#define FAST cin.tie(nullptr);
#define FOR(i, limit) for (int i = 0; i < limit; i++)
#define MOD 1000000007
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

int main() {
  GO FAST;
  ll n, sum{0}, greatest{0};
  cin >> n;
  while (n--) {
    ll book;
    cin >> book;
    sum += book;
    greatest = max(greatest, book);
  }
  cout << max(sum, 2 * greatest);
  return 0;
}
