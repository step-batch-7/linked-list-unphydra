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
  Node_ptr * ptr_to_set = &list->head;
  if(list->head!=NULL){
    ptr_to_set = &list->last->next;
  }
  (*ptr_to_set) = new_node;
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
  if (position > list->count || position < 0)
  {
    return Failure;
  }
  if (position ==0)
  {
    return add_to_start(list,value);
  }
  if (position == list->count)
  {
    return add_to_end(list,value);
  }
  
  Node_ptr new_node = create_node(value);
  int count = 1;
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
  while (count<list->count)
  {
    if (p_walk->value==value) {
      return Failure;
    }
    count++;
    p_walk = p_walk->next;
  }
  return add_to_end(list,value);
}

void display(List_ptr list)
{ 
  if (list->head==NULL)
  {
    printf("\nthe list is empty\n");
  } else {
    printf("\n%s\n",list->count>1?"values of the list are":"value of the list is");
    Node_ptr p_walk = list->head;
    while (p_walk != NULL)
    {
      printf("%d\n",p_walk->value);
      p_walk = p_walk->next;
    }
  }
}

Status remove_from_start(List_ptr list)
{
  if (list->head==NULL)
  {
    return Failure;
  }
  if (list->count==1)
  {
    return clear_list(list);
  }
  Node_ptr temp = list->head->next;
  free(list->head);
  list->head = temp;
  list->count--;
  return Success;
}

Status remove_from_end(List_ptr list)
{
  if (list->head==NULL)
  {
    return Failure;
  }
  if (list->count==1)
  {
    return clear_list(list);
  }
  
  Node_ptr p_walk = list->head;
  Node_ptr element_to_remove = p_walk->next;
  while (element_to_remove->next!=NULL)
  {
    p_walk = element_to_remove;
    element_to_remove = element_to_remove->next;
  }
  p_walk->next = NULL;
  free(element_to_remove);
  list->last = p_walk;
  list->count--;
  return Success;
}

Status remove_at(List_ptr list, int position)
{
  if (list->head==NULL || position >= list->count || position < 0)
  {
    return Failure;
  }
  if (position == 0)
  {
    return remove_from_start(list);
  }
  if (position == list->count-1)
  {
    return remove_from_end(list);
  }
  
  Node_ptr p_walk = list->head;
  Node_ptr elment_to_delete = p_walk->next;
  int count = 1;
  while (count<position)
  {
    count++;
    p_walk = elment_to_delete;
    elment_to_delete = elment_to_delete->next;
  }
  p_walk->next = elment_to_delete->next;
  free(elment_to_delete);
  list->count--;
  return Success;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  if (list->head==NULL)
  {
    return Failure;
  }
  Node_ptr p_walk = list->head;
  int count = 0;
  while (count < list->count)
  {
    if (value == p_walk->value)
    {
      return remove_at(list,count);
    }
    count++;
    p_walk= p_walk->next;
  }
  return Failure;
}

Status remove_all_occurrences(List_ptr list, int value)
{
  Status curr_status = Failure;
  while (1)
  {
    Status return_status = remove_first_occurrence(list,value);
    if (return_status == Failure)
    {
      return curr_status;
    }
    curr_status = curr_status || return_status;
  }
}

Status clear_list(List_ptr list)
{
  if (list->head==NULL)
  {
    return Failure;
  }
  
  Node_ptr p_walk = list->head;
  Node_ptr element_to_free = NULL;

  while (p_walk!=NULL)
  {
    element_to_free = p_walk;
    p_walk = p_walk->next;
    free(element_to_free);
  }
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return Success;
}

void destroy_list(List_ptr list)
{
  clear_list(list);
  free(list);
}

Status find_index(List_ptr list,int value)
{
  Node_ptr p_walk = list->head;
  int count = 1;
  while (p_walk!=NULL)
  {
    if(p_walk->value == value){
      printf("\n%d present is the list at a position %d\n",value,count);
      return Success;
    }
    count++;
    p_walk = p_walk->next;
  }
  printf("\n%d is not present in the list\n", value);
  return Success;
}