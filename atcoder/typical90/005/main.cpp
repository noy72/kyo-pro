#include <ctgmath>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
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

const int MOD = 1e9 + 7;

int main() {
  int c = 0;
  rep(i, 100000) {
    c += 3;
    if (c < 1000)
      continue;
    if (c > 10000)
      break;
    if (to_string(c).find('0') != string::npos) {
      continue;
    }
    cout << c << endl;
  }

  /*
int n, b, k;
cin >> n >> b >> k;
vector<int> c(k);
cin >> c;

vector<vector<long long>> dp = vectors(n + 1, b, 0ll);
dp[0][0] = 1;
rep(i, n) {
          rep(j, b){

          }
}
*/

  /*
  int b = 24;
  range(i, 1, 10) {
    long long c = 1e9;
    while (true) {

      cout << c * i % b << ' ';
      c /= 10;
      if (c == 0)
        break;
    }
    cout << endl;
  }
        */
}
