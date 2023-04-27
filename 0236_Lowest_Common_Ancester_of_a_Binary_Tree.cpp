/*----------------Author: Hsin-Yu Hsieh----------------*/
/*First Trial: cal ancestor vectors    T:23 39.54%   M:16   15.93%*/
/*Second Trial: find both contained    T:17 73.35%   M:16.5 14.88%*/
/*Third Trial: reverse & cal ancestor  T:17 73.35%   M:17.1 13.50%*/
/*Fourth Trial: Recursive check (l&r)  T:12 95.83%   M:14.3 28.40%*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q)   return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right= lowestCommonAncestor(root->right, p, q);
        return (left)? right? root:left :right;
    }
};




/*
Second Trial: Find the LCA and stop (containing both)
class Solution {
public:
    void tra(TreeNode* r, TreeNode* n1, TreeNode* n2, int& t, TreeNode*& ans){
        int t1=0, t2=0;
        if(r->left)     tra(r->left, n1, n2, t1, ans);
        if(r->right)    tra(r->right, n1, n2, t2, ans);
        t = r==n1 || r==n2;
        if(t1 && t2 || (t &&(t1||t2))){
            ans = r;
            return;
        }
        t = t||t1||t2;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = new TreeNode;
        int t = 0;
        tra(root, p, q, t, ans);
        return ans;
    }
};
*/

/*
First Trial: Traverse first and find the vector of ancestors
class Solution {
public:
    void tra(vector<TreeNode* > &anc, TreeNode* root, TreeNode* node, int& f){
        if(node->val == root->val){f = 1;    return;}
        if(root->left!=NULL){
            anc.push_back(root->left);
            tra(anc, root->left, node, f);
            if(!f)  anc.pop_back();
        }
        if(root->right!=NULL){
            anc.push_back(root->right);
            tra(anc, root->right, node, f);
            if(!f) anc.pop_back();
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode* > n1(1, root), n2(1, root);
        int f1 = 0, f2 = 0;
        tra(n1, root, p, f1);
        tra(n2, root, q, f2);
        cout << n1.size() << "   " << n2.size() << endl;
        int len = min(n1.size(), n2.size());
        int i;
        for(i=0; i<len; i++)    if(n1[i]->val!=n2[i]->val)    break;
        return n1[i-1];
    }
};

/*
Third Trial
*/