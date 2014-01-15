#ifndef _MEM_LIST_H
#define _MEM_LIST_H

typedef struct mem_list * plist_t ;
typedef struct mem_list list_t ;

typedef struct mem_list
{
  void *d;
  list_t *next;
}mlist;

list_t *plist ;			/* the mem pool list head */

/* the gcmalloc  */

void * cgmalloc(size_t sz);
/* free malloc */
int cgfree();

/* invalid this interface */
int add_list(list_t *pool,void *d);

/* invalid this inteface */
int del_list(list_t *pool);


#endif
