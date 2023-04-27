/*-------------------Author: Hsin-Yu Hsieh--------------------*/
/*First Trial:  Inorder check      T: 3 99.70%   M:21.7 82.55%*/
/*Second Trial: Recursive check    T:19 31.60%   M:21.8 22.74%*/

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
    TreeNode* pre = NULL;
    bool isValidBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        if(!root)    return true;
        if(!isValidBST(root->left))  return false;
        if(pre && root->val<=pre->val)   return false;
        pre = root;
        return isValidBST(root->right);
    }
};

/*
Second Trial:
class Solution {
public:
    bool is(TreeNode* root, long min, long max){
        if(!root)   return true;
        int tmp = root->val;
        if(tmp<max && tmp>min)  return is(root->left, min, tmp) && is(root->right, tmp, max);
        return false;
    }
    bool isValidBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        return is(root, LONG_MIN, LONG_MAX);
    }
};
*/