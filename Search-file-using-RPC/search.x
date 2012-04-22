const MAXSIZE=100;
struct File
{
	char name[MAXSIZE];
};

typedef struct File File;

program PROG_SEARCH{
	version VER_SEARCH{
		double searchFile(File)=1;
	}=1;
}=4148;
