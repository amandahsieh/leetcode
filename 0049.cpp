/*----------------------Author: Hsin-Yu Hsieh-----------------------*/
/*First Trial: Sort, match, push back   T:33 91.48%     M:19.8 72.9%*/

/*First Trial: Sort, match, push back, steps are the followings*/
//Sort the strings in the vector, and store the result in another vector
//Match the sorted string in the new vector with unordered map
//Store the original strings to ans according to the index of the unordered map
class Solution {
public:
    struct cmp{
        bool operator()(char a, char b){
            return a<b;
        }
    };
    string Sort(string s){
        sort(s.begin(), s.end(), cmp());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> sorted(strs.size());
        unordered_map<string, int> um;
        int v=1;
        for (int i=0; i<strs.size(); i++) sorted[i]=Sort(strs[i]);
        for (int i=0; i<strs.size(); i++){
            if (!um[sorted[i]]){
                um[sorted[i]]=v++;
                vector<string> tmp(1, strs[i]);
                ans.push_back(tmp);
                continue;
            } 
            ans[um[sorted[i]]-1].push_back(strs[i]);
        }
        return ans;
    }
};