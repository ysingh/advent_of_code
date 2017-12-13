#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t captcha_sum(char* captcha, size_t step);

int main(int argc, char** argv) {
  size_t step = 0;

  if (argc < 2) {
    printf("Usage ./inv_captcha.o <captcha> [step]\n");

    return EXIT_FAILURE;
  }

  if (argc ==  3) {
    step = atoi(argv[2]);
  }

  size_t sum = captcha_sum(argv[1], step);
  printf("%zu\n", sum);

  return EXIT_SUCCESS;
}

size_t captcha_sum(char* captcha, size_t step) {
  size_t captcha_len = strlen(captcha);
  if (step == 0) {
    step = captcha_len/2;
  }

  size_t sum = 0;

  for(size_t i = 0; i < captcha_len; ++i) {
    size_t next_char = (i + step) % captcha_len;
    if (captcha[i] == captcha[next_char]) {
        sum += captcha[i] - '0';
    }
  }

  return sum;
}

