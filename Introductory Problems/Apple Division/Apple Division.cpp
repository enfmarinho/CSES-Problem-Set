// Problem: Apple Division
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1623
// Memory Limit: 512
// Time Limit: 1000
// Start: 11/12/2023 02:35

#include <climits>
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

vll values;
ll sum_all{0};
ll ans{INT_MAX};

void dp(ll index, ll curr_sum) {
  if (index == values.size()) {
    ans = min(ans, abs(2 * curr_sum - sum_all));
  } else {
    dp(index + 1, curr_sum + values[index]);
    dp(index + 1, curr_sum);
  }
}

int main() {
  GO FAST;
  int n;
  cin >> n;
  values.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> values[i];
    sum_all += values[i];
  }

  dp(0, 0);
  cout << ans;
  return 0;
}
