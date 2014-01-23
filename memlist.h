#ifndef _MEM_LIST_H
#define _MEM_LIST_H

typedef struct mem_list * plist_t ;
typedef struct mem_list list_t ;

typedef struct mem_list
{
  void *d ;
  list_t *next ;
}mlist ;

list_t *plist ;			/* the mem pool list head */

/* the gcmalloc  */
void * cgmalloc(size_t sz);

/* free malloc */
int cgfree();

/*  add mem to plist */
void * cgadd(list_t *pool,size_t sz) ;


/* free mem from plist */
int cgdelete(list_t *pool);




#endif
