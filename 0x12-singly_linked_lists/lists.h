#ifdef LIST_H
#define LIST_H

/**
 * struct list_s - list
 * @str: string 
 * @len: string length
 * @next: where next node is pointed 
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;


list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);



#endif
