#include <stdio.h>

int main() {
    int horizontal = 0;
    int depht = 0;
    int tmp = 0;
    char command[10];

    while (scanf("%s %d", &command, &tmp) == 2)
    {
	switch(command[0]) {
	   case 'f':
		horizontal += tmp;
		break;
	   case 'd':
		depht += tmp;
		break;
	   case 'u':
		depht -= tmp;
		break;
	}
    }
    printf("Answer: %d\n", depht * horizontal);                   
}
