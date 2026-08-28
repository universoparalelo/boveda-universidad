#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    int n, m;
    cin >> n >> m;
    vector<int> b(n), v(m);

    int totalB = 0, totalV = 0;
    for(int i=0; i<n; i++){
      cin >> b[i];
    }
    for(int i=0; i<m; i++){
      cin >> v[i];
    }

    for(int i=0; i<n-1; i++){
      totalB += (b[i]-(b[i+1]-1));
    }
    totalB += b.back();

    for(int i=0; i<m-1; i++){
      totalV += (v[i]-(v[i+1]-1));
    }
    totalV += v.back();

    if(totalB >= totalV){
      cout << "1" << '\n';
    } else{
      cout << "2" << '\n';
    }
  }

  return 0;
}
