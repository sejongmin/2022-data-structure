#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* findNode(TreeNode* root, int d) {
	TreeNode* temp = root;

	if (root == NULL)
		return NULL;

	if (root->data == d)
		return root;

	temp = findNode(root->left, d);
	if (temp != NULL)
		return temp;

	return findNode(root->right, d);
}


TreeNode* makeNode(int d) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));

	node->data = d;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void connectNode(TreeNode* root, int d, int l, int r) {

	TreeNode* p = findNode(root, d);

	if (l != 0)
		p->left = makeNode(l);
	if (r != 0)
		p->right = makeNode(r);
}


TreeNode* makeTree() {
	int n, d, l, r;
	TreeNode* root;
	scanf("%d", &n);

	scanf("%d %d %d", &d, &l, &r);

	root = makeNode(d);
	root->left = makeNode(l);
	root->right = makeNode(r);

	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &d, &l, &r);
		connectNode(root, d, l, r);
	}

	return root;
}

void traversal(TreeNode* root, char* str) {
	printf(" %d", root->data);
	if (*str) {
		if (*str == 'R')
			traversal(root->right, str + 1);
		else if (*str == 'L')
			traversal(root->left, str + 1);
	}
}

int main() {
	TreeNode* root = makeTree();

	int n;
	scanf("%d", &n);
	getchar();
	char str[10];
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		getchar();
		traversal(root, str);
		printf("\n");
	}

	return 0;
}