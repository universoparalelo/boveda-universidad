#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<long long> v(n);
  for(int i=0; i<n; i++) cin >> v[i];

  long long suma=0;

  for(int i=1; i<n; i++){
    if(v[i]<v[i-1]){
      suma += v[i-1] - v[i];
      v[i] = v[i-1];
    }
  }

  cout << suma << '\n';

  return 0;
}
