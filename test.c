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
  int expected_1[] = {5};
  int expected_1_length = 1;
  s = s && compare_list_values(actual,expected_1,expected_1_length);
  show_message("should add a value if the list head is null", s);

  s = add_to_end(actual,2);
  int expected_2[] = {5,2};
  int expected_2_length = 2;
  s = s && compare_list_values(actual,expected_2,expected_2_length);
  show_message("should add a value at the end of the list", s);
}

void test_add_to_start()
{List_ptr actual = create_list();
  Status s = add_to_start(actual,5);
  int expected_1[] = {5};
  int expected_1_length = 1;
  s = s && compare_list_values(actual,expected_1,expected_1_length);
  show_message("should add a value if the list head is null", s);

  s = add_to_start(actual,2);
  int expected_2[] = {2,5};
  int expected_2_length = 2;
  s = s && compare_list_values(actual,expected_2,expected_2_length);
  show_message("should add a value at the start of the list", s);

}


int main(void)
{
  test_add_to_end();
  test_add_to_start();
  return 0;
}
