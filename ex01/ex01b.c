#include<stdio.h>
#include<stdlib.h>
struct Node{
   int data;
   struct Node*next;
};
struct Node* createNode(int data){
   struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
   if(newNode= NULL){
      fprintf(stderr,"memory allocation failed\n");
      exit(EXIT_FAILURE);
   }
   newNode->data= data;
   newNode->next= NULL;
   return newNode;
}
void insertAtEnd(struct Node** head,int data){
   struct Node*newNode = createNode(data);
   if(*head == NULL){
      *head = newNode;
      return;
   }
   struct Node* temp = *head;
   while(temp->next !=NULL)
   {
      temp = temp->next;
   }
   temp->next= newNode;
}
void insertAtPosition(struct Node** head,int data,int position){
   if(position<0){
      printf("error: Invalid position.\n");
      return;
   }
   struct Node*newNode = createNode(data);
   if(position == 0){
      newNode->next=*head;
      *head = newNode;
      return;
   }
   struct Node* current = *head;
   struct Node* previous= NULL;
   int currentPos= 0;
   while((current!=NULL)&&(currentPos<position)){
      previous = current;
      current = current->next;
      currentPos++;
   }
   if(currentPos != position) {
      printf("error: Invalid position.\n");
      free(newNode);
      return;
   }
   newNode->next = current;
   previous->next = newNode;
}
int searchElement(struct Node**head,int data){
   struct Node* temp = *head;
   int position= 0;
   while(temp != NULL) {
      if(temp->data == data) {
         return position;
      }
      temp = temp->next;
      position++;
   }
   return -1;
}
void deleteElement(struct Node** head,int position){
   if(*head ==NULL){
      printf("error: list is empty.\n");
      return;
   }
   if(position<0){
      printf("error: Invalid position.\n");
      return;
   }
   struct Node* temp = *head;
   if(position == 0){
      *head = temp->next; 
      free(temp);
      return;
   }
   struct Node* previous= NULL;
   int currentPos= 0;
   while((temp !=NULL)&&(currentPos<position)){
      previous = temp;
      temp = temp->next;
      currentPos++;
   }
   if(temp == NULL) {
      printf("error: Invalid position.\n");
      return;
   }
   previous->next = temp->next;
   free(temp);
}
void displayList(struct Node*head) {
   if(head == NULL){
      printf("List is empty.\n");
      return;
   }
   printf("Linked List:");
   struct Node* temp = head;
   while (temp != NULL){
      printf("%d ->", temp->data);
      temp = temp->next;
   }
   printf("NULL\n");
}
int main() {
   struct Node* head = NULL;
   int choice,data,position,result;
   while(1) {
      printf("\n Singly Linked List Operations Menu:\n");
      printf("1.insert at end\n");
      printf("2.insert at position\n");
      printf("3.search element\n");
      printf("4.delete element\n");
      printf("5.display list\n");
      printf("6.exit\n");
      scanf("%d", &choice);
      switch(choice) {
         case 1:  
            printf("enter data to insert at end:");
            scanf("%d",&data);
            insertAtEnd(&head,data);
            break;
        case 2:
            printf("enter data to insert:");
            scanf("%d",&data);
            printf("enter position to insert(0 - based index):");
            scanf("%d", &position);
            insertAtPosition(&head,data,position);
            break;
        case 3:
            printf("enter element to search:");
            scanf("%d",&data);
            result= searchElement(&head,data);
            if(result != -1)
               printf("element found at position:%d\n",result);
            else
               printf("element not found in the list\n");
            break;
        case 4:
           printf("enter position to delete(0 - based index):");
           scanf("%d", &position);
           deleteElement(&head,position);
            break;  
        case 5:
            displayList(head);
            break;
       case 6:
           while(head !=NULL)
           {
              struct Node*temp = head;
              head = head->next;
              free(temp);
           }
           return 0;
       default:
          printf("invalid choice! please enter a valid option.\n");
    }
  }
  return 0;
}

