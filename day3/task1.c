#include <stdio.h>
#include <stdlib.h>

#define LOG_SIZE 12

int main() {
	char input[LOG_SIZE + 1];
    char epsilon_str[LOG_SIZE + 1];
	char gammat_str[LOG_SIZE + 1];
	int ones[LOG_SIZE];
	int logs = 0;

	/* Counting zeroes and ones */
    while (scanf("%s", &input) != EOF)
    {
		for (int i = 0; i < LOG_SIZE; i++) {
			if(input[i] == '1')
				ones[i] += 1;
		}
		logs += 1;	
    }

	/* Building epsilon and gamma */
	for (int i = 0; i < LOG_SIZE; i++)
	{

		if(ones[i] > logs - ones[i]) {
			epsilon_str[i] = '1';
			gammat_str[i] = '0';
		} else {
			epsilon_str[i] = '0';
			gammat_str[i] = '1';
		}
	}
	gammat_str[LOG_SIZE] = '\0';
	
	int epsilon = strtol(epsilon_str, NULL, 2);
	int gamma = strtol(gammat_str, NULL, 2); 

    printf("Power consumption %d\n", epsilon * gamma);                   
}
