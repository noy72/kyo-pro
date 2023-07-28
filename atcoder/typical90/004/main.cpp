#include <ctgmath>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define range(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, b) for (int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x) cerr << #x << " = " << (x) << endl;
using namespace std;

template <typename X, typename T> auto vectors(X x, T a) {
  return vector<T>(x, a);
}
template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
  auto cont = vectors(y, z, zs...);
  return vector<decltype(cont)>(x, cont);
}
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {
  rep(i, v.size()) { os << v[i] << (i == v.size() - 1 ? "" : " "); }
  return os;
}
template <typename T> istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v) {
    is >> x;
  }
  return is;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> b = vectors(h, w, 0);
  rep(i, h) { cin >> b[i]; }

  vector<int> row(h, 0);
  vector<int> col(w, 0);
  rep(i, h) rep(j, w) row[i] += b[i][j];
  rep(i, w) rep(j, h) col[i] += b[j][i];

  vector<vector<int>> ans = vectors(h, w, 0);
  rep(i, h) {
    rep(j, w) { ans[i][j] = row[i] + col[j] - b[i][j]; }
  }

  rep(i, h) { cout << ans[i] << endl; }
}
