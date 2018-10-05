/*

This Code was written by Nihar Agrawal on 22 Sept. 2018, Lasted Updated 05 Oct 2018.
This code contain alot of possible Single Linked List Operations:-
1) All the Possible Inserting of Node in a Single Linked List
2) All the Possible Deletion of Node in a Single Linked List
3) Counting the number of Nodes in the Linked List
4) Searching for a particular number or Node in the Linked List
5) Printing the Linked List
6) Reversing a Linked List using recursion
Any number of linked list can be made by increasing the number of start pointer. 
Anyone can take the followeing code and improvise it upon as per their need


*/
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
/*------------------*--------------------Declaration  of all the Functions------------------*--------------------*/
struct node* create(struct node*,int);
struct node* insert_beg(struct node*,int);
struct node* insert_mid(struct node*,int,int,int);
struct node* delete(struct node*);
struct node* delete_beg(struct node*);
struct node* delete_mid(struct node*,int);
struct node* delete_all(struct node*);
struct node* reverse(struct node*);
int count(struct node*);
int search(struct node*,int num);
void print_ll(struct node*);
/*------------------*--------------------Main Function------------------*--------------------*/
int main(){
	struct node *start = NULL;
	int i = 1;
	while(i){
		printf("Select one of the option - \n1) Insert the Node at the End\n2) Insert the Node at the Beginning\n3) Insert the Node at a particular Position\n4) Delete the Node at the End\n5) Delete the Node at the Beginning\n6) Delete a Particular Node\n7) Delete linked list\n8) Count the number of nodes\n9) Print the Linked List\n10) Search a Number in the Linked List\n11) Reverse a Linked LIst using recursion\n0) Exit\n");
		int n,c = 0,data;
		scanf("%d",&n);
		switch(n){
			case 1: printf("Enter the data - ");
				scanf("%d",&data);
				start = create(start,data);
				printf("Node Created\n");
				break;
			case 2: printf("Enter the data - ");
				scanf("%d",&data);
				start = insert_beg(start,data);
				printf("Node Created\n");
				break;
			case 3: printf("Enter the data - ");
				scanf("%d",&data);
				printf("Enter the number near which the node is to be created - ");
				scanf("%d",&n);
				printf("Enter 0 for creating node to the left of the number and 1 for creating node to the right of the number - ");
				scanf("%d",&c);
				if(c == 0 || c == 1){
					start = insert_mid(start,data,n,c);
					printf("Node Created\n");
				}
				else{
					printf("Invalid Input please try again\n");
				}
				break;
			case 4: start = delete(start);
				printf("Node Deleted\n");
				break;
			case 5: start = delete_beg(start);
				printf("Node Deleted\n");
				break;
			case 6:printf("Enter the element to be deleted - ");
				scanf("%d",&data);
				start = delete_mid(start,data);
				break;
			case 7: start = delete_all(start);
				printf("Linked List Deleted\n");
				break;
			case 8: c = count(start);
				printf("The number of nodes in the linked list is - %d\n",c);
				break;
			case 9: print_ll(start);
				break;
			case 10: printf("Enter the number to be searched - ");
				scanf("%d",&data);
				c = search(start,data);
				if(c == -1)
					printf("Either the linked list is empty or the number to be searched is not present in the Linked List\n");
				else
					printf("Number to be searched is found at %d position of the linked list\n",c);
				break;
			case 11: start = reverse(start);
				printf("Resulting Reversed Linked List - ");
				print_ll(start);
				break;
			case 0: i = n;
				break;
			default: printf("Invalid Input\n");
		}
	}
	if(start != NULL)
		delete_all(start);
	return 0;
}
/*------------------*--------------------"Creating a Node at the End of the Linked List" Function------------------*--------------------*/
struct node* create(struct node *ptr,int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	struct node *p;
	if(ptr == NULL)
		ptr = temp;
	else{
		p = ptr;
		while(p->next != NULL)
			p = p->next;
		p->next = temp; 
	}
	return ptr;
}
/*------------------*--------------------"Inserting the Node in the beginning of the Linked List" Function------------------*--------------------*/
struct node* insert_beg(struct node *ptr,int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = ptr;
	ptr = temp;
	return ptr;
}
/*------------------*--------------------"Inserting the Node at a particular position of the Linked List" Function------------------*--------------------*/
struct node* insert_mid(struct node *ptr,int data,int num,int i){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	if(ptr == NULL){
		printf("The Linked list is empty so the node created is the first node\n");
		temp->next = ptr;
		ptr = temp;
	}
	else if(ptr->data == num && i == 0)
		insert_beg(ptr,data);
	else if(ptr->data == num && i == 1){
		temp->next = ptr->next;
		ptr->next = temp;
	}
	else{
		struct node *p = ptr->next,*p1 = ptr;
		while(p != NULL){
			if(p->data == num && i == 0){
				temp->next = p;
				p1->next = temp;
				break;
			}
			else if(p->data == num && i == 1){
				temp->next = p->next;
				p->next = temp;
				break;
			}
			p1 = p;
			p = p->next;
		}
		if(p == NULL){
			printf("The requested element is not present in the linked list\n");
			ptr = create(ptr,data);
		}
	}
	return ptr;
}
/*------------------*--------------------"Print Linked List" Function------------------*--------------------*/
void print_ll(struct node *ptr){
	if(ptr == NULL)
		printf("Underflow condition\n");
	else{
		while(ptr != NULL){
			printf("%d ",ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}
/*------------------*--------------------"Delete a Node from the End" Function------------------*--------------------*/
struct node* delete(struct node *ptr){
	struct node* temp;	
	if(ptr == NULL)
		printf("Underflow condition\n");
	else if(ptr->next == NULL){
		temp = ptr;
		ptr = NULL;
		free(temp);
	}
	else{
		struct node *p = ptr;
		while(p->next->next != NULL)
			p = p->next;
		temp = p->next;
		p->next = NULL;
		free(temp);
	}
	return ptr;
}
/*------------------*--------------------"Deleteing a Node in the Linked List from the Beginning" Function------------------*--------------------*/
struct node* delete_beg(struct node *ptr){
	struct node *temp = ptr;
	ptr = ptr->next;
	free(temp);
	return ptr;
}
/*------------------*--------------------"Deleting the Node from a particular position of the Linked List" Function------------------*--------------------*/
struct node* delete_mid(struct node *ptr,int num){
	struct node *temp = ptr;
	if(ptr == NULL)
		printf("Underflow condition\n");
	else if(ptr->data ==num)
		ptr = delete_beg(ptr);
	else{
		struct node *p = temp;
		temp = temp->next;
		while(temp != NULL){
			if(temp->data == num){
				 if(temp->next == NULL)
					ptr = delete(ptr);
				else{
					p->next = temp->next;
					free(temp);
				}
			}
			p = temp;
			temp = temp->next;
		}
	}
	return ptr;
}
/*------------------*--------------------"Delete the complete Linked List" Function------------------*--------------------*/
struct node* delete_all(struct node *ptr){
	struct node *temp = ptr;
	if(ptr == NULL)
		printf("Underflow condition\n");
	else{
		while(ptr != NULL){
			temp = ptr;
			ptr = ptr->next;
			free(temp);
		}
	}
	return ptr;
}
/*------------------*--------------------"Counting the number of elements in the Linked List" Function------------------*--------------------*/
int count(struct node *ptr){
	if(ptr == NULL)
		return 0;
	else if(ptr->next == NULL)
		return 1;
	else
		return 1 + count(ptr->next);
}
/*------------------*--------------------"Searching a particular number in the Linked List" Function------------------*--------------------*/
int search(struct node *ptr,int num){
	if(ptr == NULL)
		return -1;
	else{
		int count = 0;
		while(ptr != NULL){
			if(ptr->data == num)
				return count+1;
			count++;
			ptr = ptr->next;
		}
		return -1;
	}
}
/*------------------*--------------------"Reversing a Linked List using recursion" Function------------------*--------------------*/
struct node* reverse(struct node *p){
	if(p == NULL)
		return NULL;
	else if(p ->next == NULL)
		return p;
	else{
		struct node *temp = reverse(p->next);
		struct node *temp1 = temp;
		while(temp -> next != NULL)
			temp = temp->next;
		temp->next = p;
		p -> next = NULL;
		return temp1;
	}
}
