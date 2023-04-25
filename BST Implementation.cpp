#include <iostream>
using namespace std;

struct node{
  int key;
  struct node *left;
  struct node *right;
};

struct node *newNode(int value){
   struct node *temp = (struct node*) malloc(sizeof(struct node));
   temp -> key = value;
   temp -> left = temp -> right = NULL;
   return temp;
}

// Inorder traversal
void traverseInOrder(struct node *root){
  if (root != NULL) {
    traverseInOrder(root -> left);
    cout << root -> key << " ";
    traverseInOrder(root -> right);
  }
}

// Insert a node
struct node *insertNode(struct node *node, int key){

  // If the tree is empty, create the root.
  if (node == NULL)
    return newNode(key);

  // recurring down the tree.
  if (key < node -> key) {
    node -> left = insertNode(node -> left, key);
  }
  else if (key > node -> key) {
    node -> right = insertNode(node -> right, key);
  }

  // Returning the node pointer
  return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key){
  // If the tree is empty, return root.
  if (root == NULL) {
    return root;
  }

  // Recurring down the tree.
  if (key > root -> key) {
    root -> right = deleteNode(root -> right, key);
  }
  else if (key < root -> key) {
    root -> left = deleteNode(root -> left, key);
  }

  // key matches with the root.
  else {

    // Case 1: node has no children
    if (root -> right == NULL && root -> left == NULL) {
      delete root;
      root = NULL;
    }

    // Case 2: node has only one child
    else if (root -> right == NULL) {
      struct node *temp = root;
      root = root -> left;
      delete temp;
    }
    else if (root -> left == NULL) {
      struct node *temp = root;
      root = root -> right;
      delete temp;
    }

    // Case 3: node has two children
    else {
      struct node *temp = root -> right;
      while (temp -> left != NULL) {
        temp = temp -> left;
      }
      root -> key = temp -> key;
      root -> right = deleteNode(root -> right, temp -> key);
    }
  }

  // Return the node pointer
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
}
