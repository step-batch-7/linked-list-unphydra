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

Status add_to_start(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (list->head==NULL)
  {
    list->last = new_node;
  }
  Node_ptr temp = list->head;
  list->head = new_node;
  list->head->next = temp;
  list->count++;
  return Success;
}

Status insert_at(List_ptr list, int value, int position)
{
  if (position > list->count+1 || position < 0)
  {
    return Failure;
  }
  if (position ==1 || position ==0)
  {
    return add_to_start(list,value);
  }
  if (position == list->count+1)
  {
    return add_to_end(list,value);
  }
  
  Node_ptr new_node = create_node(value);
  int count = 2;
  Node_ptr p_walk = list->head;
  while (1)
  {
    if(count == position){
      Node_ptr temp = p_walk->next;
      p_walk->next = new_node;
      new_node->next = temp;
      list->count++;
      return Success;
    }
    count++;
    p_walk = p_walk->next;
  }
}

Status add_unique(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;
  int count = 0;
  Status curr_status = Failure;
  while (count<list->count)
  {
    if (p_walk->value==value) {
      return curr_status;
    }
    count++;
    p_walk = p_walk->next;
  }
  return add_to_end(list,value);
}


void display(List_ptr list)
{
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    printf("%d\n",p_walk->value);
    p_walk = p_walk->next;
  }
}