#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node{
    struct tree_node *left_child;
    struct tree_node *right_child;
    int data;
    int level;
} Node;

typedef Node* Tree;

Tree searchPoint(Tree root, int key)
{
    if (!root) {
        //printf("\nempty tree");
        return NULL;    
    }/* empty tree         */
    if (key == root->data){
        //printf("\nroot is node");
        return NULL;
    }  /* root is the node  */
    /* key is smaller than the node and there is left subtree */
    if ((key < root->data) && (root->left_child)){
        //printf("\nLEFT CHILD");
        return searchPoint(root->left_child, key);
    }
    /* key is larger than the node and there is right subtree */
    if ((key > root->data) && (root->right_child)){
        //printf("\nRIGHT CHILD");
        return searchPoint(root->right_child,key);
    }
    return root;  /* question: why do we need to return root? */
    /* the node when the search terminates */ 
    /* i.e. the place to insert the key            */


}

Tree insert(Tree root, int key)
{
    Tree ptr, point;
    point = searchPoint(root, key);

    //if (!point) printf("\npoint is NULL");
    //else if(point) printf("\npoint has value %d", point->data);

    if (point || !(root)) { /* point != NULL  key is not in the tree */
        ptr = (Tree)malloc(sizeof(Node));
        ptr->data = key;
        ptr->left_child = ptr->right_child = NULL;

        if (root) { /* the tree exists, insert as child of point */
            if (key < point->data) {
                point->left_child = ptr;
                ptr->level = point->level + 1;
                //printf("\ninserted to left");
            }
            else {
                point->right_child = ptr;
                ptr->level = point->level + 1;
                //printf("\ninserted to right");
            }
        }
        else {
            root = ptr;   
            ptr->level = 1;
            //printf("\nroot is now %d", root->data);
        } /* it is the first node in the tree  */
         /* insert the node as the root node for an empty tree */
    }
    return root;
}

void print_level(Tree root)
{
    if(root){
        print_level(root->left_child);
        printf("%d %d\n", root->data, root->level);
        print_level(root->right_child);
    }
}

int main()
{
    int n, key;
    Tree root = NULL;
    printf("Input the number of integers:\n");
    scanf("%d",&n);
    printf("Input these integers:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &key);
        root = insert(root, key);
    }
    root->level = 1;
    print_level(root);
    
    /*Tree temp = root;
    printf("\nleft printing:");
    while(temp != NULL){
        printf("\n%d", temp->data);
        temp = temp->left_child;
    }
    temp = root;
    printf("\nright printing:");
    while(temp != NULL){
        printf("\n%d", temp->data);
        temp = temp->right_child;
    }
    */
    return 0;
}
