#include <math.h>
#include <stdio.h>

int parantheses(int n) {
  int way;
  if ((n == 0) || (n == 1)) {
    way = n;
  }
  long long total = 0;

  for (int i = 0; i < n; i++) {
    long long left = parantheses(i);
    long long right = parantheses(n - 1 - i);

    if (left == 0)
      left = 1;
    if (right == 0)
      right = 1;

    total += left * right;
  }
  return total;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", parantheses(n));
  return 0;
}
