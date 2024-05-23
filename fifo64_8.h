#ifndef FIFO64_8_H
#define FIFO64_8_H

#include <pthread.h>
#include <stdint.h>

// FIFO64_8_H structure definition
typedef struct {
  uint64_t data;         // 64-bit storage for up to 8 bytes of data
  pthread_mutex_t mutex; // Mutex for thread safety
} fifo64_8;

/**
 * @brief Initializes the FIFO64_8_H structure.
 *
 * This function initializes the FIFO64_8_H structure, setting the data to 0 and
 * initializing the mutex.
 *
 * @param f Pointer to the FIFO64_8_H structure to initialize.
 */
void fifo64_8_init(fifo64_8 *f);

/**
 * @brief Destroys the FIFO64_8_H structure.
 *
 * This function destroys the FIFO64_8_H structure, cleaning up the mutex.
 *
 * @param f Pointer to the FIFO64_8_H structure to destroy.
 */
void fifo64_8_destroy(fifo64_8 *f);

/**
 * @brief Reads a byte from the FIFO64_8_H at the specified index.
 *
 * This function reads a byte from the FIFO64_8_H at the given index (0 to 7).
 * If the index is out of bounds, the function returns 0.
 *
 * @param f Pointer to the FIFO64_8_H structure.
 * @param index Index of the byte to read (0 to 7).
 * @return The byte at the specified index.
 */
uint8_t fifo64_8_read(fifo64_8 *f, uint8_t index);

/**
 * @brief Writes a byte to the FIFO64_8_H at the specified index.
 *
 * This function writes a byte to the FIFO64_8_H at the given index (0 to 7).
 * If the index is out of bounds, the function does nothing.
 *
 * @param f Pointer to the FIFO64_8_H structure.
 * @param index Index of the byte to write (0 to 7).
 * @param value The byte value to write.
 */
void fifo64_8_write(fifo64_8 *f, uint8_t index, uint8_t value);

/**
 * @brief Clears the byte at the specified index in the FIFO64_8_H.
 *
 * This function clears the byte at the given index (0 to 7) in the FIFO64_8_H,
 * setting it to 0. If the index is out of bounds, the function does nothing.
 *
 * @param f Pointer to the FIFO64_8_H structure.
 * @param index Index of the byte to clear (0 to 7).
 */
void fifo64_8_clear(fifo64_8 *f, uint8_t index);

/**
 * @brief Pops the most significant byte from the FIFO64_8_H.
 *
 * This function pops the most significant byte from the FIFO64_8_H, shifting
 * the remaining bytes left by one byte.
 *
 * @param f Pointer to the FIFO64_8_H structure.
 * @return The most significant byte that was popped.
 */
uint8_t fifo64_8_pop(fifo64_8 *f);

/**
 * @brief Pushes a byte into the fifFIFO64_8_Ho64_8.
 *
 * This function pushes a byte into the FIFO64_8_H, shifting the existing data
 * left by one byte and inserting the new byte at the least significant
 * position.
 *
 * @param f Pointer to the FIFO64_8_H structure.
 * @param value The byte value to push.
 */
void fifo64_8_push(fifo64_8 *f, uint8_t value);

/**
 * @brief Prints the current state of the FIFO64_8_H for debugging purposes.
 *
 * This function prints the current state of the FIFO64_8_H in a human-readable
 * format for debugging purposes.
 * Use the '-DDEBUG' flag when compiling.
 *
 * @param f Pointer to the FIFO64_8_H structure.
 * @param ident Identifier string to display with the FIFO64_8_H state.
 */
#ifdef DEBUG
void fifo64_8_debug_print(fifo64_8 *f, char *ident);
#endif

#endif // FIFO64_8_H
