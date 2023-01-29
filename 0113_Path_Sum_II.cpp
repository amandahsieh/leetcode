/*----------------Author: Hsin-Yu Hsieh----------------*/
/*First Trial:  Recursion      T:7 92%    M:37.2 25.43%*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> ans;
    void Traversal(vector<int> tmp, TreeNode* node, int t){
        if(!node)   return;
        tmp.push_back(node->val);
        t-=node->val;
        if(!node->left && !node->right){
            if(t==0)    ans.push_back(tmp);
            return;
        }
        Traversal(tmp, node->left, t);
        Traversal(tmp, node->right, t);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)   return ans;
        vector<int> tmp;
        Traversal(tmp, root, targetSum);
        return ans;
    }
};