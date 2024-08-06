#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* left;
		Node* right;
		Node(){
			this->left=NULL;
			this->right=NULL;
		}
};
class AVL{
	public:
		Node* root;
		AVL(){
			this->root=NULL;
		}
		int height(Node* root){
			if(root==NULL){
				return -1;
			}
			else{
				int leftheight=height(root->left);
				int rightheight=height(root->right);
				if(leftheight > rightheight){
					return(leftheight+1);
				}
				else{
					return(rightheight+1);
				}
			}
		}
		int balance(Node* &root){
			if(root==NULL){
				return -1;
			}
			return height(root->left)-height(root->right);
		}
		Node* rightrotate(Node* y){
			Node* x=y->left;
			Node* s=x->right;
			x->right=y;
			y->left=s;
			return x;
		}
		Node* leftrotate(Node* x){
			Node* y=x->right;
			Node* s=y->left;
			y->left=x;
			x->right=s;
			return y;
		}
		Node* insertAVL(Node* &root,int val){
			if(root==NULL){
				Node* temp=new Node;
				temp->data=val;
				root=temp;
				return root;
			}
			 if(root->data>val){
				root->left=insertAVL(root->left,val);
			}
			else if(root->data<val){
				root->right=insertAVL(root->right,val);
			}
			else 
			{
				return root;
			}
			
			int temp=balance(root);
			if(temp>1 && val < root->left->data){
				return rightrotate(root);
			}
			if(temp<-1 && val > root->right->data){
				return leftrotate(root);
			}
			if(temp>1 && val > root->left->data){
			     root->left=leftrotate(root->left);
			     return rightrotate(root);
			}
			if(temp<-1 && val < root->right->data){
			     root->right=rightrotate(root->right);
			     return leftrotate(root);
			}
			return root;
		}
		bool search(Node* root,int x){
			if(root->data==NULL){
				return false;
			}
			if(root->data==x){
				return true;
			}
			else{
				if(root->data>x){
					return search(root->left,x);
				}
				if(root->data<x){
					return search(root->right,x);
				}
			}
		}
		void print(Node* &root){
			if(root!=NULL){
				cout<<root->data<<" ";
				if(root->left!=NULL){
					print(root->left);
				}
				if(root->right!=NULL){
					print(root->right);
				}
			}
		}
};
int main(){
	AVL a;
	a.root=a.insertAVL(a.root,50);
	a.root=a.insertAVL(a.root,60);
	a.root=a.insertAVL(a.root,40);
	a.root=a.rightrotate(a.root);
	a.root=a.leftrotate(a.root);
	a.print(a.root);
	cout<<endl;
	if(a.search(a.root,40)){
		cout<<"Found "<<endl;
	}
	
}
