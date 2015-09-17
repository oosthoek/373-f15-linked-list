#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	
	if(head->index > new_element->index)
	{
		new_element->next = head;
		return new_element;
	}
	
	list_t* temp1 = head;
	list_t* temp2 = head->next;
	
	while(temp2 != 0)
	{
		if(temp2->index > new_element->index)
		{
			temp1->next = new_element;
			new_element->next = temp2;
			return head;
		}
		else
		{
			temp1 = temp2;
			temp2 = temp2->next;
		}
	}
	temp1->next = new_element;
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);

	list_t* previous = 0;
	list_t* current = head;
	list_t* after = head->next;

	while(after != 0)
	{
		current->next = previous;
		previous = current;
		current = after;
		after = after->next;
	}

	current->next = previous;

	return current;
}

