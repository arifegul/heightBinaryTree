#include <stdio.h>
#include <stdlib.h>  

//Binary tree has data,pointer left&right child
struct binaryTreeNode{  
    int data;  
    struct binaryTreeNode *left;  
    struct binaryTreeNode *right;  
};



//I created a new node  
struct binaryTreeNode *createNodes(int data){  
    //I created new node  
    struct binaryTreeNode *node = (struct binaryTreeNode*)malloc(sizeof(struct binaryTreeNode));  
    // Assign data to newNode, leftchildren= NULL and rightchildren=NULL  
    node -> data = data;  
    node -> left = NULL;  
    node -> right = NULL;  
      
    return node;  
}  

struct binaryTreeNode *generateBinaryTree(){
    //I define root&nodes
    struct binaryTreeNode *root =  createNodes(5);
    root->left = createNodes(7);
    root->right = createNodes(9);
    root->left->left = createNodes(11);
    root->left->right = createNodes(13);
    root->right->left = createNodes(15);
    root->right->right = createNodes(17);
    root->left->left->left = createNodes(19);
    root->right->left->left = createNodes(21);
    root->right->left->right = createNodes(23);
    root->right->left->left->left = createNodes(25);
    
    return root;
 
}


// function to height of Binary Tree
int findHeight(struct binaryTreeNode *root){

// if root is empty,I returned; 0 because root has any children
	if(root== NULL) {
		return 0;
	}
	else {
//The part where the root is counted as depth = 0. 
//So 1 must be added when going from root to left or right child.
		int leftHeight = findHeight(root -> left);
		int rightHeight = findHeight(root -> right);
		
		if(leftHeight > rightHeight)
			return(leftHeight + 1);
		else 
			return(rightHeight + 1);
	}
}

int main() {
	
//I set root the binary tree nodes that I specified above
	struct binaryTreeNode *root = generateBinaryTree();
	
	printf("The height of a binary tree: %d" ,findHeight(root));

    return 0;
}
