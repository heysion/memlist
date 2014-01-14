#ifndef _MEM_LIST_H
#define _MEM_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct mem_list * plist_t ;
typedef struct mem_list list_t ;

typedef struct mem_list
{
  void *d;
  list_t *next;
}mlist;

list_t *plist ;			/* the mem pool list head */

/* the gcmalloc  */

void * cgmalloc(size_t sz)
{
  list_t *t;
  list_t *temp;
  void * d;
  
  d=malloc(sz);

 start:
  if(NULL != plist)		/* decide the plist is not null */
     {
      t = plist->next;
      if(NULL == t && NULL == plist->d) /* decide the next not exist && the plist is not data */
	{
	  plist->d = d ;
	  plist->next = NULL ;
	  return d;

	}
      else if(NULL == t && NULL != plist->d) /* the plist is haved data so must new next */
	{
	  temp = (list_t *)malloc(sizeof(list_t)) ;
	  if(NULL != temp )
	    {
	      temp->d = (void *)d ;
	      temp->next = NULL ;
	      plist->next = temp ;	    
	      return d;
	    }
	  else{
	    free(d);
	    return NULL ;
	  }
	  /*  is impossible*/
	}
      else			/* the new next && use data */
	{
	  temp = (list_t *)malloc(sizeof(list_t)) ;
	  if(NULL != temp)
	    {
	      temp->d = d ;
	      temp->next = plist->next ;
	      plist->next= temp ;
	      return d;
	    }
	  else{
	    free(d);
	    return NULL;
	    }

	}
     }
   else				/* the init plist */
     {
       plist = (plist_t )malloc(sizeof(list_t)) ;
       if(NULL != plist)
	 {
	   plist->next = NULL ;
	   plist->d = NULL ;
	   goto start ;
	 }
       else{			/* init plist faild */
	 free(d);
	 return NULL ;
       }
     }

  return d;
}


int cgfree()
{
  list_t *t,temp;

  for(t=plist;t!=NULL; )
    {
      temp = t->next ;
      free(t->d);
      free(t);
      t= temp;
    }
  return 0;
}


/* invalid this interface */
int add_list(list_t *pool,void *d)
{
  list_t *t;
  list_t *temp;
 
  if(NULL != pool)
    {
      t = pool->next;
      if(NULL == t && NULL == pool->d)
	{
	  pool->d = d ;
	  pool->next = NULL ;
	  return 0;
	}else if(NULL == t && NULL != pool->d)
	{
	  temp = (list_t *)malloc(sizeof(list_t)) ;
	  temp->d = (void *)d ;
	  temp->next = NULL ;
	  pool->next = temp ;

	  return 0;
	}
      else
	{
	  temp = (list_t *)malloc(sizeof(list_t)) ;
	  temp->d = d ;
	  temp->next = pool->next ;
	  pool->next= temp ;

	  return 0;
	}
    }
  else
    {
      return -1;
    }
  return 1;
}

/* invalid this inteface */
int del_list(list_t *pool)
{
  list_t *t;
  for(t=pool;t!=NULL;t=t->next)
    {
      free(t->d);
      free(t);      
    }

  return 0;
}




#endif
