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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int,int>  inorder_map;
        for(int i=0;i<inorder.size();i++){
            inorder_map[inorder[i]] = i;
        }

        int preorder_idx = 0;
        return build(inorder_map,preorder,preorder_idx, 0, inorder.size()-1);
        
    }

private:
    TreeNode* build(unordered_map<int, int>& inorder_map, vector<int>& preorder,  int& preorder_idx,int in_start, int in_end){
        if(in_start>in_end){
            return NULL;
        }

        int root_val = preorder[preorder_idx++];
        TreeNode* root = new TreeNode(root_val);

        int root_ind = inorder_map[root_val];

        root->left = build(inorder_map, preorder, preorder_idx, in_start, root_ind-1);
        root->right = build(inorder_map, preorder, preorder_idx, root_ind+1, in_end);
        return root;

    }
};