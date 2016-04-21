//#define BTREE
#ifdef BTREE

#include <iostream>
#include <vector>
using namespace std;

#define MAX 100
typedef int datatype;
typedef struct btree{
	btree* left;
	btree* right;
	datatype value;
}bt;
typedef struct mystack{
	int top;
	bool mask[MAX];
	bt* data[MAX];
}stack;
bool push(stack& s, bt* node){
	if (s.top == MAX)
		return false;
	else{
		s.top++;
		s.data[s.top] = node;
	}
}
bt* pop(stack& s){
	if (s.top == -1)
		return NULL;
	else{
		s.top--;
		return s.data[s.top + 1];
	}
}
void rPreOrder(bt* tree, vector<datatype> &result){
	result.push_back(tree->value);
	if (tree->left != NULL)
		rPreOrder(tree->left, result);
	if (tree->right != NULL)
		rPreOrder(tree->right, result);
}
void rMidOrder(bt* tree, vector<datatype> &result){	
	if (tree->left != NULL)
		rPreOrder(tree->left, result);
	result.push_back(tree->value);
	if (tree->right != NULL)
		rPreOrder(tree->right, result);
}
void rPostOrder(bt* tree, vector<datatype> &result){
	if (tree->left != NULL)
		rPreOrder(tree->left, result);	
	if (tree->right != NULL)
		rPreOrder(tree->right, result);
	result.push_back(tree->value);
}
void nrPreOrder(bt* tree, vector<datatype> &result){
	if (!tree)
		return;
	stack s;
	s.top = -1;
	while (tree || s.top != -1){
		while (tree){
			result.push_back(tree->value);
			push(s, tree);
			tree = tree->left;
		}
		tree = pop(s);
		tree = tree->right;
	}

}
void nrMidOrder(bt* tree, vector<datatype> &result){
	if (!tree)
		return;
	stack s;
	s.top = -1;
	while (tree || s.top != -1){
		while (tree){
			push(s, tree);
			tree = tree->left;
		}
		tree = pop(s);
		result.push_back(tree->value);
		tree = tree->right;
	}
}
void nrPostOrder(bt* tree, vector<datatype> &result){
	if (!tree)
		return;
	stack s;
	s.top = -1;
	while (tree || s.top != -1){
		while (tree){
			push(s, tree);
			s.mask[s.top] = false;
			tree = tree->left;
		}
		if (s.mask[s.top] == false){
			tree = s.data[s.top];
			s.mask[s.top] = true;//确保左右孩子均已访问过
			tree = tree->right;
		}
		else{
			while (s.mask[s.top] == true){
				tree = pop(s);
				result.push_back(tree->value);
			}
			tree = NULL;//保证最后栈空是能退出
		}
	}
}
int main(){
	bt* tree = new bt();
	bt* left1 = new bt();
	bt* right1 = new bt();
	left1->value = 1;
	left1->left = NULL;
	left1->right = NULL;
	right1->value = 2;
	right1->left = NULL;
	right1->right = NULL;
	tree->value = 0;
	tree->left = left1;
	tree->right = right1;

	vector<datatype> result;
	nrPostOrder(tree, result);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
}
#endif