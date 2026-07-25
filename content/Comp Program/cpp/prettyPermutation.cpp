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

    if (n == 2){
      cout << "2 1" << '\n';
    } else {
      for (int i=1; i<=n-3; i+=2){
        cout << i+1 << " " << i << " ";
      }
      if (n%2 == 0){
        cout << n << " " << n-1 << '\n';
      } else {  
        cout << n << " " << n-2 << " " << n-1 << '\n';
      }
    }

  }

  return 0;
}
