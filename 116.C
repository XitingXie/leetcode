/*Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL*/
#include <stdlib.h>

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
struct Queue{
    struct TreeLinkNode* value[100000];
    int head;
    int end;
};

void init(struct Queue* q){
    q->head=q->end=0;
}

struct TreeLinkNode* pop(struct Queue* q){
    if(q->head==q->end) return NULL;
    return q->value[q->end++];
}

bool isEmpty(struct Queue* q){
    if(q->head==q->end) return true;
    else return false;
}

void push(struct Queue *q,struct TreeLinkNode *t){
    q->value[q->head++]=t;
}

void connect(struct TreeLinkNode *root) {
    
	struct TreeLinkNode* p1 = NULL;
	struct TreeLinkNode* p2 = NULL;
	
	struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
	
	init(q);
	
	struct TreeLinkNode* pn = NULL;
	p1 = root;
	
	if(p1 == NULL) return;

	push(q,pn);
	
	while(!isEmpty(q)){
		if(p1->left!=NULL) push(q,p1->left);
		if(p1->right!=NULL) push(q,p1->right);
				
		p2 = pop(q);
		p1->next = p2;
		if(p2==NULL){
		    if(p1->left!=NULL) push(q,p1->left);
		    if(p1->right!=NULL) push(q,p1->right);
		    
		    if(!isEmpty(q)) {p1=pop(q);push(q,pn);}
		}
		else{
			p1->next = p2;
			p1=p2;
		}
	}    
}