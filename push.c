#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};
struct node*head=NULL;

void insert(){
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    int x;
    printf("enter the value for inserting linklist : ");
    scanf("%d",&x);

    // (*newnode).data=x;
    newnode->data=x;
    newnode->next=NULL;

    if (head==NULL){
        head=newnode;
    }else{
        struct node*temp=head;
        while(temp->next !=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    
}

int main (){
   for(int i=0;i<4;i++){
    insert();
   }

    return 0;
}