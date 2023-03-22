Node* helper1(Node* root,int target,int &sum){
        if(!root)return NULL;
        if(root->data==target)return root;
        sum+=root->data;
        if(root->data>target){
            return helper1(root->left,target,sum);
        }
        else
        if(root->data<target){
            return helper1(root->right,target,sum);
        }   // return root;
    }
    int inorder(Node* root){
        // if(!root)return 0;
        if(!root->left and !root->right)return root->data;
        if(!root->left)return root->data+inorder(root->right);
        if(!root->right)return root->data+inorder(root->left);
        return root->data+min(inorder(root->left),inorder(root->right));
    }
    int maxDifferenceBST(Node *root,int target){
        int sum1=0;
        Node* tar=helper1(root,target,sum1);
        if(!tar)return -1;
        int sum2=inorder(tar);
        // cout<<sum1<<" "<<sum2<<endl;
        return sum1-sum2+target;
    }
