//In the program, there is a structure defined "node" which stores a pointer and an interger.

//In the fuction create we create_new_node and the value of the integer is stroed in it and it points to next node which is given as the input of the function. The function push_front and push_back use this function to add new node at the front and end respectively. 

//I would prefer to use the push_front frunction to include new nodes as as I have implemented the push_back function each time the function has to find the end node of the list. In the main fucton we only hve the head to regenerate the whole list of nodes. In order to find the end of the list I have scan throughout the list to find the node which points to null. It is computationally expensive to do that everytime I add a new node. 

//Here I am storing the input into an array. Then I am using push_front function to store them in the nodes. The push_fron function give sme the head as the outpus and using the get_list_length function I am calculating the number of elements in the list. 

//Then using the print_list function I am printing the list of elements. Before deleting the list I am searching for 42 in the list using the function search_of_42, then to varify I am again counting and printing the list.


#include <stdio.h>
#include <stdlib.h>

#define CANNOT_OPEN 7
#define CANNOT_ALLOCATE 9

typedef struct node{
    int value;
    struct node* next_val;
} node;

node* create_new_node(int value,node* next_val);
node* push_front(node* head,int value);
int get_list_length(node *head);
int print_list(node *head);
int search_of_42(node *head);
node* push_back(node* head, int value);
node* delete_list(node *head);

//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
 
int main()
{
  int n,i,j;
	node* head =NULL;
	printf("Number of elelment: %d\n",get_list_length(head));
  // read from text file
  FILE *numbers =  fopen("input","r");
  if (!numbers){
      fprintf (stderr,"Error!\n");
      return CANNOT_OPEN;
    }
  
  fscanf(numbers, "%d", &n);
  printf("numbers %d\n", n);

  int *v = (int*)malloc(sizeof(int)*n);
  if(!v){
      fprintf (stderr,"Error!\n");
      return CANNOT_ALLOCATE;
    }
    

  for (i=0;i<n;++i) {
    fscanf(numbers,"%d",&v[i]);
    head = push_front(head, v[i]);  
//		head = push_back(head, v[i]);
	}    
  // rememeber to close
  fclose(numbers);
  free(v);
  j = get_list_length(head);
	printf("Number of elelment: %d\n",j);
	print_list(head);
	search_of_42(head);
	head = delete_list(head);
  j = get_list_length(head);
	printf("Number of elelment: %d\n",j);	
	print_list(head);
 
 return 0;
}

//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//

//    creating a new node
node* create_new_node(int value,node* next_val){
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL) exit(0);
    new_node->value = value;
    new_node->next_val = next_val;
 
    return new_node;
}
 
//    insert a new node at the beginning of the list
node* push_front(node* head,int value){
    node* new_node = create_new_node(value,head);
    head = new_node;
    return head;
}

//    counting the number of elements in the list

int get_list_length(node *head){
	int i=0;
	node *current_node;
	if (head == NULL){
		return i;
	}
	else{
	for(current_node = head; current_node != NULL; current_node = current_node->next_val) 
      i++;
   return i;
   }
}


// printing the list of nodes 

int print_list(node *head){
	  node *current_node = head;
    int i;
    if (head == NULL){
    printf("List doesn't exist\n");}
    else{
    while(current_node != NULL){
    	i = current_node->value;
			printf("%d\n",i);
    	current_node = current_node->next_val;}
    	}
    return 0;	 
}

// searching the number 42 in the list of elements
int search_of_42(node *head){
	  node *current_node = head;
    int i,j;
    while(current_node != NULL){
    	i = current_node->value;
    	if (i == 42) {
				printf("42.....found the answer to the universe!!\n");    			
				j=i;
				}
    	current_node = current_node->next_val;
    	}
    	if (j != 42) {
    	printf("42 not found\n" );}
    return 0;	 
}
 
//    add a new node at the end of the list

node* push_back(node* head, int value)
{		
      	node *current_node = head;	  
    if(head == NULL){
      	node* new_node =  create_new_node(value,NULL);
    		head = new_node;
  		  }
  	else{
  	while (current_node->next_val != NULL){	  
  		  current_node = current_node->next_val;
  		  }  
    	node* new_node =  create_new_node(value,NULL);
    	current_node->next_val = new_node;
    }
    return head;
}

//    Deleting all the elements of the list
node* delete_list(node *head){
    node *current_node;
    node *tmp;
 		if (head == NULL){
 			 return NULL;
 		}
    else{
        current_node = head->next_val;
        head->next_val = NULL;
        while(current_node != NULL){
            tmp = current_node->next_val;
            free(current_node);
            current_node = tmp;
        }
        free(head);
        head = NULL;
        return head;
    }
}

//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
