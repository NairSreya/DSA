class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;  // Initialize the result
        if (!root) return result;    // Handle empty tree case
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<int> currentLevel;    // Track nodes at the current level

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL){
                result.push_back(currentLevel);  // Store the current level
                currentLevel.clear();            // Reset for next level
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                currentLevel.push_back(temp->val);  // Add node to current level
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        
        return result;  // Return the final result
    }
};