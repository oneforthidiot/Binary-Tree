 bool helper(Node* root,int l,int r){
        if(!root)return true;
        if(!(root->data<r and root->data>l))return false;
        bool f1=helper(root->left,l,min(root->data,r));
        bool f2=helper(root->right,max(l,root->data),r);
        return (f1 and f2);
    }
    bool isBST(Node* root) 
    {
        int l=INT_MIN,r=INT_MAX;
        return helper(root,l,r);
    }
