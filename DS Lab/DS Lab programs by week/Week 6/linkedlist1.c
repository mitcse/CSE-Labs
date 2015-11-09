#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;

}Node;

Node* getNode(){
    return ((Node*)malloc (sizeof(Node)));
}

void Insert(int ele, Node *h){
    if(h ->next == NULL){
        h -> next = getNode();
        (h -> next) -> next = NULL;
        (h -> next) -> data = ele;
        return;
    }

    Node* p = h;
    while(p->next!=NULL){
        p = p->next;
    }

    p->next = getNode();
    (p->next)->next = NULL;
    (p->next)->data = ele;
}

Node Delete(Node* h){
    Node* temp = h->next;
    h->next = temp->next;
    printf("Deleted element: %d\n\n", temp->data);
    free(temp);
    return *h;
}

void Display(Node h){
    if(h.next == NULL){
        printf("Empty!\n");
        return;
    }

    Node* p = h.next;
    while(p!=NULL){
        printf("%d ->", p->data);
        p = p->next;
    }
    printf("\n");

}


int main(){
    int ele;
    Node head;
    head.data = 0;
    head.next = NULL;
    int ch;
    do{
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: scanf("%d", &ele);
                    Insert(ele, &head);
                    break;
            case 2: head = Delete(&head);
                    break;
            case 3: Display(head);
                    break;
        }
    }while(ch!=4);

return 0;
}
