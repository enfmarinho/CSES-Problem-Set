// Problem: Grid Paths
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1638
// Memory Limit: 512
// Time Limit: 1000
// Start: 11/01/2024 00:28

#include <iostream>
#include <vector>
#define ll long long
#define GO ios_base::sync_with_stdio(false);
#define FAST cin.tie(nullptr);
using namespace std;

#define mod 1000000007

ll dp(int i, int j, const vector<vector<char>> &m, vector<vector<ll>> &memo) {
  if (i < 0 or j < 0) {
    return 0;
  }
  if (m[i][j] == '*') {
    return memo[i][j] = 0;
  }
  if (memo[i][j] != -1) {
    return memo[i][j];
  }
  if (i == 0 and j == 0) {
    return memo[i][j] = 1;
  }
  return memo[i][j] = (dp(i - 1, j, m, memo) + dp(i, j - 1, m, memo)) % mod;
}

int main() {
  GO FAST;
  int n;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> grid[i][j];
    }
  }

  vector<vector<ll>> memo(n, vector<ll>(n, -1));
  dp(n - 1, n - 1, grid, memo);
  cout << memo[n - 1][n - 1];
  return 0;
}
