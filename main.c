#include <stdio.h>
#include <stdlib.h>

struct node {
    int k;
    struct node *left, *right;
};

struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->k = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->k);
        inorder(root->right);
    }
}

int search(struct node *node, int k)
{
    if(node->k == k){
        return node -> k;
    }
    if(k < node->k){
        return search(node->left,k);
    }
    else{
        return (node->right,k);
    }
}

struct node* insert(struct node* node, int k)
{
   
    if (node == NULL)
        return newNode(k);
   
    if (k < node->k)
        node->left = insert(node->left, k);
    else if (k > node->k)
        node->right = insert(node->right, k);

    return node;
}

int main()
{
    struct node* root = NULL;
    FILE * file = fopen("input.txt", "r");
    int arr[18];
    int i;
    
	for(i = 1; i < 18 ; i++){
	
		fscanf(file, "%d ", &arr[i]);
	}
	root = insert(root, arr[0]);
	for(i = 1; i < 18 ; i++){
	
		insert(root, arr[i]);
	}	
	int ipt = 1;
	
	while(ipt !=0 ){
	
    printf("Key value to be searched (Enter 0 to exit):");
        scanf("%d", &ipt);
	printf("At Depth level  \n");
	int x = search(root, ipt);
	if(x == ipt){
         //   int depth = depth(root,ipt,0);
         //   printf("At Depth level %d, \n",depth );

        }  
	}
	
	fclose(file);
    return 0;
}
