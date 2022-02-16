typedef struct buru
{
	char	*msg;
	size_t	msg_len;
	int		(*getmsg)();
	size_t	(*getlen)();
	int		(*setmsg)();
} buru;

int init_buru(buru **);
