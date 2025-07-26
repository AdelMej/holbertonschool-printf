#include "main.h"

/**
 * init_format_map - Initialize the hash map buckets to NULL
 * @map: Pointer to the hash map structure to initialize
 *
 * Sets all bucket pointers to NULL to prepare the map for use.
 */
void init_format_map(hash_map_t *map)
{
	for (i = 0; i < HASH_SIZE; i++)
		map->buckets[i] = NULL;
}

/**
 * register_handler - Add a specifier and its handler function to the hash map
 * @map: Pointer to the hash map structure
 * @key: Format specifier character to register
 * @handler: Function pointer for handling the specifier
 *
 * Inserts a new key-handler pair into the appropriate bucket of the hash map.
 * Handles collisions by chaining nodes in the linked list.
 */
void register_handler(hash_map_t *map, const char key, handler_func_t handler)
{

}

/**
 * get_handler - Retrieve the handler function associated with a specifier
 * @map: Pointer to the hash map structure
 * @key: Format specifier character to look up
 *
 * Returns the handler function pointer if the key is found,
 * or NULL if the specifier is not registered.
 */
handler_func_t get_handler(hash_map_t *map,const char key)
{

}

