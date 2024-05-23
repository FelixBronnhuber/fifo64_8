#include <pthread.h>
#include <stdint.h>
#include <stdio.h>

typedef struct {
  uint64_t data;
  pthread_mutex_t mutex;
} fifo64_8;

// Initialize the fifo64_8 structure
void fifo64_8_init(fifo64_8 *f) {
  f->data = 0;
  pthread_mutex_init(&f->mutex, NULL);
}

// Destroy the fifo64_8 structure
void fifo64_8_destroy(fifo64_8 *f) { pthread_mutex_destroy(&f->mutex); }

uint8_t fifo64_8_read(fifo64_8 *f, uint8_t index) {
  if (index >= 8)
    return 0; // Handle out-of-bounds index
  pthread_mutex_lock(&f->mutex);
  uint8_t n_byte_shift = index * 8;
  uint64_t mask = ((uint64_t)0xFF) << n_byte_shift;
  uint64_t value = (f->data & mask) >> n_byte_shift;
  pthread_mutex_unlock(&f->mutex);
  return (uint8_t)value;
}

void fifo64_8_write(fifo64_8 *f, uint8_t index, uint8_t value) {
  if (index >= 8)
    return; // Handle out-of-bounds index
  pthread_mutex_lock(&f->mutex);
  uint8_t n_byte_shift = index * 8;
  uint64_t mask = ((uint64_t)0xFF) << n_byte_shift;
  f->data &= ~mask;
  f->data |= ((uint64_t)value << n_byte_shift);
  pthread_mutex_unlock(&f->mutex);
}

void fifo64_8_clear(fifo64_8 *f, uint8_t index) {
  if (index >= 8)
    return; // Handle out-of-bounds index
  pthread_mutex_lock(&f->mutex);
  uint8_t n_byte_shift = index * 8;
  uint64_t mask = ((uint64_t)0xFF) << n_byte_shift;
  f->data &= ~mask;
  pthread_mutex_unlock(&f->mutex);
}

uint8_t fifo64_8_pop(fifo64_8 *f) {
  pthread_mutex_lock(&f->mutex);
  uint8_t element =
      (uint8_t)(f->data >> 56); // Extract the most significant byte
  f->data <<= 8;                // Shift the data left by one byte
  pthread_mutex_unlock(&f->mutex);
  return element;
}

void fifo64_8_push(fifo64_8 *f, uint8_t value) {
  pthread_mutex_lock(&f->mutex);
  f->data <<= 8;
  f->data |= value;
  pthread_mutex_unlock(&f->mutex);
}

#ifdef DEBUG
void fifo64_8_debug_print(fifo64_8 *f, char *ident) {
  uint8_t byte;

  printf("fifo64_8 ( %s ) [", ident);
  for (uint8_t i = 0; i < 7; i++) {
    byte = (uint8_t)(f->data >> 8 * (7 - i));
    printf("%02x, ", byte);
  }
  byte = (uint8_t)(f->data);
  printf("%02x", byte);

  printf("]\n");
}
#endif
