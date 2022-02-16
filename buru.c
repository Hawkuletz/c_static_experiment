#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buru.h"

static int setmsg(buru *br, char *src);
static int getmsg(buru *br, char *dst);
static size_t getlen(buru *br);

int init_buru(buru **dstbr)
{
	buru *br=calloc(1,sizeof(buru));
	if(br==NULL) return -1;
	br->getmsg=getmsg;
	br->setmsg=setmsg;
	br->getlen=getlen;
	/* calloc does bzero so rest of members are ok */
	*dstbr=br;
	return 0;
}

static int setmsg(buru *br, char *src)
{
	/* to show that this is different we'll make a little silly modification */
	char pre[]="Alice says:\n";
	char *buf;
	size_t l;
	if(src==NULL || br==NULL) return -1;
	l=strlen(src)+sizeof(pre);	/* quick and dirty, should check for overflow */
	buf=malloc(l); 
	if(buf==NULL) return -1;
	/* not the safest way, but it's just to prove a point */
	strcpy(buf,pre);
	strcat(buf,src);
	free(br->msg);	/* no-op if NULL; don't leak memory on setmsg */
	br->msg=buf;
	br->msg_len=l;
	return 0;
}

static size_t getlen(buru *br)
{
	if(br==NULL) return 0;
	return br->msg_len;
}

/* it's caller's responsability to make sure dst is big enough */
static int getmsg(buru *br, char *dst)
{
	if (br==NULL || dst==NULL) return -1;
	memcpy(dst,br->msg,br->msg_len);
	return 0;
}
