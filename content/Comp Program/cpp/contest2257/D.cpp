#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        ll S; int q;
        cin >> S >> q;

        // 1. factorizar S en O(sqrt(S))
        vector<pair<ll,int>> factors;
        ll temp = S;
        for(ll d=2; d*d<=temp; d++){
            if(temp % d == 0){
                int cnt=0;
                while(temp % d == 0){ temp/=d; cnt++; }
                factors.push_back({d,cnt});
            }
        }
        if(temp > 1) factors.push_back({temp,1});

        // 2. generar todos los divisores a partir de la factorizacion
        vector<ll> divs = {1};
        for(auto& [p, e] : factors){
            int sz = divs.size();
            ll pw = 1;
            for(int k=1; k<=e; k++){
                pw *= p;
                for(int i=0; i<sz; i++){
                    divs.push_back(divs[i]*pw);
                }
            }
        }
        sort(divs.begin(), divs.end());
        int r = divs.size();

        // 3. prefijos: PV[k] = suma_{j=1}^{k} len_j * v_j  (1-indexado, PV[0]=0)
        //    len_j = a_j - a_{j-1},  v_j = S / a_j
        vector<ll> PV(r+1, 0);
        for(int k=1; k<=r; k++){
            ll len = divs[k-1] - (k>=2 ? divs[k-2] : 0LL);
            ll v = S / divs[k-1];
            PV[k] = PV[k-1] + len*v;
        }

        // 4. responder queries
        while(q--){
            ll x, y;
            cin >> x >> y;

            // p = cantidad de divisores <= x
            int p = upper_bound(divs.begin(), divs.end(), x) - divs.begin();

            // k0_global = cantidad de divisores <= floor(S/y)
            ll thresh = S / y;
            int k0g = upper_bound(divs.begin(), divs.end(), thresh) - divs.begin();

            int k0 = min(k0g, p);

            ll a_k0 = divs[k0-1];         // k0 siempre >= 1
            ll sumPart1 = y*a_k0 + (PV[p] - PV[k0]);

            ll partial = 0;
            ll a_p = divs[p-1];
            if(a_p < x){
                // hay un grupo parcial usando el siguiente divisor
                ll v_next = S / divs[p];  // divs[p] es a_(p+1), 0-indexado
                partial = (x - a_p) * min(y, v_next);
            }

            cout << (sumPart1 + partial) << '\n';
        }
    }
    return 0;
}
