#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node*prew;
    struct node*next;
};
struct node*head=NULL;
struct node*temp;

void insert(){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("\nEnter the value for push : ");
    scanf("%d",&x);

    newnode->data=x;
    newnode->next=NULL;
    newnode->prew=NULL;

    if(head==NULL){
        head=newnode;
        temp=newnode;
    }else{
        temp->next=newnode;
        newnode->prew=temp;
        temp=newnode;
    }

    printf("%d",newnode->data);
}

void desplay(){
    if(head== NULL){
        printf("\nlinklist is emty !!");
    }else{
        temp=head;
        while(head != NULL){
            printf("%d <->",temp->data);
            temp=temp->next;
        }
    }
}
int main (){
    int ch;
    do{
    printf("\nenter your choise : ");
    scanf("%d",&ch);
    printf("\n---MENU---");
    printf("\n1 for push");
    printf("\n2 for desplay\n");

    switch(ch){
        case 1: insert();
        break;
        case 2: desplay();
        break;
        default :printf("enter right choise!!");
      }
    }while(ch !=0);

    return 0;
}