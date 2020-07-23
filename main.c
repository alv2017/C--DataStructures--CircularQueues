#include <stdio.h>
#include <stdlib.h>
#include "menu/menu.h"
#include "src/circular_queue.h"

#define clear() printf("\033[H\033[J")

const char *menu[] = {
		" 1. Add element to the queue.",
		" 2. Remove element from the queue.",
		" 3. Return the value of the first queue element.",
		" 4. Display queue items.",
		" 5. Exit the program",
		NULL
};

int main(void) {
	op_status = 0;

	// Circular Queue
	int qdata[QSIZE] = {0};
	cqueue.first = -1;
	cqueue.last = -1;
	cqueue.data = qdata;

	struct queue *qptr = &cqueue;

	// Menu
	short opt;
	const short MINOPT = 1;
	const short MAXOPT = get_menu_length(menu);
	clear();
	display_menu(menu);

	opt = select_option(MINOPT, MAXOPT);

	while (1) {
		printf("You have selected: %d\n", opt);
		switch (opt) {
			case 1:
				clear();
				printf("Adding a new element to stack.\n");
				int new_val = enter_value(&op_status);
				queue_insert(qptr, new_val, &op_status);
				break;

			case 2:
				clear();
				printf("Removing an element from stack.\n");
				int removed_value = queue_remove(qptr, &op_status);
				if (op_status == 1) {
					printf("Removed value: %d\n", removed_value);
				}
				break;

			case 3:
				clear();
				printf("Returning the value of the first queue element:\n");
				int first_element = queue_first(qptr, &op_status);
				if (op_status == 1) {
					printf("The value of the first queue element is %d.\n", first_element);
				}
				break;

			case 4:
				clear();
				printf("Displaying queue items.\n");
				display_queue(qptr);
				break;

			case 5:
				clear();
				printf("Exiting the program\n");
				return 0;
		}
		// Asking user for further actions;
		display_menu(menu);
		opt = select_option(MINOPT, MAXOPT);
	}
	return 0;
}
