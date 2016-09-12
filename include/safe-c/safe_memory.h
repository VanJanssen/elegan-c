#ifndef SAFE_MEMORY_H_
#define SAFE_MEMORY_H_

#include <malloc.h>

/**
 * Memory allocation with strict boundary and error checking.
 *
 * @param size
 *      The size in bytes to be allocated. Be aware that size in an unsigned
 *      type, passing signed values can lead to conversion errors.
 *      If `size == 0`, this function will call `exit()` and print an error
 *      message indicating with function requested zero memory. You should set
 *      your pointer to NULL yourself explicitly if you want a pointer without
 *      memory allocation.
 *
 * @param calling_function
 *      The name of the function calling this function. You can pass a
 *      custom NULL termination string, or pass the __FUNCTION__ define. You
 *      can use the macro function `safe_malloc(size)`, which will automatically
 *      pass the __FUNCTION__ define as second parameter. This usage is the most
 *      convenient because the calling it will be the same as `malloc`.
 *
 * @return
 *      The return value will be a pointer to the allocated memory, the memory
 *      will be initialized to all zero.
 *      If for some reason the memory couldn't be allocated, this function will
 *      call `exit()` and print an error message indicating the caller function
 *      and the amount of memory request.
 */
void* safe_malloc_function(size_t size, const char* calling_function);

#define safe_malloc(size) safe_malloc_function(size, __FUNCTION__);

void safe_free_function(void** pointer);
#define safe_free(pointer) safe_free_function((void **) &(pointer))

#endif /* SAFE_MEMORY_H_ */