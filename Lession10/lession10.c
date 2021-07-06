#include <stdio.h>

// 1. Задание

char *brackets_check(const char *s) {
  switch (*s) {
    case '\0':
    case ')':
    case '}':
    case ']':
      return (char *)s;
    case '(': {
      char *ret = brackets_check(s + 1);
      return (*ret == ')') ? brackets_check(ret + 1) : (char *)s;
    }
    case '{': {
      char *ret = brackets_check(s + 1);
      return (*ret == '}') ? brackets_check(ret + 1) : (char *)s;
    }
    case '[': {
      char *ret = brackets_check(s + 1);
      return (*ret == ']') ? brackets_check(ret + 1) : (char *)s;
    }
    default:
      return brackets_check(s + 1);
  }
}
// 2. Задание

int main(void) {
  // 1.

  char buf[BUFSIZ];

  while (printf("Введите формулу: ") && fgets(buf, BUFSIZ, stdin) &&
         *buf != '\n')
    printf("%s\n", (*brackets_check(buf)) ? "Неправильное выражение" : "Верно");

  return 0;
}
