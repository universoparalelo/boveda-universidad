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

    int x;
    int a = 0, b = 0, c = 0;
    for (int i=0; i<n; i++){
      cin >> x;
      if (x == 0){
        a++;
      } else if (x == 1){
        b++;
      } else {
        c++;
      }
    }

    if (b >= c){
      cout << a + c + (b-c)/3 << '\n';
    } else {
      cout << a + b + (c-b)/3 << '\n';
    }
  }
  return 0;
}
