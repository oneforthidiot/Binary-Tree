Node *deleteNode(Node *root, int X) {
    if(!root)return NULL;
    if(root->data>X){
        root->left=deleteNode(root->left,X);
        return root;
    }
    else
    if(root->data<X){
        root->right=deleteNode(root->right,X);
        return root;
    }
    else{
        if(!root->right and !root->left)return NULL;
        else
        if(!root->left){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else
        if(!root->right){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        else{
            Node* temp=root->right;//Next Sucessessor
            while(temp->left)temp=temp->left;
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    return root;
}
