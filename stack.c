#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



// Declaring the structure of the node
struct node {
    int value;
    struct node *next;

};

//declaring all functions
int size(struct node *list); //takes in the linked list as a parameter and returns its size
int empty(struct node *list);//takes in the linked list node as a parameter and returns 1 and 0 depending upon whether the linked list is empty or not
int top(struct node *list);//takes in the linked list node as a parameter and returns the topmost element of the given stack
struct node *push(struct node *list, int x);//takes in the linked list and an integer as a parameter and adds a new node to the pointed linked list , assigns the integer value and returns it
struct node *pop(struct node *list);//takes in the linked list and deletes the most recent element of the stack and returns the linked list
void traverse(struct node *list);//takes in the linked list and simply prints out the values by traversing through the whole linked list



int main()
{
    struct node *list = NULL;
    char c,d;
    // Instructions of the Stack Commands
    printf("Welcome to the Stack program.\n\nHere are the guidelines to the codes you should use to access the functions:\n\n");
    printf("To use the empty(s) function, use 'em'.\n");
    printf("To use the size(s) function, use 'si'.\n");
    printf("To use the top(s) function, use 'to'.\n");
    printf("To use the push(s, x) function, use 'pu'.\n");
    printf("To use the pop(s) function, use 'po'.\n");
    printf("To use the traverse(x) function, use 'tr'.\n");
    printf("To quit the program, use 'qu'.\n\n");

    //To take operation codes under an infinite loop
    while(1){
        d = 'q';
        printf("Enter Operation Code: ");
        //Takes input
        scanf(" %c%c", &c, &d);
        if (d != '\n'){
            while(getchar() != '\n');
        }
        //switch statement to allocate the codes to its functions
        switch(c)
        {
            case 'e':
            if (d == 'm'){
                printf("empty(s): Returns 1 if the stack is empty. Returns 0 otherwise.\n\n");
                printf("Your result: ");
                //checks return value of empty(s)
                empty(list) ? printf("The stack is empty.\n\n") : printf("The stack is not empty.\n\n");

            }
            else{
                //if a code doesnt match the function provided but has an 'e'
                printf("Illegal Code.\n\n");
            }
            break;
            case 's':
            if (d == 'i'){
                printf("size(s): Returns the number of elements in the stack.\n\n");
                //returns number of elements in the stack
                printf("Your Result: There are %d elements in the stack.\n\n", size(list));

            }
            else{
                //if a code doesnt match the function provided but has a 's'
                printf("Illegal Code.\n\n");
            }

            break;
            case 'p': switch(d){
                case 'o': printf("pop(s): Deletes the topmost element of the stack. If the stack is empty, it shows an error message.\n\n");
                //deletes the topmost element of the stack
                list = pop(list);
                break;
                case 'u': printf("push(s, x): Insert the element x into the stack.\n\n");
                int input;
                printf("What is the identification of the element?: ");
                //takes in the identity of the element
                scanf("%d", &input);
                //makes a new node and stores the element
                list = push(list, input);
                printf("\n");
                break;
                //if a code doesn't match the functions but has a 'p'
                default: printf("Illegal Code.\n\n");
            }
            break;
            case 't': switch (d){
                case 'o': printf("top(s): Returns the topmost element of the stack. If the stack is empty, it shows an error message.\n\n");
                //stores the value of the topmost element of the stack
                int temp = top(list);
                //checks if the stack is empty
                if (temp == 0 && empty(list)){
                    printf("Error! There are no elements in the Stack. Add some elements to return the topmost element of the stack.\n\n");
                }
                else{
                    printf("The topmost element of the stack is %d.\n\n", temp);
                }
                break;
                case 'r': printf("traverse(s): Sequentially traverses the stack, printing all the elements in it.\n\n");
                //traverse function called
                traverse(list);
                break;
                //if code does not match with the functions but starts with 't'
                default : printf("Illegal Code.\n\n");
            }
            break;
            case 'q':
            if (d == 'u'){
                //quits the program
                printf("You have decided to Quit the Stack Program. Bye Bye!\n");
                return 0;
            }
            //If the code does not match with any of the functions
            default: printf("Illegal Code.\n");
            break;
        }

    }

}


int empty(struct node *list){
    //Returns 1 if the stack is empty. Returns 0 otherwise.
    if (!list){
        return 1;
    }


}

int size(struct node *list){
    struct node *p;
    int count = 0;
    //iterates through the whole linked list
    for (p = list; p != NULL; p = p->next){
        count++;
    }
    //return number of elements
    return count;

}

int top(struct node *list){
    //if size of list is 0, it shows error

    if (size(list) == 0){
        return 0;
    }
    //if not, it returns the topmost element of the list
    else{
        int first = list->value;
        return first;
    }
}

struct node *push(struct node *list, int x)
{
    //checks if there is space for a new node
    struct node *new_node = malloc(sizeof(struct node));
    //if not, terminates the program with an error message.
    if (new_node == NULL){
        printf("Error! Malloc Failed in Push! We have to terminate your program now!");
        exit(EXIT_FAILURE);
    }
    //if there is space, it makes a new node to add to the linked list
    new_node->value = x;
    new_node->next = list;
    return new_node;
}
    return 0;

struct node *pop(struct node *list){
    //if list is empty, print error message
    if (empty(list)){
        printf("Error! There are no elements in the Stack. Add some elements to delete the topmost element.\n\n");
        return list;
    }
    //if not, pop the first element of the list.
    else{
        struct node *cur;
        cur = list;
        list = list->next;
        free(cur);
        return list;
    }

}

void traverse(struct node *list)
{
    //if list is empty, print error message
    if (empty(list)){
        printf("Error! The stack is empty. Add elements to traverse elements.\n\n");
    }
    //if not, print all the elements in the stack in sequence
    else{
        struct node *p;
        printf("Elements in stack sequence: \n");
        for (p = list; p != NULL; p = p->next){
            int show = p->value;
            printf("%d\n", show);
        }
        printf("\n");
    }

}


