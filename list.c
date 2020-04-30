#include "list.h"

Node_ptr create_node(int value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

List_ptr create_list()
{
  List_ptr new_list =malloc(sizeof(List));
  new_list->head = NULL;
  new_list->last = NULL;
  new_list->count = 0;
  return new_list;
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if(list->head == NULL){
    list->head = new_node;
  } else
  {
    list->last->next = new_node;
  }
  list->last = new_node;
  list->count++;
  return Success;
}