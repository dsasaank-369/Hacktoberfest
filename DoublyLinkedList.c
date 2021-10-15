#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node{
    int value;
    struct node* left;
    struct node* right;
}Node;
Node *start;
void reverse_ll(){
    Node *temp=start;
    Node *next=temp;
    while(next->right != NULL){
        next = temp->right;
        temp->right = temp->left;
        temp->left = next;
        temp = next;
    }
    start->right = NULL;
    start = next;
    start->right = next->left;
    start->left = NULL;
}
void insert_at_front(int value){
    Node* ptr=(Node*)malloc(sizeof(Node*));
    (*ptr).value=value;
    (*ptr).left=NULL;
    (*ptr).right=start;
    if(start != NULL)
        (*start).left=ptr;
    start=ptr;
    printf("The node value %d is stored at the address %d.\n",(*start).value,start);
}
void insert_at_end(int value){
    Node* ptr=(Node*)malloc(sizeof(Node*));
    (*ptr).value=value;
    (*ptr).left=NULL;
    (*ptr).right=NULL;
    Node* temp=start;
    if(start == NULL){
        start=ptr;
        return;
    }
    while ((*temp).right != NULL){
        temp=(*temp).right;
    }
    (*ptr).left=temp;
    (*temp).right=ptr;
     printf("The node value %d is stored at the address %d.\n",(*ptr).value,ptr);
}
void insert_after_pos(int pos,int value){
    Node* ptr=(Node*)malloc(sizeof(Node*));
    (*ptr).value=value;
    (*ptr).left=NULL;
    (*ptr).right=NULL;
    if(pos == 0){
        (*ptr).right = start;
        (*start).left = ptr;
        start = ptr;
        printf("The node value %d is stored at the address %d.\n",(*ptr).value,ptr);
        return;
    }
    Node* temp=start;
    while (pos-1>0){
        temp=(*temp).right;
        pos--;
        if(temp == NULL){
            printf("The entered node position is invalid.");
            return;
        }
    }
    (*ptr).left=temp;
    (*ptr).right=(*temp).right;
    if((*temp).right != NULL){
        (*(*temp).right).left=ptr;
    }
    (*temp).right=ptr;
    printf("The node value %d is stored at the address %d.\n",(*ptr).value,ptr);
}
void insert_after_val(int val,int value){
    Node* ptr=(Node*)malloc(sizeof(Node*));
    (*ptr).value=value;
    (*ptr).right=NULL;
    (*ptr).left=NULL;
    if(start == NULL){
        printf("The node with the value %d was not found.",val);
        return;
    }
    Node* temp=start;
    while(temp->value != val){
        temp=temp->right;
        if(temp == NULL){
            printf("The node with the value %d was not found.",val);
            return;
        }
    }
    (*ptr).left=temp;
    (*ptr).right=(*temp).right;
    if((*temp).right != NULL){
        (*(*temp).right).left=ptr;
    }
    (*temp).right=ptr;
    printf("The node value %d is stored at the address %d.\n",(*ptr).value,ptr);
}
void delete_from_start(){
    Node* temp=start;
    if (start==NULL){
        return;
    }
    printf("The node value %d  stored at the address %d was deleted.\n",(*start).value,start);
    start=(*temp).right;
    (*start).left=NULL;
    free(temp);
}
void delete_from_end(){
    Node* temp=start;
    if (start==NULL){
        return;
    }
    if((*start).right==NULL){
        printf("The node value %d  stored at the address %d was deleted.\n",(*start).value,start);
        start=NULL;
        free(start);
        return;
    }
    while ((*temp).right != NULL){
        temp=(*temp).right;
    }
    (*(*temp).left).right=NULL;
    printf("The node value %d  stored at the address %d was deleted.\n",(*temp).value,temp);
    free(temp);
}
void delete_value(int val){
    if (start==NULL){
        return;
    }
    Node* temp;
    if((*start).value == val){
        temp = start->right;
        printf("The node value %d stored at the address %d was deleted.\n",val,start);
        start->right = NULL;
        start = temp;
        return;
    }
    temp=start;
    Node* previous;
    while((*temp).value != val){
        previous=temp;
        temp=(*temp).right;
        if (temp == NULL){
            printf("The node value %d to be deleted was not found in the linked list.",val);
            return;
        }
    }
    (*previous).right=(*temp).right;
    if ((*temp).right != NULL){
        (*(*temp).right).left = previous;
    }
    (*temp).left = NULL;
    (*temp).right = NULL;
    free(temp);
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
        printf("[ %d, %d, %d] ",ptr->left,ptr->value,ptr->right);
        ptr=(*ptr).right;
    }
    printf("\n");
}
void menu(){
    printf("Available Operations : \n");
    printf("1] Insert at start, 2] Insert at end, 3] Insert after a position, 4] Insert after a value, ");
    printf("5] Delete from start, 6] Delete from end, 7] Delete a node with a specific value, ");
    printf("8] Display elements , 9] Exit\n");
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
        reverse_ll();
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

