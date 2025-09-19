
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char *inventory[3] = {"hydraulic pump", "PLC module", "servo motor"};
const int length = 100;
const char *SpecialQuery1 = "Do you actually have any parts?";
const char *SpecialQuery2 = "Is there anything in stock at all?";
const char *question = "Which part do you need?";

int main(void) {

  char input[length];

  puts("Hej.Welcome to the spare parts inventory !\n");
  puts(question);

  fgets(input, _countof(input), stdin);
  input[strcspn(input, "\n")] = '\0';

  int found = 0;
  while (found == 0) {
    for (size_t i = 0; i < _countof(inventory); i++) {
      if (strcmp(input, inventory[i]) == 0) {
        printf("I have got %s here for you. Bye!", inventory[i]);
        found = 1;
        break;
      }
    }

    if (found == 0) {
      if (strcmp(input, SpecialQuery1) == 0 ||
          strcmp(input, SpecialQuery2) == 0) {
        printf("We have %zu part(s)!", _countof(inventory));
        for (size_t i = 0; i < _countof(inventory); i++) {
          printf("%s\n", inventory[i]);
        }
        puts(question);
        fgets(input, _countof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
      } else {
        printf("I am afraid we don't have any %s in the inventory.\n", input);
        puts(question);
        fgets(input, _countof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
      }
    }
  }

  return 0;
}
