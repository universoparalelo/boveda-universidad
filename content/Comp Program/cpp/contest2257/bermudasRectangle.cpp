#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    int S, q;
    cin >> S >> q;

    vector<pair<int, int>> querys(q);
    for(int i=0; i<q; i++){
      int x, y; cin >> x >> y;
      vector[i] = {x, y};
    }

    vector<pair<long long, int> factors;
    int temp = S;
    for (int d=2; d*d<=temp; d++){
      if(temp%d == 0){
        int cnt = 0;
        while(temp%d==0) {
          temp/=d; cnt++;
        }
        factors.push_back({d,cnt});
      }
    }
    if(temp>1) factors.push_back({temp,1});

    vector<long long> divs = {1};
    for(auto& [p, e] : factors){
      long long pw = 1;
      int sz = divs.size();
      for (int j=1; j<=e; j++){
        pw *= p;
        for (int i=0; i<sz; i++){
          divs.push_back(divs[i]*pw);
        }
      }
    }

    sort(divs.begin(), divs.end());
    int r = divs.size();

    //no hay chance q copie y pegue
  }

  return 0;
}
