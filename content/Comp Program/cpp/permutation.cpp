#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n = 3;
  vector<int> permutation;
  for (int i = 0; i < n; i++) {
    permutation.push_back(i);
  }
  do {
    for (int i = 0; i < n; i++) {
      cout << permutation[i] << " ";
    }
    cout << '\n';
  } while (next_permutation(permutation.begin(),permutation.end()));

  return 0;
}
