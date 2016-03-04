/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int valid(int, int, int);
int isOlder(char *dob1, char *dob2)
{
	int i, da1, da2, m1, m2, y1, y2, x, y;
	if (dob1[2] != '-' || dob1[5] != '-' || dob2[2] != '-' || dob2[5] != '-')
	{
		return -1;
	}
	else
	{
		for (i = 0; dob1[i] != '\0'; i++)
		{
			if (i == 2 || i == 5)
			{
				i++;
			}
			x = dob1[i] - '0';
			y = dob2[i] - '0';
			if (x<0 || x>9 || y<0 || y>9)
			{
				return -1;
			}
		}
		da1 = (dob1[0]-'0') * 10 + (dob1[1]-'0');
		da2 = (dob2[0]-'0') * 10 + (dob2[1]-'0');
		m1 = (dob1[3] - '0') * 10 + (dob1[4] - '0');
		m2 = (dob2[3]-'0') * 10 + (dob2[4]-'0');
		y1 = (dob1[6]-'0') * 1000 + (dob1[7]-'0') * 100 + (dob1[8]-'0') * 10 + (dob1[9]-'0');
		y2 = (dob2[6]-'0') * 1000 + (dob2[7]-'0') * 100 + (dob2[8]-'0') * 10 + (dob2[9]-'0');
		x = valid(da1, m1, y1);
		y = valid(da2, m2, y2);
		if (x != 0 || y != 0)
		{
			return -1;
		}
		if (y1 > y2)
		{
			return 2;
		}
		else
		if (y1<y2)
		{
			return 1;
		}
		if (m1>m2)
		{
			return 2;
		}
		else if (m1<m2)
		{
			return 1;
		}
		if (da1>da2)
		{
			return 2;
		}
		else if (da1 < da2)
		{
			return 1;
		}
		return 0;
	}
}

int valid(int d, int m, int y)
{
	int leap;
	if (d<0 || m<0 || y <= 0)
	{
		return -1;
	}
	if (m>12)
	{
		return -1;
	}
	if (d>31)
	{
		return -1;
	}
	if (y % 400 == 0)
	{
		leap = 1;
	}
	else if (y % 100 == 0)
	{ 
		leap = 0;
	}
	else if (y % 4 == 0)
	{
		leap = 1;
	}
	else
		leap = 0;
	if (leap == 0)
	{
		if (m == 9 || m == 4 || m == 6 || m == 11)
		{
			if (d>30)
			{
				return -1;
			}
		}
		if (m == 2 && d>28)
		{
			return -1;
		}
	}
	else
	{
		if (m == 9 || m == 4 || m == 6 || m == 11)
		{
			if (d>30)
			{
				return -1;
			}
		}
		if (m == 2 && d>29)
		{
			return -1;
		}
	}
	return 0;
}



