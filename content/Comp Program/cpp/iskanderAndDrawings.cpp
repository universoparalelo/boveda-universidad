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

    char x;
    long long count = 0, max = 0;

    for (int i=0; i<n; i++){
      cin >> x;
      if (x == '#'){
        count++;
        if (count > max){
          max = count;
        }
      } else {
        count = 0;
      }
    }
    
    if (max % 2 == 0){
      cout << max / 2 << '\n';
    } else {
      cout << (max / 2) + 1 << '\n';
    }
  }

  return 0;
}
