TreeNode* helper(vector<int> &pre,vector<int>&in,int &idx,int l,int r,map<int,int> &mp){
        if(l>r)return NULL;
        int curr=pre[idx];
        idx++;
        TreeNode* root=new TreeNode(curr);
        if(l==r)return root;
        int mid=mp[curr];
        root->left=helper(pre,in,idx,l,mid-1,mp);
        root->right=helper(pre,in,idx,mid+1,r,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int l=0,r=preorder.size()-1;
        int idx=0;
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return helper(preorder,inorder,idx,l,r,mp);
    }
