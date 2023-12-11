// Problem: Counting Rooms
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1192
// Memory Limit: 512
// Time Limit: 1000
// Start: 11/12/2023 03:06

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

int height, width;
vi adj_horizontal = {1, -1, 0, 0};
vi adj_vertical = {0, 0, 1, -1};

bool in_bounds(const int &row, const int &column) {
  return row >= 0 and row < height and column >= 0 and column < width;
}

void dfs(const vector<vector<char>> &matrix, vvb &visited, const int &row,
         const int &column) {
  if (visited[row][column]) {
    return;
  }
  visited[row][column] = true;
  for (int i{0}; i < 4; ++i) {
    int new_column = column + adj_horizontal[i];
    int new_row = row + adj_vertical[i];
    if (in_bounds(new_row, new_column) and matrix[new_row][new_column] == '.') {
      dfs(matrix, visited, new_row, new_column);
    }
  }
}

int main() {
  GO FAST;
  cin >> height >> width;
  vector<vector<char>> matrix(height, vector<char>(width));
  for (int row{0}; row < height; ++row) {
    for (int column{0}; column < width; ++column) {
      cin >> matrix[row][column];
    }
  }

  int ans{0};
  vvb visited(height, vb(width, false));
  for (int row{0}; row < height; ++row) {
    for (int column{0}; column < width; ++column) {
      if (not visited[row][column] and matrix[row][column] == '.') {
        dfs(matrix, visited, row, column);
        ++ans;
      }
    }
  }
  cout << ans;
  return 0;
}
