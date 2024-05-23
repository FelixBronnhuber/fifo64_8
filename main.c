#include "fifo64_8.h"
#include <stdio.h>

#ifdef DEBUG
#define FIFO64_8_DEBUG_PRINT(fifo, ident) fifo64_8_debug_print(fifo, ident);
#else
#define FIFO64_8_DEBUG_PRINT(fifo, ident)                                      \
  do {                                                                         \
  } while (0)
#endif

int main() {
  fifo64_8 f;
  fifo64_8_init(&f);

  // Test pushing elements into the fifo64_8
  printf("Pushing elements 1, 2, 3, 4, 5, 6, 7, 8\n");
  for (uint8_t i = 1; i <= 8; i++) {
    fifo64_8_push(&f, i);
  }

  FIFO64_8_DEBUG_PRINT(&f, "After Push");

  // Test popping elements from the fifo64_8
  printf("Popping elements:\n");
  for (int i = 0; i < 8; i++) {
    uint8_t value = fifo64_8_pop(&f);
    printf("Popped value: %u\n", value);
    FIFO64_8_DEBUG_PRINT(&f, "After Pop");
  }

  // Test reading and writing to specific indices
  printf("Writing values 0xAA to index 0 and 0xBB to index 1\n");
  fifo64_8_write(&f, 0, 0xAA);
  fifo64_8_write(&f, 1, 0xBB);
  FIFO64_8_DEBUG_PRINT(&f, "After Write");

  printf("Reading from indices 0 and 1:\n");
  uint8_t value0 = fifo64_8_read(&f, 0);
  uint8_t value1 = fifo64_8_read(&f, 1);
  printf("Value at index 0: %02x\n", value0);
  printf("Value at index 1: %02x\n", value1);

  // Test clearing an index
  printf("Clearing index 1\n");
  fifo64_8_clear(&f, 1);
  FIFO64_8_DEBUG_PRINT(&f, "After Clear");

  fifo64_8_destroy(&f);
  return 0;
}
