#define MUMU_MSG_SIZE 256
typedef struct mumu 
{
	char	msg[MUMU_MSG_SIZE];
	int		(*getmsg)();
	int		(*setmsg)();
} mumu;

int init_mumu(mumu **);
