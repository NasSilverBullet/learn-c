#include <stdio.h>
#include <string.h>

typedef struct {
  char name[64];
  int age;
  int sex;
} person;

void scan_person(person* p) {
  printf("名前: ");
  scanf("%s", p->name);
  printf("年齢: ");
  scanf("%d", &(p->age));
  printf("性別> 女性-> 0 男性-> 1: ");
  scanf("%d", &(p->sex));
}

void print_person(person* p) {
  char sex[] = "undefined";

  if (p->sex == 0) {
    strcpy(sex, "woman");
  } else if (p->sex == 1) {
    strcpy(sex, "man");
  }

  printf("名前: %s\n", p->name);
  printf("年齢: %d\n", p->age);
  printf("性別: %s\n", sex);
  return;
}

int main(void) {
  int i;

  person ps[3];

  for (i = 0; i < sizeof(ps) / sizeof(person); i++) {
    scan_person(&ps[i]);
  }

  for (i = 0; i < sizeof(ps) / sizeof(person); i++) {
    print_person(&ps[i]);
  }

  return 0;
}
