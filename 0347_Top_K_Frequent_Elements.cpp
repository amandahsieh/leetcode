/*------------------Author: Hsin-Yu Hsieh------------------*/
/*First:  bucket, Push back     T:41 18.23%  M:17.2  8.33% */
/*Second: hash, priority queue  T:19 70.48%  M:13.6 76.47% */

class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second<b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int, int> pii;
        unordered_map <int, int> um;
        vector<int> ans(k);
        for (int i=0; i<nums.size(); i++){
            um[nums[i]]++;
        }
        priority_queue<pii,vector<pii>,cmp> v(um.begin(),um.end());
        for (int i=0 ; i<k ; i++){
            ans[i] = v.top().first;
            v.pop();
        }
        return ans;
    }
};

/*
class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second<b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int, int> pii;
        unordered_map <int, int> um;
        priority_queue<pair<int, int>> order;
        vector<int> ans(k);
        for (int i=0; i<nums.size(); i++){
            um[nums[i]]++;
        }
        priority_queue<pii,vector<pii>,cmp> v(um.begin(),um.end());
        for (int i=0 ; i<k ; i++){
            ans[i] = v.top().first;
            v.pop();
        }
        return ans;
    }
};
*/
/*
First Trial: 
class Solution {
public:
    class bucket{
        public:
        int n;
        int num = 0;
    };
    struct comparing{
        bool operator ()(bucket ba, bucket bb){
            return ba.num > bb.num;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <bucket> b(20010);
        for (int i=0 ; i<nums.size() ; i++){
            b[nums[i]+10005].n = nums[i];
            b[nums[i]+10005].num++;
        }
        sort(b.begin(), b.end(), comparing());
        vector <int> ans(k);
        for (int i=0 ; i<k ; i++)   ans[i] = b[i].n;
        return ans;
    }
};
*/