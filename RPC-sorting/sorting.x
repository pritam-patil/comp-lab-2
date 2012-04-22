const MAXSIZE=10;
struct Array
{
	int num[MAXSIZE];
	int size;
};

typedef struct Array Array;

program PROG_SORT{
	version VER_SORT{
		Array SORT(Array)=1;
	}=1;
}=4148;