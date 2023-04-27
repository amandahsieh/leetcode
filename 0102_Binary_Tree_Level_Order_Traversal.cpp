/*-------------------Author: Hsin-Yu Hsieh--------------------*/
/*First Trial:  queue & vector      T:3 85.82%   M:12.7 34.64%*/
/*Second Trial: function call       T:0 100%     M:13.7  6.11%*/

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

/*Second Trial: */
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)   return ans;
        Traversal(root, 0);
        return ans;
    }
    void Traversal(TreeNode* Node, int depth){
        if(!Node)   return;
        if(depth == ans.size())    ans.push_back({});
        ans[depth].push_back(Node->val);
        Traversal(Node->left, depth+1);
        Traversal(Node->right, depth+1);
    }
};

 /*First Trial: queue & vector
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue <TreeNode *> q;
        vector<vector<int>> ans;
        if(!root)   return ans;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> tmp(len);
            for(int i=0; i<len; i++){
                TreeNode* t = q.front();
                q.pop();
                if(t->left)     q.push(t->left);
                if(t->right)    q.push(t->right);
                if(t) tmp[i] = t->val;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
*/