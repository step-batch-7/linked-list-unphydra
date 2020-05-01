#include "list.h"

typedef int * Array;
typedef char * String;

int pass = 0;
int fail = 0;

Status compare_list_values(List_ptr,Array,int);
void show_message(String,Status);
void show_length_failure(int, int);

void show_message(String msg, Status s)
{
  s?pass++:fail++;
  printf("%s => %s\n",msg,s?"pass":"fails");
}

void show_length_failure(int a, int b)
{
  printf("\nactual=> %d\nexpected=>%d\n",a,b);
}

Status compare_list_values(List_ptr list, Array a, int length)
{
  Status s = Success;
  s = list->count == length;
  if (!s)
  {
    show_length_failure(list->count,length);
  }
  
  Node_ptr p_walk = list->head;
  int count = 0;
  while (p_walk!=NULL)
  {
    s = s && p_walk->value == a[count];
    count++;
    p_walk = p_walk->next;
  }
  if (!s)
  {
    printf("\nactual=>\n");
    display(list);
    printf("expected=>\n");
    for (int i = 0; i < length ; i++)
    {
      printf("%d\n",a[i]);
    } 
  }
  return s && (count == length);
}

void test_add_to_end(void)
{
  printf("\ntest_add_to_end\n");
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

void test_add_to_start(void)
{
  printf("\ntest_add_to_start\n");
  List_ptr actual = create_list();
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

void test_insert_at(void)
{
  printf("\ntest_insert_at\n");
  List_ptr actual = create_list();
  Status s = insert_at(actual,5,1);
  int expected_1[] = {5};
  int expected_1_length = 1;
  s = s && compare_list_values(actual,expected_1,expected_1_length);
  show_message("should add a value if the list head is null", s);

  s = insert_at(actual,2,1);
  int expected_2[] = {2,5};
  int expected_2_length = 2;
  s = s && compare_list_values(actual,expected_2,expected_2_length);
  show_message("should add a value at the first position of the list", s);

  s = insert_at(actual,1,0);
  int expected_3[] = {1,2,5};
  int expected_3_length = 3;
  s = s && compare_list_values(actual,expected_3,expected_3_length);
  show_message("should add a value at the zero position of the list", s);

  s = insert_at(actual,4,4);
  int expected_4[] = {1,2,5,4};
  int expected_4_length = 4;
  s = s && compare_list_values(actual,expected_4,expected_4_length);
  show_message("should add a value at the position after the end of the list", s);

  s = insert_at(actual,3,3);
  int expected_5[] = {1,2,3,5,4};
  int expected_5_length = 5;
  s = s && compare_list_values(actual,expected_5,expected_5_length);
  show_message("should add a value at the given between position of the list", s);
}

void test_add_unique(void)
{
  printf("\ntest_add_unique\n");
  List_ptr actual = create_list();
  Status s = add_unique(actual,5);
  int expected_1[] = {5};
  int expected_1_length = 1;
  s = s && compare_list_values(actual,expected_1,expected_1_length);
  show_message("should add a value if the list head is null", s);

  s = add_unique(actual,2);
  int expected_2[] = {5,2};
  int expected_2_length = 2;
  s = s && compare_list_values(actual,expected_2,expected_2_length);
  show_message("should add a unique value at the end of the list", s);

  s = add_unique(actual,2);
  int expected_3[] = {5,2};
  int expected_3_length = 2;
  s = (s==Failure) && compare_list_values(actual,expected_3,expected_3_length);
  show_message("should not add the not unique value at the end of the list", s);
}

void test_remove_from_start(void)
{
  printf("\ntest_remove_from_start\n");
  List_ptr actual = create_list();
  Status s = remove_from_start(actual);
  int expected_1[] = {};
  int expected_1_length = 0;
  s = (s==Failure) && compare_list_values(actual,expected_1,expected_1_length);
  show_message("should not remove if the list is empty", s);

  s = add_to_start(actual,2);
  s = s && add_to_start(actual,2);
  s = s && remove_from_start(actual);
  int expected_2[] = {2};
  int expected_2_length = 1;
  s = s && compare_list_values(actual,expected_2,expected_2_length);
  show_message("should remove a value from the start of the list", s);
}

void test_remove_from_end(void)
{
  printf("\ntest_remove_from_end\n");
  List_ptr actual = create_list();
  Status s = remove_from_end(actual);
  int expected_1[] = {};
  int expected_1_length = 0;
  s = (s==Failure) && compare_list_values(actual,expected_1,expected_1_length);
  show_message("should not remove if the list is empty", s);

  s = add_to_start(actual,2);
  s = s && add_to_start(actual,2);
  s = s && remove_from_end(actual);
  int expected_2[] = {2};
  int expected_2_length = 1;
  s = s && compare_list_values(actual,expected_2,expected_2_length);
  show_message("should remove a value from the start of the list", s);
}

void test_remove_at(void)
{
  printf("\ntest_remove_at\n");
  List_ptr actual = create_list();
  Status s = remove_at(actual,1);
  int expected_1[] = {};
  int expected_1_length = 0;
  s = (s==Failure) && compare_list_values(actual,expected_1,expected_1_length);
  show_message("should not remove if the list is empty", s);

  s = add_to_end(actual,2);
  s =s && add_to_end(actual,2);
  s =s && remove_at(actual,1);
  int expected_2[] = {2};
  int expected_2_length = 1;
  s = s && compare_list_values(actual,expected_2,expected_2_length);
  show_message("should remove a value at the first position of the list", s);

  s = remove_at(actual,0);
  int expected_3[] = {2};
  int expected_3_length = 1;
  s = (s==Failure) && compare_list_values(actual,expected_3,expected_3_length);
  show_message("should not remove a value at the zero position of the list", s);

  s = remove_at(actual,2);
  int expected_4[] = {2};
  int expected_4_length = 1;
  s = (s==Failure) && compare_list_values(actual,expected_4,expected_4_length);
  show_message("should not remove a value at the position after the end of the list", s);

  s = add_to_end(actual,5);
  s =s && add_to_end(actual,4);
  s =s && remove_at(actual,2);
  int expected_5[] = {2,4};
  int expected_5_length = 2;
  s = s && compare_list_values(actual,expected_5,expected_5_length);
  show_message("should remove a value at the given between position of the list", s);
}

void test_remove_first_occurrence(void)
{
  printf("\ntest_remove_first_occurrence\n");
  List_ptr actual = create_list();
  Status s = add_to_end(actual,5);
  s = s && add_to_end(actual,2);
  s = s && add_to_end(actual,5);
  s = s && add_to_end(actual,5);
  s = s && remove_first_occurrence(actual,5);
  int expected_1[] = {2,5,5};
  int expected_1_length = 3;
  s = s && compare_list_values(actual,expected_1,expected_1_length);
  show_message("should remove the first occurrence of the given value from the first position", s);

  s = remove_first_occurrence(actual,5);
  int expected_2[] = {2,5};
  int expected_2_length = 2;
  s = s && compare_list_values(actual,expected_2,expected_2_length);
  show_message("should remove the first occurrence of the given value from the in between position", s);
}

void test_remove_all_occurrences(void)
{
  printf("\ntest_remove_first_occurrences\n");
  List_ptr actual = create_list();
  Status s = add_to_end(actual,5);
  s = s && add_to_end(actual,2);
  s = s && add_to_end(actual,5);
  s = s && add_to_end(actual,5);
  s = s && remove_all_occurrences(actual,2);
  int expected_1[] = {5,5,5};
  int expected_1_length = 3;
  s = s && compare_list_values(actual,expected_1,expected_1_length);
  show_message("should remove the first occurrence of the given value from the first position", s);

  s = remove_all_occurrences(actual,5);
  int expected_2[] = {};
  int expected_2_length = 0;
  s = s && compare_list_values(actual,expected_2,expected_2_length);
  show_message("should remove the first occurrence of the given value from the in between position", s);
}

void test_find_index(void)
{
  printf("\ntest_find_index\n");
  List_ptr actual = create_list();
  Status s = add_to_end(actual,5);
  s = s && add_to_end(actual,2);
  s = s && add_to_end(actual,5);
  s = s && add_to_end(actual,5);

  int value = find_index(actual,5);
  int expected = 1;
  s = s && (value==expected);
  show_message("should give the position of the value in the list", s);

  value = find_index(actual,3);
  expected = -1;
  s = s && (value==expected);
  show_message("should give -1 if the value is not present in the list", s);
}

int main(void)
{
  test_add_to_end();
  test_add_to_start();
  test_insert_at();
  test_add_unique();
  test_remove_from_start();
  test_remove_from_end();
  test_remove_at();
  test_remove_first_occurrence();
  test_remove_all_occurrences();
  test_find_index();
  printf("\ntestpasses=> %d, testfail=> %d\n", pass,fail);
  return 0;
}
