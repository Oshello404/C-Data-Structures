#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_node{
    int value;
    struct linked_list_node* next;
} Node;

typedef Node* List;

List Insert(List head, int value, int asc)
{
    Node *ptr = (List)malloc(sizeof(Node)); // allocate a piece of memory for the new node
    ptr->value = value;
    if(head==NULL || value < head->value && asc == 1 || value > head->value && asc == 0)
    {
        ptr->next = head;
        return ptr;
    }
    Node *current = head;
    while(1)
    {
        if(asc == 1){ // ascending order
            if(current->next == NULL){
                current->next = ptr;
                ptr->next = NULL;
                break;
            }
            else if(ptr->value <= current->next->value){
                ptr->next = current->next;
                current->next = ptr;
                break;
            }
            else current = current->next;
        }
        else if(asc == 0){ // descending order
            if(current->next == NULL){
                current->next = ptr;
                ptr->next = NULL;
                break;
            }
            else if(ptr->value >= current->next->value){
                ptr->next = current->next;
                current->next = ptr;
                break;
            }
            else current = current->next;
        }
    }
    return head;
}

int NumberOfPairsSumToK(List headA, List headB, int k)
{
    int numberOfPairs = 0;
    Node *currentA = headA;
    Node *currentB = headB;
    
    while(currentA != NULL){
        while(currentB != NULL){
            if(currentA->value + currentB->value < k) break;
            else if(currentA->value + currentB->value == k) numberOfPairs++;
            currentB = currentB->next;
        }
        currentA = currentA->next;
    }
    return numberOfPairs;
}

void Print(List head)
{
    // do not forget to print a '\n'
    Node *current = head;
    while(current != NULL){
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    List headA = NULL;
    List headB = NULL;
    int n, m, k;
    int value;

    printf("Input the number of integers in A:\n");
    scanf("%d", &n);
    printf("Input these integers:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &value);
        headA = Insert(headA, value, 1);
    }

    printf("Input the number of integers in B:\n");
    scanf("%d", &m);
    printf("Input these integers:\n");
    for(int i=0; i<m; i++)
    {
        scanf("%d", &value);
        headB = Insert(headB, value, 0);
    }

    printf("Input k:\n");
    scanf("%d", &k);

    int noOfPairs;
    noOfPairs = NumberOfPairsSumToK(headA, headB, k);

    Print(headA);
    Print(headB);
    printf("Number of pairs summed to k:\n");
    printf("%d\n", noOfPairs);
    
    return 0;
}
