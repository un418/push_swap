

int	bench_me(char *str)
{
	char	*sa = "sa";
	char	*sb = "sb";
	char	*ss = "ss";
	char	*pa = "pa";
	char	*pb = "pb";
	char	*ra = "ra";
	char	*rb = "rb";
	char	*rr = "rr";
	char	*rra = "rra";
	char	*rrb = "rrb";
	char	*rrr = "rrr";
	char	*fin = "total";
	static	int	count;
	int 	total;

	if (!str)
		return (0);
	if (*str == "total")
	{
		total = count;
		count = 0;
		return (total);
	}







}
