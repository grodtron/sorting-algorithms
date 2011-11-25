#ifndef INCLUDE_LINKED_LIST_H
#define INCLUDE_LINKED_LIST_H

#define NEW_LISTNODE (struct listNode*) malloc(sizeof(struct listNode))

struct listNode {
   int value;
   struct listNode* next;
   struct listNode* prev;
};

void add_after(struct listNode* node, struct listNode* newNode);

void add_before(struct listNode* node, struct listNode* newNode);

void remove_node(struct listNode* node);

void free_list(struct listNode* head);

struct listNode* insertion_sort(struct listNode* head);

#endif
