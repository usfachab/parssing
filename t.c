#include<unistd.h>
int main()
{
	char *s[]={"fojghjfkogjfkogjo", "-l", NULL};
	execve("/bin/ls", s, NULL);
}