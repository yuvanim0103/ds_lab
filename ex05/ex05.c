#include <stdio.h>
#include <stdlib.h>
struct BST {
	int data;
	struct BST *ichild;
	struct BST *rchild;
};
typedef struct BST * NODE;
NODE create() {
	NODE temp;
	temp = (NODE) malloc(sizeof(struct BST));
	printf("\nEnter The value: ");
	scanf("%d", &temp->data);
	temp->ichild = NULL;
	temp->rchild = NULL; 
	return temp;
}
void inset(NODE root, NODE newnode) {
	if (newnode->data < root->data) {
		if (root->ichild == NULL){
		root->ichild = newnode;
	      } else {
	      inset(root->ichild, newnode);
	      }
	} else if (newnode->data > root->data) {
		if (root->rchild == NULL) {
		root->rchild = newnode;
		} else {
		inset(root->rchild, newnode);
		}
	}
}
void search(NODE root) {
	int key;
	NODE cur;
	if(root == NULL) {
		printf("\nBST is empty.");
		return;
	}
	printf("\nEnter Element to be searched: ");
	scanf("%d", &key);
	cur = root;
	while (cur != NULL) {
		if (cur->data == key) {
		printf("\nkey element is present in BST");
		return;
	}
	if (key < cur->data) {
		cur = cur->ichild;
		} else {
		cur = cur->rchild;
		}
	}
	printf("\nkey element is not found in the BST");
}
void inorder(NODE root) {
	if (root != NULL) {
		inorder(root->ichild);
		printf("%d ", root->data);
		inorder(root->rchild);
	}
}
void preorder(NODE root) {
	if (root !=NULL) {
		preorder(root->ichild);
		preorder(root->rchild);
		printf("%d ", root->data);
	}
}
int main() {
	int ch, n, i;
	NODE root = NULL, newnode;
	while(1) {
		printf("\n\n~~~~BST MENU~~~~");
		printf("\n1. Create a BST");
		printf("\n2. Display");
		printf("\n3. Search");
		printf("\n4. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				printf("\nEnter the number of elements: ");
				scanf("%d", &n);
				for(i = 1; i <= n; i++) {
					newnode =create();
					if (root == NULL) {
						root = newnode;
							} else {
						inset(root, newnode);
							}
			      }
			      break;
		      case 2:
		      	if (root == NULL) {
		      		printf("\nTree Is Not created");
		      			} else {
		      		printf("\nThe Preorder display : ");
		      		preorder(root);
		      		printf("\nThe Inorder display : ");
		      		inorder(root);
		      		printf("\nThe Postorder display : ");
		      		preorder(root);
		      	}
		      	break;
		      case 3:
		      	search(root);
		      	break;
		      case 4:
		      	exit(0);
		      default:
		      	printf("\nInvalid choice! Please enter a valid option.");
		 }
	}
	return 0;
}
