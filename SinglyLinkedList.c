#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node{
    int value;
    struct node* next;
}Node;
Node *start;
void reverse(){
    Node *temp=start,*previous=start;
    Node *other=temp;
    if (other->next == NULL){
        return;
    }
    while(other->next != NULL){
        other = temp->next;
        temp->next = previous;
        previous = temp;
        temp = other;
    }
    start->next = NULL;
    start = other;
    start->next = previous;
}
void insert_at_front(int value){
    Node* ptr=(Node*)malloc(sizeof(Node*));
    (*ptr).value=value;
    (*ptr).next=NULL;
    (*ptr).next=start;
    start=ptr;
    printf("The node value %d is stored at the address %d.\n",(*start).value,start);
}
void insert_at_end(int value){
    Node* ptr=(Node*)malloc(sizeof(Node));
    (*ptr).value=value;
    (*ptr).next=NULL;
    Node* temp=start;
    if(start == NULL){
        start=ptr;
        printf("The node value %d is stored at the address %d.\n",(*ptr).value,ptr);
        return;
    }
    while ((*temp).next != NULL){
        temp=(*temp).next;
    }
    (*temp).next=ptr;
     printf("The node value %d is stored at the address %d.\n",(*ptr).value,ptr);
}
void insert_after_pos(int pos,int value){
    Node* ptr=(Node*)malloc(sizeof(Node*));
    (*ptr).value=value;
    (*ptr).next=NULL;
    if(pos == 0){
        (*ptr).next=start;
        start=ptr;
        printf("The node value %d is stored at the address %d.\n",(*ptr).value,ptr);
        return;
    }
    Node* temp=start;
    while (pos-1>0){
        temp=(*temp).next;
        pos--;
        if(temp == NULL){
            printf("The entered node position could not be found.\n");
            return;
        }
    }
    (*ptr).next=(*temp).next;
    (*temp).next=ptr;
    printf("The node value %d is stored at the address %d.\n",(*ptr).value,ptr);
}
void insert_after_val(int val,int value){
    Node* ptr=(Node*)malloc(sizeof(Node*));
    (*ptr).value=value;
    (*ptr).next=NULL;
    if(start == NULL){
        printf("The node with the value %d was not found.",val);
        return;
    }
    Node* temp=start;
    while(temp->value != val){
        temp=temp->next;
        if(temp == NULL){
            printf("The node with the value %d was not found.",val);
            return;
        }
    }
    ptr->next=temp->next;
    temp->next=ptr;
    printf("The node value %d is stored at the address %d.\n",(*ptr).value,ptr);
}
void delete_from_start(){
    Node* temp=start;
    if (start==NULL){
        return;
    }
    printf("The node value %d  stored at the address %d was deleted.\n",(*start).value,start);
    start=(*temp).next;
    free(temp);
}
void delete_from_end(){
    Node* temp=start;
    Node* previous=NULL;
    if (start==NULL){
        return;
    }
    if((*start).next==NULL){
        printf("The node value %d  stored at the address %d was deleted.\n",(*start).value,start);
        start=NULL;
        free(start);
        return;
    }
    while ((*temp).next != NULL){
        previous=temp;
        temp=(*temp).next;
    }
    (*previous).next=NULL;
    printf("The node value %d  stored at the address %d was deleted.\n",(*temp).value,temp);
    free(temp);
}
void delete_value(int val){
    if (start==NULL){
        return;
    }
    Node* temp;
    if((*start).value == val){
        temp = start->next;
        printf("The node value %d stored at the address %d was deleted.\n",val,start);
        start->next = NULL;
        start = temp;
        return;
    }
    temp=start;
    Node* previous;
    while((*temp).value != val){
        previous=temp;
        temp=(*temp).next;
        if (temp == NULL){
            printf("The node value %d to be deleted was not found in the linked list.",val);
            return;
        }
    }
    (*previous).next=(*temp).next;
    (*temp).next=NULL;
    printf("The node value %d stored at the address %d was deleted.\n",val,temp);
    return;
}
void display_list(){
    Node* ptr=start;
    if (start==NULL){
        printf("The linked list is empty.\n");
        return;
    }
    printf("The elements in the linked list are : ");
    while (ptr != NULL){
        printf("[Value : %d ,Next : %d] ",(*ptr).value,ptr->next);
        ptr=(*ptr).next;
    }
    printf("\n");
}
void menu(){
    printf("Available Operations : \n");
    printf("1] Insert at start, 2] Insert at end, 3] Insert after a position, 4] Insert after a value, ");
    printf("5] Delete from start, 6] Delete from end, 7] Delete a node with a specific value, ");
    printf("8] Display elements, 9] Reverse, 10] Exit\n");
}
int main(){
    menu();
    int opchoice,val,pos;
    bool isOn=true;
    while(isOn){
    printf("\nEnter an operation to perform : ");
    scanf("%d",&opchoice);
    switch(opchoice){
    case 1:
        printf("Enter a node value : ");
        scanf("%d",&val);
        insert_at_front(val);
        display_list();
        break;
    case 2:
        printf("Enter a node value : ");
        scanf("%d",&val);
        insert_at_end(val);
        display_list();
        break;
    case 3:
        printf("Enter a node value : ");
        scanf("%d",&val);
        printf("Enter the position to enter after : ");
        scanf("%d",&pos);
        insert_after_pos(pos,val);
        display_list();
        break;
    case 4:
        printf("Enter a node value : ");
        scanf("%d",&val);
        printf("Enter the value to enter after : ");
        scanf("%d",&pos);
        insert_after_val(pos,val);
        display_list();
        break;
    case 5:
        delete_from_start();
        display_list();
        break;
    case 6:
        delete_from_end();
        display_list();
        break;
    case 7:
        printf("Enter a node value : ");
        scanf("%d",&val);
        delete_value(val);
        display_list();
        break;
    case 8:
        display_list();
        break;
    case 9:
        reverse();
        display_list();
        break;
    case 10:
        isOn=false;
        break;
    default:
        printf("Wrong Choice.");
    }
    }
    printf("\n\n\t\t\t Prepared by : Vraj Parikh 19CE088");
}
