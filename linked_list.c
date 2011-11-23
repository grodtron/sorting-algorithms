#include <stdlib.h>
#define NEW_LISTNODE (struct listNode*) malloc(sizeof(struct listNode))

struct listNode {
   int value;
   struct listNode* next;
   struct listNode* prev;
};

void add_after(struct listNode* node, struct listNode* newNode){
   newNode->prev = node;
   newNode->next = node->next;
   node->next = newNode;
   if(newNode->next){
      newNode->next->prev = newNode;
   }
}

void add_before(struct listNode* node, struct listNode* newNode){
   newNode->next = node;
   newNode->prev = node->prev;
   node->prev = newNode;
   if(newNode->prev){
      newNode->prev->next = newNode;
   }
}

void remove_node(struct listNode* node){
   if(node->next){
      node->next->prev = node->prev;
   }
   if(node->prev){
      node->prev->next = node->next;
   }
}

void free_list(struct listNode* head){
   struct listNode* temp;
   while(head->prev && (head = head->prev)); // make sure that we're at the beginning
   while(head){ // free every listNode
      temp = head;
      head = head->next;
      free(temp);
   }
}

struct listNode* insertion_sort(struct listNode* head){
   struct listNode* scan_temp;
   struct listNode* head_temp;
   struct listNode* new_head;
   while(head != NULL){
      scan_temp = head;
      head_temp = head;

      while( scan_temp->prev && scan_temp->prev->value > head_temp->value ){
         scan_temp = scan_temp->prev;
      }

      head = head->next;

      if(scan_temp != head_temp){
         remove_node(head_temp);
         add_before(scan_temp, head_temp);
         if(head_temp->prev == NULL){
            new_head = head_temp; // if we change the first element in the list, make sure
            // that we update the true start point of the list
         }
      }
   }
   return new_head;
}
