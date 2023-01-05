class Solution {
public:

    /*Use a class bucket to store the information of frequency and number*/
    class bucket{
        public:
        int n;
        int num = 0;
    };

    /*Use the structure containing boolean function to sort the bucket*/
    struct comparing{
        bool operator ()(bucket ba, bucket bb){
            return ba.num > bb.num;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <bucket> b(20010);
        /*Update the numbers and frequency plus 10005: the number might be negative*/
        for (int i=0 ; i<nums.size() ; i++){
            b[nums[i]+10005].n = nums[i];
            b[nums[i]+10005].num++;
        }
        sort(b.begin(), b.end(), comparing());
        /*Use a vector to store the top k numbers*/
        vector <int> ans(k);
        for (int i=0 ; i<k ; i++)   ans[i] = b[i].n;
        return ans;
    }
};
