# include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node*next;
}node;

typedef struct linkedlist{
    int size;
    node*head;
}ll;

node*create(int data){
    node*new=(node*)malloc(sizeof(node));
    new->next=NULL;
    new->data=data;

    return new;
}

void init(ll*list)
{
    list->head=NULL;
    list->size=0;
}

void end(ll*list,int data){
    node*new=create(data);
    if(list->head==NULL){
        list->head=new;
    
    }else{
        node*temp=list->head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
    }
    list->size++;

}


void start(ll*list,int data){
    node*new=create(data);
    new->next=list->head;
    list->head=new;
    list->size++;
}


void index(ll*list,int data,int index){
    node*new=create(data);
    if(index>list->size || index<0){
        printf("Out of bounds");

    }else if(index==0){
        new->next=list->head;
        list->head=new;
    }else{
        node*temp=list->head;
        for(int i=0;i<index-1;i++){
                temp=temp->next;
        }
        temp->next=new;
    }
    list->size++;

}

int indexof(ll* list, int key) {
    node* temp = list->head;
    for (int i = 0; i < list->size; i++) {
        if (temp->data == key) {
            return i;
        }
        temp = temp->next;
    }
    return -1;
}




void delindex(ll*list,int index){
    node*temp=list->head;
    if(index==0){
        list->head=temp->next;
        free(temp);
    }else{
node*prev=NULL;
        for(int i=0;i<index;i++){
prev=temp;
    temp=temp->next;
        }

        prev->next=temp->next;
        free(temp);
    }
    list->size--;
}

void del(ll*list,int key){
    int index = indexof(list,key);
    delindex(list,index);
    list->size--;
}


void print(ll*list){
node*temp=list->head;
while(temp!=NULL){
    printf("%d",temp->data);
    if(temp->next!=NULL){
        printf("->");
    }
    temp=temp->next;
    
}
printf("\n");
}

int main(){
ll list1;
ll list2;
    init(&list1);
     init(&list2);
    end(&list1,874);
    end(&list1,2348);
    end(&list1,2882);
    end(&list1,28);
    end(&list2,28);
    end(&list2,37);
    end(&list2,94);
    
    print(&list1);
   
    print(&list2);


    return 0;
}