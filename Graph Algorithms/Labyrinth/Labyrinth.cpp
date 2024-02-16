// Problem: Labyrinth
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1193
// Memory Limit: 512
// Time Limit: 1000
// Start: 11/12/2023 03:06

#include <algorithm>
#include <iostream>
#include <queue>
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

string get_path(vector<vector<char>> parents, pair<int, int> &curr) {
  string path;
  while (parents[curr.first][curr.second] != 'S') {
    char direction = parents[curr.first][curr.second];
    switch (direction) {
    case 'D':
      curr.first -= 1;
      break;
    case 'U':
      curr.first += 1;
      break;
    case 'R':
      curr.second -= 1;
      break;
    case 'L':
      curr.second += 1;
      break;
    }
    path.push_back(direction);
  }
  reverse(path.begin(), path.end());
  return path;
}

int h, w;
bool in_bounds(int i, int j) { return i >= 0 && i < h && j >= 0 && j < w; }

int main() {
  GO FAST;
  cin >> h >> w;
  vector<vector<char>> matrix(h, vector<char>(w));
  pair<int, int> A, B;
  for (int i{0}; i < h; ++i) {
    for (int j{0}; j < w; ++j) {
      cin >> matrix[i][j];
      if (matrix[i][j] == 'A') {
        A = {i, j};
      } else if (matrix[i][j] == 'B') {
        B = {i, j};
      }
    }
  }

  vector<vector<char>> parents(
      h, vector<char>(w, 0)); // Saves direction of origin of each node
  vector<pair<int, int>> adj{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  queue<pair<int, int>> q;
  q.push(A);
  parents[A.first][A.second] = 'S'; // Denotes Start.
  while (!q.empty()) {
    pair<int, int> position = q.front();
    q.pop();
    if (position.first == B.first && position.second == B.second) {
      cout << "YES\n";
      string path = get_path(parents, position);
      cout << path.size() << '\n';
      cout << path;
      return 0;
    }
    for (auto d : adj) {
      int i = position.first - d.first;
      int j = position.second - d.second;
      if (!in_bounds(i, j) || parents[i][j] != 0 || matrix[i][j] == '#') {
        continue;
      }
      if (d.first == 1) {
        parents[i][j] = 'U';
      } else if (d.first == -1) {
        parents[i][j] = 'D';
      } else if (d.second == 1) {
        parents[i][j] = 'L';
      } else if (d.second == -1) {
        parents[i][j] = 'R';
      }
      q.push({i, j});
    }
  }

  cout << "NO\n";
  return 0;
}
