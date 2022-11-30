#include <stdio.h>

int main() {
    int horizontal = 0;
    int depht = 0;
    int aim = 0;
    int tmp = 0;
    char command[10];

    while (scanf("%s %d", &command, &tmp) == 2)
    {
	switch(command[0]) {
	   case 'f':
		horizontal += tmp;
		depht += aim * tmp;
		break;
	   case 'd':
		aim += tmp;
		break;
	   case 'u':
		aim -= tmp;
		break;
	}
    }
    printf("Answer: %d\n", depht * horizontal);                   
}
