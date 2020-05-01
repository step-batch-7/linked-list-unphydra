#include "list.h"

typedef int * Array;
typedef char * String;

Status compare_list_values(List_ptr,Array,int);
void show_message(String,Status);

Status compare_list_values(List_ptr list, Array a, int length)
{
  Status s = Success;
  s = list->count == length;
  Node_ptr p_walk = list->head;
  int count = 0;
  while (p_walk!=NULL)
  {
    s = s && p_walk->value == a[count];
    count++;
    p_walk = p_walk->next;
  }
  return s && (count == length);
}

void show_message(String msg, Status s)
{
  printf("%s => %s\n",msg,s?"pass":"fails");
}

void test_add_to_end(void)
{
  List_ptr actual = create_list();
  Status s = add_to_end(actual,5);
  int expected[] = {5};
  int expected_length = 1;
  s = s && compare_list_values(actual,expected,expected_length);
  show_message("should add a value if the list head is null", s);
}

int main(void)
{
  test_add_to_end();
  return 0;
}
