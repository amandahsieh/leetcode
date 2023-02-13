/*------------------------Author: Hsin-Yu Hsieh------------------------*/
/*First Trial: Merge Sort       T:1515  6.57%   M:250.9  9.80%*/
/*Second Trial: Priority Queue  T:172  78.60%   M:61.5  52.80%*/
/*Third Trial: Bucket Sort      T:100  99.43%   M:65.3  38.98%*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> bucket(100010, 0);
        int tmp = 0;
        for(int i=0; i<nums.size(); i++)    bucket[nums[i]+50005]++;
        for(int i=0; i<bucket.size(); i++){
            if(tmp>=nums.size())    return nums;
            while(bucket[i]--)    nums[tmp++] = i-50005;
        }
    	return nums;
	}
};

/*
First Trial: Merge Sort
class Solution {
public:
	void merge(vector<int> l, vector<int> r, vector<int>& nums){
		int i=0, j=0;
		while(i<l.size() && j<r.size()){
            if(l[i]<r[j])    nums[(i++)+j] = l[i];
            else    nums[i+(j++)] = r[j];
		}
		while(i<l.size())    nums[(i++)+j] = l[i];
		while(j<r.size())    nums[i+(j++)] = r[j];
	}
    void merge_sort(vector<int>& nums){
	    int n = nums.size();
	    if(n<=1)	return;
	    vector<int> left(n/2);
	    vector<int> right(n-n/2);
	    copy(nums.begin(), nums.begin()+(n/2), left.begin());
        copy(nums.begin()+(n/2), nums.end(), right.begin()); 
        merge_sort(left);
	    merge_sort(right);
        cout << "merge "<< n;
	    merge(left, right, nums);

    }
    vector<int> sortArray(vector<int>& nums) {
  		merge_sort(nums);
    	return nums;
	}
};
*/

/*
Second Trial: Priority Queue
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0; i<nums.size(); i++)    q.push(nums[i]);
        for(int i=0; i<nums.size(); i++){
            nums[i] = q.top();
            q.pop();
        }
    	return nums;
	}
};
*/