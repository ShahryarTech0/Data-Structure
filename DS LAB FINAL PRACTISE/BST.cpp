#include<iostream>
#include<queue>
using namespace std;
class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node(int data){
		this->data=data;
		this->left=NULL;
		this->right=NULL;
	}
};
int max(Node* &root){
	Node* current;
	current=root;
	while(current->right!=NULL){
		current=current->right;
	}
	return current->data;
}
int min(Node* &root){
	Node* current;
	current=root;
	while(current->left!=NULL){
		current=current->left;
	}
	return current->data;
}
Node* deletion(Node* &root,int val){
	if(root==NULL){
		return root;
	}
	if(root->data==val){
		if(root->left==NULL && root->right==NULL){
			delete root;
			return NULL;
		}
		if(root->left!=NULL && root->right!=NULL){
			Node* temp=root->left;
			delete root;
			return temp;
		}
		if(root->left!=NULL && root->right!=NULL){
			Node* temp=root->right;
			delete root;
			return temp;
		}
	}
	if(root->data>val){
		root->left=deletion(root->left,val);
		return root;
	}
	if(root->data<val){
		root->right=deletion(root->right,val);
		return root;
}
}
void inorder(Node* &root){
	if(root==NULL){
		return;
	}
	else{
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
}
void preorder(Node* &root){
	if(root==NULL){
		return;
	}
	else{
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
}
void postorder(Node* &root){
	if(root==NULL){
		return;
	}
	else{
	postorder(root->right);
	cout<<root->data<<" ";
	postorder(root->left);
}
}
bool search(Node* &root,int x){
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
void levelordertriversel(Node* &root){
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node* temp=q.front();
		q.pop();
		if(temp==NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<temp->data<<" ";
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
}
Node* insertBST(Node* &root,int val){
	if(root==NULL){
		root=new Node(val);
	}
	if(root->data>val){
		root->left=insertBST(root->left,val);
	}
	if(root->data<val){
		root->right=insertBST(root->right,val);
	}
	return root;
}
void takeinput(Node* &root){
	int n;
	cin>>n;
	while(n!=-1){
		root=insertBST(root,n);
		cin>>n;
	}
}
int main(){
		Node* root=NULL;
	cout<<"Enter the Elements you want to insert and for exit enter -1 "<<endl;
	takeinput(root);
	levelordertriversel(root);
	if(search(root,8)){
		cout<<"Element exist "<<endl;
	}
	else{
		cout<<"Element not exist "<<endl;
	}
	cout<<"The inorder: ";
	inorder(root);
	cout<<endl;
	cout<<"The PreOrder: ";
	preorder(root);
	cout<<endl;
	cout<<"The PostOrder: ";
	postorder(root);
	cout<<endl;
	cout<<"The Maximum number is: "<<max(root)<<endl;
	cout<<"The Minimum number is: "<<min(root)<<endl;
	root=deletion(root,3);
	levelordertriversel(root);
}
