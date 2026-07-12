#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k, l, m, n, d;
  cin >> k >> l >> m >> n >> d;

  long long sum = 0;

  for (int i=1; i<d+1; i++){
    if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0){
      sum++;
    }
  }
  cout << sum << '\n';

  return 0;
}
