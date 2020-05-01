#include "list.h"

void show_menu(void);
void take_input_and_perform(List_ptr);

void show_menu(void){
  printf("Main Menu\n---------\n(a) add a number to the end of the list\n(b) add a number to the start of the list\n(c) insert a number at a given position in the list\n(d) add a unique item on the list at the end\n(e) remove a number from the beginning of the list\n(f) remove a number from the end of the list\n(g) remove a number from a given position in the list\n(h) remove first occurrence of a number\n(i) remove all occurrences of a number\n(j) clear the whole list\n(k) check if a number exists in the list\n(l) display the list of numbers\n(m) exit\n\nPlease enter the alphabet of the operation you would like to perform\n");
}

void take_input_and_perform(List_ptr list)
{
  int value;
  char option;
  while (Success)
  {
    show_menu();
    scanf("%c",&option);
    if (option=='m')
    {
      break;
    }
    printf("enter the value\n");
    scanf("%d",&value);
    while ((getchar()) != '\n');
    printf("option=> %c, value=> %d\n",option,value);
  }
}

int main(void)
{
  List_ptr list = create_list();
  take_input_and_perform(list);
  return 0;
}