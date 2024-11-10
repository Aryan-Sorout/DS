#include<stdio.h>
#include<stdlib.h>

typedef struct node{

    int data;
    struct node*next;
    struct node*prev;
}node;

typedef struct dll{
    node*head;
}dll;

node*create(int data){
    node*new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
return new;
}
 
void init(dll*list){
    list->head=NULL;

}

void end(dll*list,int data){
node*new=create(data);
if(list->head==NULL){
    list->head=new;


}else{
    node*temp=list->head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
    new->prev=temp;
}

}

void start(dll*list,int data){
    node*new=create(data);
    if(list->head==NULL){
    list->head=new;
}else{
     node*oldh= list->head;
    list->head=new;
    new->next=oldh;
    oldh->prev=new;
}

}


void delend(dll*list){
    if(list->head==NULL){
        printf("list is empty");
        return;
    }
    node*temp=list->head;
    if (temp->next == NULL) {
        list->head = NULL;  // Update head to NULL, as the list will become empty
        free(temp);
        return;
    }
        
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    
}

void delstart(dll*list){
    if(list->head==NULL){
        printf("list is empty");
        return;
    }
     if (list->head->next == NULL) {
        node* oldHead = list->head;
        list->head = NULL;
        free(oldHead);
        return;
    }
    node* oldHead = list->head;
    node* newHead = oldHead->next;
    list->head = newHead;
    newHead->prev = NULL;
    free(oldHead);
}

void printforward(dll*list){
    
    if(list->head==NULL){
        printf("list is empty");
        return;
    }
    else{
        node*temp=list->head;
        while(temp!=NULL){
            printf("%d",temp->data);
            if(temp->next!=NULL){
                printf("->");
            }
            temp=temp->next;
            
        }
          
    }
      printf("\n");
}


void printback(dll*list){
    node*temp=list->head;
    while(temp->next!=NULL){
        temp=temp->next;
    
    }
    printf("LIST BACKWARDS:");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->prev;
        printf("->");
    }
    printf("\n");
}
int main() {
    dll list;
    init(&list);

    end(&list, 10);
    end(&list, 20);
    start(&list, 5);

    printforward(&list);   // Expected output: 5 -> 10 -> 20
    printback(&list);      // Expected output: 20 -> 10 -> 5

    
    return 0;
}