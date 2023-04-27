/*------------------Author: Hsin-Yu Hsieh------------------*/
/*First Trial:  DP (v & i)    T:164 96.59%   M:10.6  50.54%*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n==1)    return 1;
        vector<long long int> ni(primes.size());
        vector<long long int> nv(primes.size());
        vector<long long int> ans(n);
        ans[0] = 1;
        for(int i=0; i<nv.size(); i++)  nv[i] = primes[i];
        for(int i=1; i<n; i++){
            long long int tmp=-1;
            for(int j=0; j<nv.size(); j++){
                if(nv[j]<tmp&&nv[j]>ans[i-1] || tmp<0)   tmp = nv[j];
            }
            ans[i] = tmp;
            for(int j=0; j<nv.size(); j++){
                if(nv[j]<=tmp){
                    nv[j] = ans[(++ni[j])]*primes[j];
                }
            }
        }
        return ans[n-1];
    }
};