 TreeNode* helper(vector<int>& pre,vector<int> &post,int l,int r,int &idx){
        if(l>r)return NULL;
        TreeNode* root=new TreeNode(pre[idx++]);
        if(l==r)return root;
        int x=pre[idx];
        int i=0;
        for(;i<=r;i++){
            if(x==post[i])break;
        }
        root->left=helper(pre,post,l,i,idx);
        root->right=helper(pre,post,i+1,r-1,idx);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int l=0,r=preorder.size()-1;
        int idx=0;
        return helper(preorder,postorder,l,r,idx);
    }
