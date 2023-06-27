/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
 */

// @lc code=start
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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int max_width = 1;

        while(!q.empty()){
            int size = q.size();
            int start = q.front().second;
            int end = q.back().second;
            max_width = max(max_width,end-start+1);

            for(int i=0;i<size;i++){
                auto it = q.front();
                TreeNode* node = it.first;
                int id = it.second;
                q.pop();

                if(node->left) q.push({node->left,2LL*id+1});
                if(node->right) q.push({node->right,2LL*id+2});

            }
        }

        return max_width;
        
    }
};

