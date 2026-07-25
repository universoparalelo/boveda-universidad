#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    long long a, b, x;
    cin >> a >> b >> x;

    long long ans = 0;
    
    while (a > x && b > x){ 
      
    }

    if (a != b){
      if (a-b > 1){
        ans += 2;
      } else {
        ans++;
      }
    }

    cout << ans << '\n';
  }
  return 0;
}
