#include <stdio.h>
#include "stack.h"

/**
 * @brief Prints out the element.
 * @note The format specifier should be changed in accordance to the type defintion of StackEntry.
 * @param element The element to be printed.
 * @return None.
 */
void Display (StackEntry element);

/**
 * @brief An implementation of the function StackTop from the eye of the user.
 * @param pstack Address of the created stack.
 * @return The top-most element on the stack.
 */
StackEntry Client_StackTop (Stack_t *pstack);

/* Main application. */
int main (void)
{
    /* Creat the stack. */
    Stack_t my_stack;

    /* Initialize the stack. */
    InitStack (&my_stack);

    char menu_option = 0;
    
    StackEntry element = 0;

    do
    {
        /* Promt the user to choose from the displayed menu. */
    
        printf ("Choose an action:\n");
        printf ("a. Clear the stack.\n"
                "b. Read an element and Push it.\n"
                "c. Pop an element and display it.\n"
                "d. Display the stack size. \n"
                "e. Print the top of the stack.\n"
                "f. Exit.\n");

        scanf (" %c", &menu_option);

        switch (menu_option)
        {
        case 'a':
            /* Clear the stack. */
            ClearStack (&my_stack);
            break;

        case 'b':
            /* Read the element from the user and push it to the stack. */
            printf ("Enter the element you want to push: ");
            scanf ("%d", &element);

            if (!StackFull (&my_stack) )
            {
                Push (element, &my_stack);
            }
            else
            {
                printf ("Error, stack is full!\n");
            }
            break;

        case 'c':
            /* Pop an element and display it. */
            if (!StackEmpty (&my_stack) )
            {
                printf ("The element is ");
                Display ( Pop (&my_stack) );
                printf ("\n");
            }
            else
            {
                printf ("Error, stack is empty!\n");
            }
            break;
            
        case 'd':
            /* Display the stack size. */
            printf ("The stack size is: ");
            Display ( StackSize (&my_stack) );
            break;
        
        case 'e':
            /* Display the top most element on the stack. */
            printf ("The top of the stack is: %d\n", StackTop (&my_stack));
            Display ( StackTop (&my_stack) );
            printf ("\n");
            break;

        case 'f':
            printf ("The first element in the queue is: %d.\n", StackFirstElement (&my_stack));
            break;

        case 'g':
            printf ("The last element in the queue is: %d.\n", StackLastElement (&my_stack));
            break;

        case 'z':
            printf ("Closing ...");
        default:
            break;
        }

    } while (menu_option != 'e');
    

    return 0;
}

/*  User functions definition. */

void Display (StackEntry element)
{
    printf ("%d\t", element);
}
 
StackEntry Client_StackTop (Stack_t *pstack)
{
    StackEntry stack_top = 0;
    stack_top = Pop (pstack);
    Push (stack_top, pstack);

    return stack_top;
}

