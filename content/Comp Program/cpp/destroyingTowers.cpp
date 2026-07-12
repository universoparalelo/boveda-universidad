#include <bits/stdc++.h>
using namespace std;

int main(){
  int T;
  cin >> T;

  while (T--){
    int n;
    cin >> n;
    vector<int> towers(n);
    for (int i=0; i<n; i++){
      cin >> towers[i];
    }

    long long points = 0;
    int minTower = 1001;
    for (int i=0; i<n; i++){
      if (towers[i] < minTower){
        minTower = towers[i];
      }
      
      points += minTower;
    }
    cout << points << '\n';
  }
  return 0;
}
