#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
int size =0;
//inserts at the head of the linked list
void top(struct node **head)
{
	struct node *temp;
	temp = malloc(sizeof(struct node));
	printf("Enter a number:");
	scanf("%d",&temp->data);
	temp->next=*head;
	*head = temp;
}

void delete(struct node **head){
	struct node *temp= malloc(sizeof(struct node));
	temp = *head;
	*head = temp->next;
	free(temp);
	size--;
}

void deleteTail(struct node **head,struct node **tail){
    struct node *temp;
    temp=*head;
	while(temp->next!=*tail){
		temp=temp->next;
	}
	*tail = temp;
	free(temp->next);
	temp->next=NULL;

}

void deleteChoice(struct node **head){
	int choice;
	printf("Enter a number to delete:");
	scanf("%d", &choice);
	getchar();
	struct node *temp;
	struct node *dataf;
	temp =*head;
	dataf = temp->next;
	while(dataf!=NULL){
	    if(temp->data == choice){
	        temp = *head;
	        *head = temp->next;
	        free(temp);
	        return;
	    }
		if(dataf->data == choice){
			temp->next = dataf->next;
			free(dataf);
			return;
		}
		temp=temp->next;
		dataf = temp->next;
	}
	printf("number not found\n");
}


void Display(struct node **head){
	printf("The linked list is:\n");
	struct node *temp;
	temp = *head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}

}

int main(){
	struct node *head;
	struct node *tail;
	head = NULL;
	int menu=0;
	while(menu == 0){
		int item;
		printf("what would you like to do?:\n");
		printf("1)create node/add a node to head.\n2)add node to tail\n3)delete from head\n 4)delete from tail\n 5)search and delete a number\n 6)print list\n 7)exit\nyour choice: ");
		scanf("%d", &item);
		getchar();
		switch(item){
			case (1):{top(&head);
				if(head->next==NULL){
				    tail=head;
				}
				break;}
			case (2):{top(&(tail->next));
				tail=tail->next;
				break;}
			case (3): {delete(&head);
				break;}
			case(4):{deleteTail(&head,&tail);
				break;}
			case(5):{deleteChoice(&head);
					break;
				}
			case(6):{Display(&head);
				break;
			}
			case (7):{menu =1;
				break;}
			default:{ printf("not an option\n");
			    break;}
		}
	}

	//releasing memory
	struct node *endtemp;
	while(head!=NULL)
	{
		endtemp=head;
		head=head->next;
		free(endtemp);	
	}
}