#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    long long a, b;
    cin >> a >> b;

    if (b%a == 0){
      cout << b * (b/a) << '\n';
    } else {
      cout << lcm(a, b) << '\n';
    }
  }
  return 0;
}
