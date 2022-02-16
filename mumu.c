#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mumu.h"

static int setmsg(mumu *mr, char *src);
static int getmsg(mumu *mr, char *dst);

int init_mumu(mumu **dstmr)
{
	mumu *mr=calloc(1,sizeof(mumu));
	if(mr==NULL) return -1;
	mr->getmsg=getmsg;
	mr->setmsg=setmsg;
	/* calloc does bzero so rest of members are ok */
	*dstmr=mr;
	return 0;
}

static int setmsg(mumu *mr, char *src)
{
	if(src==NULL || mr==NULL) return -1;
	if(strlen(src)>=MUMU_MSG_SIZE) return -1;
	strcpy(mr->msg,src);
	return 0;
}

/* it's caller's responsability to make sure dst is big enough */
static int getmsg(mumu *mr, char *dst)
{
	if (mr==NULL || dst==NULL) return -1;
	strcpy(dst,mr->msg);
	return 0;
}
