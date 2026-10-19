#include <iostream>

 struct TreeNode {
 int value ;
 TreeNode * left ;
 TreeNode * right ;

// Constructor for cleaner allocation
TreeNode (int val ) : value ( val ) , left ( nullptr ) , right ( nullptr ) {}
};

 TreeNode* insertBST(TreeNode* root, int val){
    if (root==nullptr){
        root=new TreeNode(val);
        
        return root;
    } 
     
    if (root->value >val){
            root->left= insertBST(root->left,val);
    }
    else
        root->right= insertBST(root->right,val);
    
    return root;
 }
 
void deleteTree(TreeNode* root) {
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}


void printInOrder(const TreeNode* root){
    //depth first search

    if (root == nullptr)
        return;

    printInOrder(root->left);

    std::cout << root->value << std::endl;

    printInOrder(root->right);
}

int main() {
    TreeNode* root = nullptr;

    root = insertBST(root, 15);
    root = insertBST(root, 6);
    root = insertBST(root, 23);
    root = insertBST(root, 4);
    
    root = insertBST(root, 7);
    root = insertBST(root, 71);

    printInOrder(root);
    
    deleteTree(root);

    return 0;
}
