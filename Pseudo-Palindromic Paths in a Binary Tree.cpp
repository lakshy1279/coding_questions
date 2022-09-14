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
    int ans;
    void helper( TreeNode* root, unordered_map<int,int> map)
    {
        if( root == NULL )
            return;
        if( map.find( root -> val) != map.end() )
        {
            map.erase(root -> val);
        }
        else
            map[root -> val]++;
        if( (!root -> left) && (!root -> right) )
        {
            if(map.size() <= 1)
            {
                ans++;
            }
            return;
        }
        helper( root -> left, map);
        helper( root -> right, map);
    }
    int pseudoPalindromicPaths (TreeNode* root, int count = 0) {
        // unordered_map<int,int>map;
        // ans = 0;
        //  helper(root, map);
        // return ans;
      
       // 2nd method
        if (!root) return 0;
        // to mark the presence of the digit 
        count ^= 1 << (root->val - 1);
        int res = pseudoPalindromicPaths(root->left, count) + pseudoPalindromicPaths(root->right, count);
        // to check the presence of the leaf node and check only one bit is set in the count;
        if (root->left == root->right && (count & (count - 1)) == 0) res++;
        return res;
    }
};
