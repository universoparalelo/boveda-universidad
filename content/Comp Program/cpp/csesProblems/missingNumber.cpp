#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> v(n, 0);
  for(int i=1; i<n; i++){
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  
  for(int i=1; i<=n; i++){
    if(v[i] != i){
      cout << i << '\n';
      break;
    }
  }

  return 0;
}
