//
//	DoublyLinkedList.c
//	Doubly Linked List Operations
//
//	Created by Avikant Saini on 11/16/15
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

#define initString(size) (char *)malloc(size * sizeof(char));

typedef char * String;

typedef enum { NO, YES } BOOL;

#pragma mark - String utilities

BOOL equalsIgnoreCase (String stra, String strb) {
	
	long la = strlen(stra), lb = strlen(strb);
	
	if (la != lb) return NO;
	
	long i;
	for (i = 0; i < la; ++i) {
		
		char za = *(stra + i), zb = *(strb + i);
		int diff = abs(za - zb);
		
		if (!(diff == 0 || diff == 32))
			return NO;
	}
	
	return YES;
}

BOOL containsString (String string, String substring) {
	
	String tstr = string;
	String tsub = substring;
	
	String tsubend = substring + strlen(substring);
	
	while (*tstr != '\0') {
		
		while (*tsub != '\0' && *tstr == *tsub) {
			tstr++;
			tsub++;
		}
		
		if (tsub == tsubend)
			return YES;
		else
			tsub = substring;
		
		tstr++;
	}
	
	return NO;
}

#pragma mark - Node initilization

typedef struct Node {
	String data;
	struct Node *prev;
	struct Node *next;
} NODE_t, *NODE_p_t;

NODE_p_t initNode (String data) {
	NODE_p_t node = (NODE_p_t)malloc(sizeof(NODE_t));
	node->data = initString(SIZE);
	strcpy(node->data, data);
	node->prev = node;
	node->next = node;
	return node;
}

#pragma mark - Insert

BOOL insertFront (NODE_p_t list, String data) {
	
	NODE_p_t temp = initNode(data);
	NODE_p_t first = list->next;
	
	list->next = temp;
	temp->next = first;
	first->prev = temp;
	temp->prev = list;
	
	return YES;
}

BOOL insertRear (NODE_p_t list, String data) {
	
	NODE_p_t temp = initNode(data);
	NODE_p_t last = list->prev;
	
	last->next = temp;
	temp->prev = last;
	temp->next = list;
	list->prev = temp;
	
	return YES;
}

#pragma mark - Delete

String deleteFront (NODE_p_t list) {
	
	if (list->next == list)
		return NULL;
	
	NODE_p_t first = list->next;
	NODE_p_t second = first->next;
	
	list->next = second;
	second->prev = list;
	
	String data = first->data;
	free(first);
	
	return data;
}

String deleteRear (NODE_p_t list) {
	
	if (list->prev == list)
		return NULL;
	
	NODE_p_t last = list->prev;
	NODE_p_t slast = last->prev;
	
	list->prev = slast;
	slast->next = list;
	
	String data = last->data;
	free(last);
	
	return data;
}

/**
 *	Delete all occurences of an item from a list.
 *	Returns a BOOL value (1, 0) - Item is deleted or not.
 */

BOOL deleteItem (NODE_p_t list, String item) {
	
	if (list->next == list)
		return NO;
	
	NODE_p_t temp = list->next;
	NODE_p_t tpre, tnxt;
	
	BOOL found = NO;
	
	while (temp != list) {
		
		tpre = temp->prev;
		tnxt = temp->next;
		
		if (equalsIgnoreCase(temp->data, item)) {
			tpre->next = tnxt;
			tnxt->prev = tpre;
			free(temp);
			found = YES;
		}
		
		temp = temp->next;
	}
	
	return found;
}

#pragma mark - Search (ignore case)

BOOL searchItem (NODE_p_t list, String item) {
	
	if (list->next == list)
		return NO;
	
	NODE_p_t temp = list->next;
	
	while (temp != list) {
		if (equalsIgnoreCase(temp->data, item))
			return YES;
		temp = temp->next;
	}
	
	return NO;
}

#pragma mark - Display

void displayList (NODE_p_t list, String id) {
	
	if (list->next == list) {
		printf("\n\tEmpty List!");
		return;
	}
	
	printf("\n\tList %s: ", id);
	printf(" <-{");
	
	NODE_p_t temp = list->next;
	
	while (temp->next != list) {
		printf(" %s <->", temp->data);
		temp = temp->next;
	}
	
	printf(" %s }->\n", temp->data);
}

#pragma mark - Sort List

/**
 *	Find the half of the list using the slow-fast pointer concept.
 *	Copy one half to one list, and other to other list.
 */

void splitLists (NODE_p_t list, NODE_p_t *alist, NODE_p_t *blist) {
	
	NODE_p_t fast = list->next;
	NODE_p_t slow = list->next;
	
	while (fast != list) {
		fast = fast->next;
		slow = slow->next;
		if (fast != list)
			fast = fast->next;
	}
	
	NODE_p_t temp = list->next;
	
	*alist = initNode("<HEAD A>");
	*blist = initNode("<HEAD B>");
	
	while (temp != slow) {
		insertRear(*alist, temp->data);
		temp = temp->next;
	}
	
	while (temp != list) {
		insertRear(*blist, temp->data);
		temp = temp->next;
	}
	
}

NODE_p_t mergeLists (NODE_p_t alist, NODE_p_t blist) {
	
	NODE_p_t list = initNode("<HEAD>");
	
	NODE_p_t tempa = alist->next;
	NODE_p_t tempb = blist->next;
	
	while (tempa != alist && tempb != blist) {
		
		if (strcmp(tempa->data, tempb->data) < 0) {
			insertRear(list, tempa->data);
			tempa = tempa->next;
		}
		else if (strcmp(tempa->data, tempb->data) > 0) {
			insertRear(list, tempb->data);
			tempb = tempb->next;
		}
		else {
			insertRear(list, tempa->data);
			insertRear(list, tempb->data);
			tempa = tempa->next;
			tempb = tempb->next;
		}
	}
	
	while (tempa != alist) {
		insertRear(list, tempa->data);
		tempa = tempa->next;
	}
	
	while (tempb != blist) {
		insertRear(list, tempb->data);
		tempb = tempb->next;
	}
	
	return list;
}

