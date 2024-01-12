class Solution {
public:
    TreeNode* nodeToParentMapping(TreeNode* root, int start, unordered_map<TreeNode*, TreeNode*> &nodeToParent){
        TreeNode* startNode;
        nodeToParent[root] = NULL;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            if(curr->val == start)startNode = curr;
            q.pop();

            if(curr->left){
                nodeToParent[curr->left] = curr;
                q.push(curr->left);
            }

            if(curr->right){
                nodeToParent[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return startNode;
    }
    int infectTree(TreeNode* root, TreeNode* startNode,unordered_map<TreeNode*, TreeNode*> &nodeToParent){
        int res = 0;
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        vis[startNode] = true;

        q.push(startNode);


        while(!q.empty()){
            int size = q.size();
            bool flag = false;

            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && !vis[curr->left]){
                    vis[curr->left] = true;
                    q.push(curr->left);
                    flag = 1;
                }

                if(curr->right && !vis[curr->right]){
                    vis[curr->right] = true;
                    q.push(curr->right);
                    flag = 1;
                }

                if(nodeToParent[curr] && !vis[nodeToParent[curr]]){
                    vis[nodeToParent[curr]] = true;
                    q.push(nodeToParent[curr]);
                    flag = 1;
                }
            }

            if(flag == true){
                res++;
            }
        }
        return res;
    }


    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* startNode = nodeToParentMapping(root,start,nodeToParent);

        int ans = infectTree(root,startNode,nodeToParent);
        return ans;
        
    }
};