#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    int n;
    cin >> n;

    long long x, sum = 0;
    for(int i=0; i<n; i++){
      cin >> x;
      sum += x;
    }

    long long ans = (sum%n) * (n-(sum%n));
    cout << ans << '\n';
  }

  return 0;
}
