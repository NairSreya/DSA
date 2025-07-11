class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map: hd -> level -> multiset (to keep values sorted at same (hd, level))
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;

        // Edge case
        if(root == NULL)
            return {};

        // Start with root at (hd=0, level=0)
        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto p = q.front(); q.pop();
            TreeNode* curr = p.first;
            int hd = p.second.first;
            int level = p.second.second;

            nodes[hd][level].insert(curr->val);

            if(curr->left)
                q.push({curr->left, {hd - 1, level + 1}});
            if(curr->right)
                q.push({curr->right, {hd + 1, level + 1}});
        }

        // Construct result
        vector<vector<int>> result;
        for(auto& x : nodes) {
            vector<int> col;
            for(auto& y : x.second) {
                col.insert(col.end(), y.second.begin(), y.second.end());
            }
            result.push_back(col);
        }

        return result;
    }
};
