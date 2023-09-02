#include <stddef.h>
#include <stdio.h>

typedef enum { EQUAL, UNEQUAL, SUBLIST, SUPERLIST } comparison_result_t;

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count);

int main (void)
{
  //UNEQUAL
  // int list_to_compare[] = { 1, 2, 3 };
  //  int base_list[] = { 1, -2, 3 };

  // int list_to_compare[] = { 1, 2, 3 };
  // int base_list[] = { 2, 3, 4 };

   int list_to_compare[] = { 1, 3 };
   int base_list[] = { 1, 2, 3 };

  //SUBLIST
  // int list_to_compare[] = { 1, 2, 5 };    
  // int base_list[] = { 0, 1, 2, 3, 1, 2, 5, 6 };

  // int list_to_compare[] = { 2, 3, 4 };
  //  int base_list[] = { 0, 1, 2, 3, 4, 5 };

  // int list_to_compare[] = { 1, 1, 2 };
  //  int base_list[] = { 0, 1, 1, 1, 2, 1, 2 };


  //EQUAL
  // int list_to_compare[] = { 1, 2, 3 }; 
  // int base_list[] = { 1, 2, 3 };

  //SUPERLIST
  // int list_to_compare[] = { 0, 1, 2, 3, 4, 5 }; 
  // int base_list[] = { 0, 1, 2 };

  // int list_to_compare[] = { 0, 1, 2, 3, 4, 5 };
  // int base_list[] = { 2, 3 };

  size_t list_to_compare_element_count = sizeof(list_to_compare)/sizeof(list_to_compare[0]);
  size_t base_list_element_count = sizeof(base_list)/sizeof(base_list[0]);
  comparison_result_t result = check_lists(list_to_compare, base_list, list_to_compare_element_count, base_list_element_count);
  printf("result - %d\n", result);
  return 0;
}

comparison_result_t check_lists(int *list_to_compare, int *base_list, size_t list_to_compare_element_count, size_t base_list_element_count)
{
  int match_count = 0;
  size_t list_to_compare_idx = 0, base_list_idx = 0;

  while(list_to_compare_idx != list_to_compare_element_count && base_list_idx != base_list_element_count)
  {
    if(base_list[base_list_idx] == list_to_compare[list_to_compare_idx])
    {
      list_to_compare_idx++;
      base_list_idx++;
      match_count++;
    }
    else
    {
      if(match_count == 0)
      {
        if(list_to_compare_element_count > base_list_element_count)
          list_to_compare_idx++;
        else if(list_to_compare_element_count < base_list_element_count)
          base_list_idx++;
        else
        {
          list_to_compare_idx++;
          base_list_idx++;
        }
      }
      else
      {
        if(list_to_compare_element_count < base_list_element_count)
        {
          list_to_compare_idx = 0;
          if(base_list_idx - 1 != 0)
            base_list_idx--;
        }
        else if(list_to_compare_element_count > base_list_element_count)
        {
          base_list_idx = 0;
          if(list_to_compare_idx - 1 != 0)
            list_to_compare_idx--;
        }
        else
          return UNEQUAL;
        match_count = 0;
      }
    }
  }
  if(match_count == 0 && list_to_compare_element_count != 0 && base_list_element_count != 0) return UNEQUAL;
  else if(list_to_compare_element_count > base_list_element_count) return SUPERLIST;
  else if(list_to_compare_element_count == base_list_element_count) return EQUAL;
  else return SUBLIST;
}                            
