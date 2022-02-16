#include <stdio.h>
#include <stdlib.h>
#include "mumu.h"
#include "buru.h"

int main(int argc, char *argv[])
{
	buru *b1;
	mumu *m1;
	char *buf;	/* message buffer from buru */
	char mbuf[MUMU_MSG_SIZE];	/* message buffer from mumu is fixed size so we use the stack */
	size_t l;
	/* init both */
	if(init_buru(&b1) || init_mumu(&m1))
	{
		fprintf(stderr,"Unable to initialize buru\n");
		exit(1);
	}

	/* set message in buru (this has a side-effect, see buru.c) */
	if(b1->setmsg(b1,"I wonder... did it work?"))
	{
		fprintf(stderr,"Unable to set msg\n");
		exit(1);
	}

	/* set another message in mumu */
	m1->setmsg(m1,"Let's hear it from mumu!"); /* this can't fail */

	/* for buru we have to get the total length, in order to allocate a buffer */
	l=b1->getlen(b1);
	if(l==0) exit(1);	/* shouldn't happen */
	buf=malloc(l);
	if(buf==NULL)		/* always check malloc */
	{
		fprintf(stderr,"malloc?\n");
		exit(1);
	}
	/* get messages from both structs; both setmsg and getmsg "methods" are different */
	b1->getmsg(b1,buf);
	m1->getmsg(m1,mbuf);
	printf("Msg from buru: %s\n",buf);
	printf("Msg from mumu: %s\n",mbuf);

	return 0;
}
