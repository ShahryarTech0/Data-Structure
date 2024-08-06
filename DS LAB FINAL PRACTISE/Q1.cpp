#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Employee class definition
class Employee {
public:
    int id;
    string name;
    string position;
    string department;
    int salary;
};

// Node class definition
class Node {
public:
    Employee employee;
    Node* left;
    Node* right;

    Node(Employee emp) {
        employee = emp;
        left = NULL;
        right = NULL;
    }
};

// Binary search tree class definition
class BinarySearchTree {
private:
    Node* root;

    // Helper function to insert a new node in the tree
    Node* insertHelper(Node* node, Employee emp) {
        if (node == NULL) {
            return new Node(emp);
        }
        if (emp.id < node->employee.id) {
            node->left = insertHelper(node->left, emp);
        }
        else if (emp.id > node->employee.id) {
            node->right = insertHelper(node->right, emp);
        }
        else {
            if (emp.salary > node->employee.salary) {
                node->right = insertHelper(node->right, emp);
            }
            else if (emp.salary < node->employee.salary) {
                node->left = insertHelper(node->left, emp);
            }
            else {
                if (emp.position > node->employee.position) {
                    node->right = insertHelper(node->right, emp);
                }
                else {
                    node->left = insertHelper(node->left, emp);
                }
            }
        }
        return node;
    }

    // Helper function to find a node with a given ID
    Node* findHelper(Node* node, int id) {
        if (node == NULL) {
            return NULL;
        }
        if (node->employee.id == id) {
            return node;
        }
        if (id < node->employee.id) {
            return findHelper(node->left, id);
        }
        else {
            return findHelper(node->right, id);
        }
    }

    // Helper function to delete a node with a given ID
    Node* deleteHelper(Node* node, int id) {
        if (node == NULL) {
            return NULL;
        }
        if (id < node->employee.id) {
            node->left = deleteHelper(node->left, id);
        }
        else if (id > node->employee.id) {
            node->right = deleteHelper(node->right, id);
        }
        else {
            if (node->left == NULL && node->right == NULL) {
                delete node;
                node = NULL;
            }
            else if (node->left == NULL) {
                Node* temp = node;
                node = node->right;
                delete temp;
            }
            else if (node->right == NULL) {
                Node* temp = node;
                node = node->left;
                delete temp;
            }
            else {
                Node* temp = findMin(node->right);
                node->employee = temp->employee;
                node->right = deleteHelper(node->right, temp->employee.id);
            }
        }
        return node;
    }

    // Helper function to find the node with the minimum value
    Node* findMin(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        if (node->left == NULL) {
            return node;
        }
        return findMin(node->left);
    }
        Node* findMaxInDepartmentHelper(Node* node, string department, int maxSalary) {
        if (node == NULL) {
            return NULL;
        }
        if (node->employee.department == department && node->employee.salary >= maxSalary) {
            return node;
        }
        if (node->employee.department < department || (node->employee.department == department && node->employee.salary < maxSalary)) {
            return findMaxInDepartmentHelper(node->right, department, maxSalary);
        }
        else {
            Node* leftResult = findMaxInDepartmentHelper(node->left, department, maxSalary);
            if (leftResult == NULL) {
                return node;
            }
            return leftResult;
        }
    }
};
int main(){
	Node* root=NULL;
	BinarySearchTree bst;
	bst.insertHelper(root,22);
	bst.insertHelper(root,23);
	bst.insertHelper(root,24);
	bst.insertHelper(root,25);
	bst.deleteHelper(root,25);
	
}
