/*-------------------Author: Hsin-Yu Hsieh-------------------*/
/*First Trial:  BFS               T:15 94.57%  M: 25.2 20.34%*/
/*Second Trial: Recursive         T:16 90.60%  M: 25   66.61%*/
/*Third Trial:  DFS               T:23 56.21%  M: 25.1 36.49%*/

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

/*First Trial*/
class Solution {
public:
    void tra(TreeNode* r, int v, int d){
        queue<TreeNode* >q;
        q.push(r);
        for(int i=2; i<d; i++){
            int s = q.size();
            while(s--){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left)   q.push(tmp->left);
                if(tmp->right)  q.push(tmp->right);
            }
        }
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            TreeNode* l = new TreeNode(v, tmp->left, NULL);
            tmp->left = l;
            TreeNode* r = new TreeNode(v, NULL, tmp->right);
            tmp->right = r;
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* h = new TreeNode(val, root, NULL);
            return h;
        }
        tra(root, val, depth);
        return root;
    }
};

/*
Second Trial: Recursive
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            return new TreeNode(val, root, NULL);;
        }
        if(depth==2){
            root->left = new TreeNode(val, root->left, NULL);
            root->right = new TreeNode(val, NULL, root->right);
            return root;
        }
        if(root->left)  root->left = addOneRow(root->left, val, depth-1);
        if(root->right) root->right = addOneRow(root->right, val, depth-1);
        return root;
    }
};
*/

/*
Third Trial: DFS
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)    return new TreeNode(val, root, NULL);
        stack<pair<TreeNode* , int>>    st;
        st.push({root, depth-1});
        while(!st.empty()){
            TreeNode* t = st.top().first;
            int d = st.top().second;
            st.pop();
            if(d==1){
                t->left = new TreeNode(val, t->left, NULL);
                t->right = new TreeNode(val, NULL, t->right);
                continue;
            }
            if(t->left) st.push({t->left, d-1});
            if(t->right)st.push({t->right, d-1});
        }
        return root;
    }
};
*/