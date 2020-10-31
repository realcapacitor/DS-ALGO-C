#include<stdio.h> 
#include<stdlib.h> 
struct Node 
{ 
    int data; 
    struct Node *next, *prev; 
}; 
  
struct Node *split(struct Node *head); 
  

struct Node *merge(struct Node *first, struct Node *second) 
{ 
 
    if (!first) 
        return second; 

    if (!second) 
        return first; 

    if (first->data < second->data) 
    { 
        first->next = merge(first->next,second); 
        first->next->prev = first; 
        first->prev = NULL; 
        return first; 
    } 
    else
    { 
        second->next = merge(first,second->next); 
        second->next->prev = second; 
        second->prev = NULL; 
        return second; 
    } 
} 
  

struct Node *mergeSort(struct Node *head) 
{ 
    if (!head || !head->next) 
        return head; 
    struct Node *second = split(head); 
    head = mergeSort(head); 
    second = mergeSort(second); 
    return merge(head,second); 
} 

	int main(void) 
	{ 
		struct Node *head = NULL; 
		insert(&head,5); 
		insert(&head,20); 
		insert(&head,4); 
		insert(&head,3); 
		insert(&head,30); 
		insert(&head,10); 
		head = mergeSort(head); 
		printf("\n\nLinked List after sorting\n"); 
		print(head); 
		return 0; 
	}

void insert(struct Node **head, int data) 
{ 
    struct Node *temp = 
        (struct Node *)malloc(sizeof(struct Node)); 
    temp->data = data; 
    temp->next = temp->prev = NULL; 
    if (!(*head)) 
        (*head) = temp; 
    else
    { 
        temp->next = *head; 
        (*head)->prev = temp; 
        (*head) = temp; 
    } 
} 


void print(struct Node *head) 
{ 
    struct Node *temp = head; 
    printf("Forward Traversal by poitner\n"); 
    while (head) 
    { 
        printf("%d ",head->data); 
        temp = head; 
        head = head->next; 
    } 
    printf("\nBackward Traversal by prev pointer\n"); 
    while (temp) 
    { 
        printf("%d ", temp->data); 
        temp = temp->prev; 
    } 
} 

void swap(int *A, int *B) 
{ 
    int temp = *A; 
    *A = *B; 
    *B = temp; 
} 

struct Node *split(struct Node *head) 
{ 
    struct Node *fast = head,*slow = head; 
    while (fast->next && fast->next->next) 
    { 
        fast = fast->next->next; 
        slow = slow->next; 
    } 
    struct Node *temp = slow->next; 
    slow->next = NULL; 
    return temp; 
} 
