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
    void preorder(TreeNode* root, vector<TreeNode*> & pre ){
        if(root == nullptr){
            return;
        }
        pre.push_back(root);
        preorder(root->left, pre);
        preorder(root->right, pre);
    }
    void flatten(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        vector<TreeNode*> temp;
        preorder(root, temp);
        int n = temp.size();

        TreeNode* curr = root;
        for(int i=0; i<n-1;i++){
            curr=temp[i];
            curr->left = nullptr;
            curr->right = temp[i+1];
            

        }     
        curr = temp.back();  
        curr->left = nullptr;
        curr->right = nullptr; 
    }
};