#include <stdio.h>
#include <stdlib.h>
struct BST {
int data;
struct BST *lchild;
struct BST *rchild;
};
typedef struct BST * NODE;
NODE create() {
NODE temp;
temp = (NODE) malloc(sizeof(struct BST));
printf("\n Enter the value:");
scanf("%d", &temp->data);
temp->lchild = NULL;
temp->rchild = NULL;
return temp;
}
void insert(NODE root, NODE newnode) {
if (newnode->data < root->data) {
if (root->lchild == NULL){
root->lchild = newnode;
} else {
insert(root->lchild, newnode);
}
} else if (newnode->data > root->data) {
if(root->lchild == NULL){
root->lchild = newnode;
} else {
insert(root->lchild, newnode);
}
}
}
void search(NODE root) {
int key;
NODE cur;
if(root == NULL) {
printf("\n BST is empty.");
return;
}
printf("\n Enter element to be searched:");
scanf("%d",&key);
cur = root;
while (cur != NULL) {
if (cur->data == key) {
printf("\n key element is present in BST");
return;
}
if (key < cur->data) {
cur = cur->lchild;
} else {
cur = cur->rchild;
}
}
printf("\n Key element is not found in the BST");
}
void inorder(NODE root) {
if(root != NULL) {
inorder(root->lchild);
printf("%d", root->data);
inorder(root->lchild);
}
}
void preorder(NODE root) {
if(root != NULL) {
printf("%d", root->data);
preorder(root->lchild);
preorder(root->lchild);
}
}
void postorder(NODE root) {
if(root != NULL) {
postorder(root->lchild);
postorder(root->lchild);
printf("%d", root->data);
}
}
int main() {
int ch, n, i;
NODE root = NULL, newnode;
while(1) {
printf("\n\n~~~~ BST MENU~~~~");
printf("\n 1. Create a BST");
printf("\n 2. Display");
printf("\n 3. Search");
printf("\n 4. Exit");
printf("\n Enter your choice: ");
scanf("%d",&ch);
switch(ch) {
case 1:
printf("\nEnter the number of elements:");
scanf("%d",&n);
for(i = 1;i<= n;i++) {
newnode = create();
if (root == NULL) {
root = newnode;
}  else {
insert(root,newnode);
}
}
break;
case 2:
if (root == NULL) {
printf("\n Tree is not created");
} else {
printf("\n The preorder Display");
preorder(root);
printf("\n The inorder Display");
inorder(root);
printf("\n The postorder Display");
postorder(root);
}
break;
case 3:
search(root);
break;
case 4:
exit(0);
default:
printf("\n Invalid choice! Please enter a valid option.");
}
}
return 0;
}



