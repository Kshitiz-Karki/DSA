#include <stdio.h>


int main(void)
{
  //enum starts from 0
  enum Company {GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT};

  //can be assigned any integer value to any one of the enums
  // enum Company {GOOGLE, FACEBOOK, XEROX, YAHOO=10, EBAY, MICROSOFT};
  
  enum Company google = GOOGLE;
  enum Company xerox = XEROX;
  enum Company ebay = EBAY;

  printf("%d\n", xerox);
  printf("%d\n", google);
  printf("%d\n", ebay);

  return 0;
}