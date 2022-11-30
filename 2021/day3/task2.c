#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LOG_SIZE 12

typedef struct list_t list_t;

struct list_t
{
    char *data;
    list_t* next;
};

void add_string(list_t** head, char* data) {
	list_t* node = malloc(sizeof(list_t));
	node->data = malloc(sizeof(char) * (LOG_SIZE + 1));
	memcpy(node->data, data, sizeof(char) * (LOG_SIZE + 1));
	node->next = *head;
	*head = node;
}

void pop(list_t** head) {
	list_t* tmp = *head;
	*head = tmp->next;
	free(tmp->data);
	free(tmp);
} 

int main() {
	list_t* oxygen = NULL;
	list_t* co2 = NULL;
	char input[LOG_SIZE + 1];
	char common[LOG_SIZE];
	int ones[LOG_SIZE];
	int nbr_logs = 0;

	/* Scaning input data*/
    while (scanf("%s", &input) != EOF)
    {
		/* Building linked list */
		add_string(&oxygen, input);
		add_string(&co2, input);		

		/* Counting bits */
		for (int i = 0; i < LOG_SIZE; i++) {
			if(input[i] == '1')
				ones[i] += 1;
		}
		nbr_logs += 1;	
    }

	for (size_t i = 0; i < LOG_SIZE; i++)
	{
		char common_bit = (nbr_logs - ones[i] <= ones[i]) ? '0' : '1';
		printf("%c", common_bit);
	}
	printf("\n");
	

	/* Filtering */
	for (int i = 0; i < LOG_SIZE; i++)
	{
		char common_bit = (ones[i] >= nbr_logs - ones[i]) ? '1' : '0';
		if(oxygen->next == NULL) {
			break; /* Stops filtering when only one entry in list */
		}

		if(oxygen->data[i] != common_bit)
			pop(&oxygen);

		list_t* node = oxygen;
		while (node->next != NULL)
		{
			if(node->next->data[i] != common_bit) {
				list_t* tmp = node->next;
				node->next = tmp->next;
				free(tmp->data);
				free(tmp);
			} else {
				node = node->next;
			}

		}	
	}

	for (int i = 0; i < LOG_SIZE; i++)
	{
		char common_bit = (nbr_logs - ones[i] <= ones[i]) ? '0' : '1';
		if(co2->next == NULL) {
			break; /* Stops filtering when only one entry in list */
		}

		if(co2->data[i] != common_bit)
			pop(&co2);

		list_t* node = co2;
		while (node->next != NULL)
		{
			if(node->next->data[i] != common_bit) {
				list_t* tmp = node->next;
				node->next = tmp->next;
				free(tmp->data);
				free(tmp);
			} else {
				node = node->next;
			}
		}	
	}

	printf("Result %d\n", strtol(oxygen->data, NULL, 2) * strtol(co2->data, NULL, 2));
	printf("%s", oxygen->data);
	free(oxygen->data);
	free(oxygen);
	free(co2->data);
	free(co2);              
}
