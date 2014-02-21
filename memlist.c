#include <stdlib.h>
#include <stdio.h>

#include "memlist.h"

size_t const list_sz = sizeof(list_t) ;

void * cgmalloc(size_t sz)
{
  list_t *t ;
  list_t *temp ;
  void * d ;
  
 start:

  if(NULL != plist) {		/* decide the plist is not null  */
    t = plist->next;
    if(( NULL != t )&&(NULL != plist->d )) { 
      /* new plist->next */
  
      temp = (list_t *)malloc(list_sz + sz ) ;
      if(NULL != temp) {
	d = (void *) (((void *)temp) + list_sz );
	temp->d = d ;
	temp->next = t ;
	plist->next = temp ;
	return d;    

      }
      else {
	/* malloc failed */
	return NULL ;
      }

    } /* new plist->next end */
    else if(( NULL == t )&&(NULL != plist->d )) {
      /* the second plist->next */

      temp = (list_t *)malloc(list_sz + sz ) ;
      if(NULL != temp ) {
	d = (void *) (((void * )temp ) + list_sz );
	temp->d = d ;
	temp->next = NULL ;
	plist->next = temp ;	    
	return d;
      }
      else {
	/* malloc failed */
	return NULL ;
      }

    } /* the second plist->next end */
    else if(( NULL == t )&&(NULL == plist->d )) {
      /*  plist->d && plist->next init*/

      d = (void *)(((void *)plist) + list_sz);
      plist->d = d ;
      plist->next = NULL ;
      return d;

    }
    else {
      /*  */
      return NULL ;
    } 
  }
  else {			/* the plist==NULL ,init plist */
    plist = (plist_t )malloc(list_sz+sz) ;
    if(NULL != plist)	{
      plist->next = NULL ;
      plist->d = NULL ;
      goto start ;
    }
    else {

      return NULL ;
    }
    
  }

  return d;
}

int cgfree()
{
  list_t *t;
  list_t *temp;

  for(t=plist;t!=NULL; )
    {
      temp = t->next ;
      free(t);
      t= temp;
    }
  plist =NULL ;
  return 0;
}

#define init(x) void *x=NULL

/*  add mem to plist */
void * push(list_t *pool,size_t sz)
{

  list_t *t ;
  list_t *temp ;
  void * d ;
  
 start:

  if(NULL != pool) {		/* decide the pool is not null  */
    t = pool->next;
    if(( NULL != t )&&(NULL != pool->d )) { 
      /* new pool->next */
  
      temp = (list_t *)malloc(list_sz + sz ) ;
      if(NULL != temp) {
	d = (void *) (((void *)temp) + list_sz );
	temp->d = d ;
	temp->next = t ;
	pool->next = temp ;
	return d;    

      }
      else {
	/* malloc failed */
	return NULL ;
      }

    } /* new pool->next end */
    else if(( NULL == t )&&(NULL != pool->d )) {
      /* the second pool->next */

      temp = (list_t *)malloc(list_sz + sz ) ;
      if(NULL != temp ) {
	d = (void *) (((void * )temp ) + list_sz );
	temp->d = d ;
	temp->next = NULL ;
	pool->next = temp ;	    
	return d;
      }
      else {
	/* malloc failed */
	return NULL ;
      }

    } /* the second pool->next end */
    else if(( NULL == t )&&(NULL == pool->d )) {
      /*  pool->d && pool->next init*/

      d = (void *)(((void *)pool) + list_sz);
      pool->d = d ;
      pool->next = NULL ;
      return d;

    }
    else {
      /*  */
      return NULL ;
    } 
  }
  else {			/* the pool==NULL ,init pool */
    pool = (plist_t )malloc(list_sz+sz) ;
    if(NULL != pool)	{
      pool->next = NULL ;
      pool->d = NULL ;
      goto start ;
    }
    else {

      return NULL ;
    }
    
  }

  return d;

}


/* free mem from pool */
int release(list_t *pool)
{
  list_t *t;
  for(t=pool;t!=NULL;t=t->next)
    {
      free(t);      
    }

  pool = NULL ;
  return 0;
}


