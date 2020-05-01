#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include <stdlib.h>
typedef enum
{
  Failure,
  Success
} Status;

typedef struct node
{
  int value;
  struct node *next;
} Node;

typedef Node *Node_ptr;

typedef struct
{
  Node *head;
  Node *last;
  int count;
} List;

typedef List *List_ptr;

Node_ptr create_node(int value);
List_ptr create_list(void);

Status add_to_end(List_ptr, int value); // a
Status add_to_start(List_ptr, int value);// b
Status insert_at(List_ptr, int value, int position);// c
Status add_unique(List_ptr, int value);// d

void display(List_ptr);//l

Status remove_from_start(List_ptr);//e
Status remove_from_end(List_ptr);//f
Status remove_at(List_ptr, int position);//g

Status remove_first_occurrence(List_ptr, int value);//h
Status remove_all_occurrences(List_ptr, int value);//i

Status clear_list(List_ptr); //j

void destroy_list(List_ptr); // 
Status find_index(List_ptr,int value);//k

#endif