#include <stdlib.h>
#include <stdio.h>

#include "memlist.h"

void * cgmalloc(size_t sz)
{
  list_t *t ;
  list_t *temp ;
  void * d ;
  void * td ;
  size_t const list_sz = sizeof(list_t) ;
  
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


/*  add mem to plist */
void * cgadd(list_t *pool,size_t sz)
{
  list_t *t;
  list_t *temp;
  void * d ;
  if(NULL != pool) {
    t = pool->next;
    if(NULL == t && NULL == pool->d) {
      pool->d = d ;
      pool->next = NULL ;
      return d;
    }
    else if(NULL == t && NULL != pool->d ) {
      temp = (list_t *)malloc(sizeof(list_t)) ;
      temp->d = (void *)d ;
      temp->next = NULL ;
      pool->next = temp ;
      
      return d;
    }
    else {
      temp = (list_t *)malloc(sizeof(list_t)) ;
      temp->d = d ;
      temp->next = pool->next ;
      pool->next= temp ;

      return d;
    }
  }
  else {
    return NULL;
  }
  return NULL;
}


/* free mem from plist */
int cgdelete(list_t *pool)
{
  list_t *t;
  for(t=pool;t!=NULL;t=t->next)
    {
      free(t->d);
      free(t);      
    }

  pool = NULL ;
  return 0;
}


