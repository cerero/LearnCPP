#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int args, char **argv) {
	/*char buf[100];
	int a = 10;
	int *p = NULL;
	
	p = &a;
	*p = 20;
	
	{
		char *p2 = NULL;
		p2 = (char *) malloc(100);
		if (p2 != NULL) {
			free(p2);	
			p2 = NULL;
		}	
		
		if (p2 != NULL) {
			free(p2);	
		}
	}*/
	int *i1 = NULL;
	char *p3 = NULL;
	char ****p4 = NULL;

	printf("sizeof(int)=%d\n", sizeof(int));
	printf("i1=%d, i1+1=%d\n", i1, i1 + 1);
	printf("sizeof(p3)=%d\n", sizeof(p3));
	printf("sizeof(p4)=%d\n", sizeof(p4));
	printf("p3=%d, p3+1=%d\n", p3, p3 + 1);
	printf("p3=%d, p4+1=%d\n", p4, p4 + 1);
	
	return 0;	
}