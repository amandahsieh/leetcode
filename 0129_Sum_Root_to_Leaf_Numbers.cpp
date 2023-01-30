/*--------------------Author: Hsin-Yu Hsieh--------------------*/
/*First Trial: DFS & cal number & add     T:0 100%  M:9.2 86.3%*/

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
    int ans = 0;
    void dfs(TreeNode* node, int t){
        if(!node)   return;
        t = t*10 + node->val;
        if(!node->left && !node->right) ans+=t;
        dfs(node->left, t);
        dfs(node->right, t);
    }
    int sumNumbers(TreeNode* root) {
        int tmp=0;
        dfs(root, tmp);
        return ans;
    }
};