#include "list.h"

void show_menu(void);
void take_input_and_perform(List_ptr);
void perform_operation_on_list(List_ptr,char,int,int);

void show_menu(void){
  printf("Main Menu\n---------\n(a) add a number to the end of the list\n(b) add a number to the start of the list\n(c) insert a number at a given position in the list\n(d) add a unique item on the list at the end\n(e) remove a number from the beginning of the list\n(f) remove a number from the end of the list\n(g) remove a number from a given position in the list\n(h) remove first occurrence of a number\n(i) remove all occurrences of a number\n(j) clear the whole list\n(k) check if a number exists in the list\n(l) display the list of numbers\n(m) exit\n\nPlease enter the alphabet of the operation you would like to perform\n");
}

void show_message(Status s)
{
  printf("%s\n\n",s?"operation was successfully done":"oops!, operation was unsuccessfull");
}


void perform_operation_on_list(List_ptr list,char option, int value, int position)
{
  Status s = Success;
  switch (option)
  {
  case 'a':
    s = add_to_end(list,value);
    break;
  case 'b':
    s = add_to_start(list,value);
    break;
  case 'c':
    s = insert_at(list,value,position);
    break;
  case 'd':
    s = add_unique(list,value);
    break;
  case 'e':
    s = remove_from_start(list);
    break;
  case 'f':
    s = remove_from_end(list);
    break;
  case 'g':
    s = remove_at(list,position);
    break;
  case 'h':
    s = remove_first_occurrence(list,value);
    break;
  case 'i':
    s = remove_all_occurrences(list,value);
    break;
  case 'j':
    s = clear_list(list);
    break;
  case 'k':
    s = find_index(list,value);
    break;
  case 'l':
    display(list);
    break;
  }
  show_message(s);
}

void take_input_and_perform(List_ptr list)
{
  int value = 0;
  int position = 0;
  char opt;
  while (Success)
  {
    show_menu();
    scanf("%c",&opt);
    if (opt=='m')
    {
      break;
    }

    if (opt != 'l' && opt != 'e' && opt != 'f' && opt != 'g' && opt != 'j' )
    {
    printf("enter the value\n");
    scanf("%d",&value);
    }

    if (opt == 'c' || opt == 'g')
    {
      printf("enter the position\n");
      scanf("%d",&position);
    }
    while ((getchar()) != '\n');
    perform_operation_on_list(list,opt,value,position);
  }
}

int main(void)
{
  List_ptr list = create_list();
  take_input_and_perform(list);
  return 0;
}