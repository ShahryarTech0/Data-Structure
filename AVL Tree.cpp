#include<iostream>
using namespace std;
class TreeNode {
  public:
    int value;
    TreeNode * left;
    TreeNode * right;

  TreeNode() {
    left = NULL;
    right = NULL;
  }
};

class AVLTree {
  public:
    TreeNode * root;
    AVLTree() {
      root = NULL;
    }

    int height(TreeNode * r) {
      if (r == NULL)
        return -1;
      else {
      
        int lheight = height(r -> left);
        int rheight = height(r -> right);

        /* use the larger one */
        if (lheight > rheight)
          return (lheight + 1);
        else return (rheight + 1);
      }
    }

    int getBalanceFactor(TreeNode * n) {
      if (n == NULL)
        return -1;
      return height(n -> left) - height(n -> right);
    }

    TreeNode * rightRotate(TreeNode * y) {
      TreeNode * x = y -> left;
      TreeNode * T2 = x -> right;

      // Perform rotation  
      x -> right = y;
      y -> left = T2;

      return x;
    }

    TreeNode * leftRotate(TreeNode * x) {
      TreeNode * y = x -> right;
      TreeNode * T2 = y -> left;

      // Perform rotation  
      y -> left = x;
      x -> right = T2;

      return y;
    }

    TreeNode * insert(TreeNode * r, int value) {
      if (r == NULL) {
        TreeNode * new_node = new TreeNode();
        new_node -> value = value;
        r = new_node;
        cout << "Value inserted successfully" << endl;
        return r;
      }

      if (value < r -> value) {
        r -> left = insert(r -> left, value);
      } else if (value > r -> value) {
        r -> right = insert(r -> right, value);
      } else {
        cout << "No duplicate values allowed!" << endl;
        return r;
      }

      int bf = getBalanceFactor(r);
      // Left Left Case  
      if (bf > 1 && value < r -> left -> value)
        return rightRotate(r);

      // Right Right Case  
      if (bf < -1 && value > r -> right -> value)
        return leftRotate(r);

      // Left Right Case  
      if (bf > 1 && value > r -> left -> value) {
        r -> left = leftRotate(r -> left);
        return rightRotate(r);
      }

      // Right Left Case  
      if (bf < -1 && value < r -> right -> value) {
        r -> right = rightRotate(r -> right);
        return leftRotate(r);
      }

      /* return the (unchanged) node pointer */
      return r;

    }

void display(TreeNode *root) {
  if (root != NULL) {
    cout << "Data of Node: " << root->value << endl;
    if (root->left != NULL) {
      cout << "Left Nodes: "<<endl;
      display(root->left);
    }
    if (root->right != NULL) {
      cout << "Right Nodes: "<<endl;
      display(root->right);
    }
  }
}

};

int main() {
  AVLTree obj;
  cout << "AVL INSERT" << endl;
  obj.root = obj.insert(obj.root, 50);
  obj.root = obj.insert(obj.root, 30);
  obj.root = obj.insert(obj.root, 20);
  cout << endl;
  obj.root = obj.rightRotate(obj.root);
  obj.root=obj.leftRotate(obj.root);
  obj.display(obj.root);
  return 0;
}