/**
 *	Sorting the lists using merge sort.
 *	If the list is empty or contains one element, return.
 *	Split the list into two parts.
 *	Sort each part.
 *	Merge the sorted parts.
 */

void sortList (NODE_p_t *list) {
	
	NODE_p_t head = *list;
	
	if (head->next == head)
		return;
	
	if (head->next->next == head)
		return;
	
	NODE_p_t alist = NULL, blist = NULL;
	
	splitLists(head, &alist, &blist);
	
	sortList(&alist);
	sortList(&blist);
	
	*list = mergeLists(alist, blist);
	
}

#pragma mark - Reverse List

/**
 *	Since the list has a header, get the first and last elements of the list.
 *	Delete the curcular links from the first and last element.
 *	Traverse through the list, from first to last, swap the links.
 *	Set the first element as the last, and last as the first.
 *	Set the circular links of first and last accordingly.
 */

void reverseList (NODE_p_t *list) {
	
	NODE_p_t head = *list;
	
	NODE_p_t first = head->next;
	NODE_p_t last = head->prev;
	
	first->prev = NULL;
	last->next = NULL;
	
	NODE_p_t curr = first;
	
	while (curr != NULL) {
		NODE_p_t temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}
	
	head->next = last;
	head->prev = first;
	
	first->next = head;
	last->prev = head;
}

#pragma mark - List containing item

NODE_p_t listContainingSubstring (NODE_p_t list, String substr) {
	
	NODE_p_t nlist = initNode("SLIST");
	
	NODE_p_t temp = list->next;
	
	while (temp != list) {
		
		if (containsString(temp->data, substr))
			insertRear(nlist, temp->data);
		
		temp = temp->next;
	}
	
	return nlist;
}

#pragma mark - Remove duplicates

void removeDuplicates (NODE_p_t list) {
	
	NODE_p_t temp = list->next;
	
	while (temp->next != list) {
		
		NODE_p_t tnext = temp->next;
		
		while (equalsIgnoreCase(temp->data, tnext->data)) {
			NODE_p_t tnextnext = tnext->next;
			temp->next = tnextnext;
			tnextnext->prev = temp;
			tnext = temp->next;
		}
		
		temp = temp->next;
	}
	
}

#pragma mark - Main

int main (int argc, const char * argv []) {
	
	NODE_p_t list = initNode("<HEAD>");
	
	insertRear(list, "RICK");
	insertRear(list, "DARYL");
	insertRear(list, "GLENN");
	insertRear(list, "GLENN");
	insertRear(list, "MICHONNE");
	insertRear(list, "CARL");
	insertRear(list, "CAROL");
	insertRear(list, "GLENN");
	insertRear(list, "MAGGIE");
	displayList(list, "TWD");
	
	int choice;
	
	do {
		printf("\n------------------------------------------------------------------------");
		printf("\n\t 1. Insert Rear.");
		printf("\n\t 2. Insert Front.");
		printf("\n\t 3. Delete Front.");
		printf("\n\t 4. Delete Rear.");
		printf("\n\t 5. Delete Item.");
		printf("\n\t 6. Search Item.");
		printf("\n\t 7. Search Item (substring).");
		printf("\n\t 8. Sort List.");
		printf("\n\t 9. Reverse List.");
		printf("\n\t10. Remove Duplicates.");
		printf("\n\t 0. Display");
		printf("\n\tChoice: ");
		scanf(" %d", &choice);
		
		if (choice == 1 || choice == 2) {
			String str = initString(SIZE);
			printf("\n\tEnter item to be inserted: ");
			scanf(" %s", str);
			if (choice == 1)
				insertRear(list, str);
			else if (choice == 2)
				insertFront(list, str);
		}
		
		if (choice == 3 || choice == 4) {
			String str;
			if (choice == 3)
				str = deleteFront(list);
			else if (choice == 4)
				str = deleteRear(list);
			printf("\n\tDeleted item: '%s'.\n", str);
		}
		
		if (choice == 5) {
			String str = initString(SIZE);
			printf("\n\tEnter item to be deleted: ");
			scanf(" %s", str);
			if (deleteItem(list, str))
				printf("\n\tDeleted item(s): '%s'.\n", str);
			else
				printf("\n\t'%s' not found in the list.\n", str);
		}
		
		if (choice == 6) {
			String str = initString(SIZE);
			printf("\n\tEnter item to be searched: ");
			scanf(" %s", str);
			if (searchItem(list, str))
				printf("\n\t'%s' found in the list.\n", str);
			else
				printf("\n\t'%s' not found in the list.\n", str);
		}
		
		if (choice == 7) {
			String str = initString(SIZE);
			printf("\n\tEnter item to be searched: ");
			scanf(" %s", str);
			NODE_p_t slist = listContainingSubstring(list, str);
			if (slist->next == slist)
				printf("\n\tNo such element found.");
			else
				displayList(slist, "Substrings");
		}
		
		if (choice == 8) {
			sortList(&list);
			printf("\n\tSorted successfully.");
		}
		
		if (choice == 9) {
			reverseList(&list);
			printf("\n\tReversed successfully.");
		}
		
		if (choice == 10) {
			sortList(&list);
			removeDuplicates(list);
			printf("\n\tRemoved duplicates.");
		}
		
		displayList(list, "TWD");
		
	} while (choice >= 1 && choice <= 10);
	
}
