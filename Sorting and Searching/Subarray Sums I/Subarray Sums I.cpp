// Problem: Subarray Sums I
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1660
// Memory Limit: 512
// Time Limit: 1000
// Start: 09/12/2023 22:06

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
  int size, target;
  cin >> size >> target;
  vi values(size);
  for (int index{0}; index < size; ++index) {
    cin >> values[index];
  }
  int start{0}, end{0}, sum{0}, ans{0};
  while (end <= size) {
    if (sum < target) {
      sum += values[end++];
    } else if (sum > target) {
      sum -= values[start++];
    } else {
      ++ans;
      sum += values[end++];
    }
  }
  cout << ans;
  return 0;
}
