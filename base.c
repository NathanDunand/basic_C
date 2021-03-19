#include <stdio.h>
#include <string.h>
#include "base.h"

/**
 * retourne;
 * -1 si t1<t2, 0 si si t1==t2, 1 si t1>t2 
 */
int compare(s_base_t t1, s_base_t t2)
{
	if(strcmp(t1.name,t2.name)==0){
		return 0;
	}else{
		return 1;
	}
}

void print(s_base_t t)
{
	printf("%s - %s",t.name,t.title);
}