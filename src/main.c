#include "main.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
  char *printMe = "Hello, World!";

  if (!printf("%s\n", printMe))
  {
    printf("ERROR!\n");
    return 1;
  }
  
  return 0;
}
