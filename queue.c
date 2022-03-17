#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Declaring the structure of the node
struct node {
    int value;
    struct node *next;

};

//declaring all functions
int empty(struct node *list);//takes in the linked list as a parameter and returns 1 and 0 depending upon whether the linked list is empty or not
int size(struct node *list);//takes in the linked list as a parameter and returns its size
struct node *push(struct node *list, int x);//takes in the linked list and an integer as a parameter and adds a new node to the pointed linked list , assigns the integer value and returns it
int front(struct node *list);//takes in the linked list as a parameter and returns the first inserted element of the given queue
struct node *pop(struct node *list);//takes in the linked list as a parameter and deletes the first inserted element of the queue(last element of the linked list) and returns it
void traverse(struct node *list);//takes in the linked list as a parameter and simply prints out the values by traversing through the whole linked list

int main()
{
    struct node *list = NULL;
    char c,d;
    // Instructions of the Queue Commands
    printf("Welcome to the Queue program.\n\nHere are the guidelines to the codes you should use to access the functions:\n\n");
    printf("To use the empty(s) function, use 'em'.\n");
    printf("To use the size(s) function, use 'si'.\n");
    printf("To use the front(s) function, use 'fr'.\n");
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
                printf("empty(s): Returns 1 if the queue is empty. Returns 0 otherwise.\n\n");
                printf("Your Result: ");
                //checks return value of empty(s)
                empty(list) ? printf("The queue is empty.\n\n") : printf("The queue is not empty.\n\n");

            }
            else{
                //if a code doesn't match the function provided but starts with an 'e'
                printf("Illegal Code.\n\n");
            }
            break;
            case 's':
            if (d == 'i'){
                printf("size(s): Returns the number of elements in the queue.\n\n");
                //Returns number of elements in the queue
                printf("Your Result: There are %d elements in the queue.\n\n", size(list));
            }
            else{
                //if a code doesn't match the function provided but starts with a 's'
                printf("Illegal Code.\n\n");
            }

            break;
            case 'p': switch(d){
                case 'o': printf("pop(s): Deletes the first inserted element of the queue. If the queue is empty, it shows an error message.\n\n");
                //pops an element to the queue
                list = pop(list);
                break;
                case 'u': printf("push(s, x): Insert the element x into the queue.\n\n");
                int input;
                printf("What is the identification of your element?: ");
                //takes input of the identity of the element
                scanf("%d", &input);
                printf("\n");
                list = push(list, input);
                break;
                //if a code doesn't match the function provided but starts with a 'p'
                default: printf("Illegal Code.\n\n");
            }
            break;

            case 't':
            if (d == 'r'){
                //traverses through the whole queue and prints out the elements
                printf("traverse(s): Sequentially traverses the queue, printing all the elements in it.\n\n");
                traverse(list);
            }
            else{
                //if a code does not match the function provided but starts with a 't'
                printf("Illegal Code.\n\n");
            }
            break;
            case 'f':
            if (d == 'r'){
                printf("front(s): Returns the first inserted element of the queue. If the queue is empty, it shows an error message.\n\n");
                //stores the front element of the queue
                int temp = front(list);
                //checks if the queue is empty
                if (temp == 0 && empty(list)){
                    printf("Error! There are no elements in the queue. Add some elements to return the first inserted element of the queue.\n\n");
                }
                //If not, prints the first inserted element of the queue
                else{
                    printf("The first inserted element of the queue is %d.\n\n", temp);
                }
            }
            //if the code does not match with the functions provided but starts with a 'f'
            else {
                printf("Illegal Code.\n\n");
            }
            break;
            case 'q':
            //quits the program
            if (d == 'u'){
                printf("You have decided to Quit the Queue Program. Bye Bye!\n");
                return 0;
            }
            //If the code does not match with the functions provided
            default: printf("Illegal Code.\n\n");
            break;
        }

    }

}

int empty(struct node *list)
{
    //Returns 1 if the list is empty. Otherwise, returns 0
    if (!list){
        return 1;
    }
    return 0;
}

int size(struct node *list)
{
    struct node *p;
    int count = 0;
    //iterates through the whole linked list
    for (p = list; p != NULL; p = p->next){
        count++;
    }
    //return number of elements
    return count;
}

struct node *push(struct node *list, int x)
{
    //checks if there is space for a new node
    struct node *new_node = malloc(sizeof(struct node));
    //if not, terminates the program with an error message.
    if (new_node == NULL){
        printf("Error! Malloc Failed in Push! We have to terminate your program now!\n");
        exit(EXIT_FAILURE);
    }
    //if there is space, it makes a new node to add to the linked list
    new_node->value = x;
    new_node->next = list;
    return new_node;
}

int front(struct node *list){
    //if list is empty, no first element to show and hence 0
    if (empty(list)){
        return 0;
    }
    //if not, return the first element of the queue by going to the last element of the linked list
    else{
        struct node *cur;
        for (cur = list; cur->next != NULL; cur = cur->next);
        int top = cur->value;
        return top;
    }


}

struct node *pop(struct node *list){
    //if list is empty, prints error message and returns the list
    if (empty(list)){
        printf("Error! There are no elements in the Queue. Add some elements to delete the first inserted element.\n\n");
        return list;
    }
    //if not, then two struct nodes iterates simultaneously to go to the last element
    else
    {
        struct node *cur, *prev;
        for (prev = NULL, cur = list; cur->next != NULL; prev = cur, cur = cur->next);
        //if the size of the queue is 1, the list basically points to the next element and frees the cur and list is returned
        if (size(list) == 1){
            list = list->next;

        }
        //if not, the prev points to the address cur was pointing too and cur is freed and list is returned
        else{
            prev->next = cur->next;

        }
        free(cur);
        return list;
    }

}
void traverse(struct node *list){
     //if list is empty, print error message
    if (empty(list)){
        printf("Error! The queue is empty. Add elements to traverse elements.\n\n");
    }
    //if not, print all the elements in the queue in sequence
    else{
        struct node *p;
        printf("Elements in queue sequence: ");
        for (p = list; p != NULL; p = p->next){
            int show = p->value;
            printf("%d ", show);
        }
        printf("\n\n");
    }

}



