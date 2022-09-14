#include <stdint.h>
#include "stack.h"

/**
 * @brief Appends an element to the the top of the stack.
 * @details Pre-conditions: The stack must be created and not full. \n
 *          Post conditions: The element is appended to the stack on the top-most level.
 * @warning A check on the status of the stack must be performed before performing the push.
 * @param element Value to be pushed to the stack.
 * @param pstack Address of the created stack.
 * @return None.
 */
void Push (StackEntry element, Stack_t *pstack)
{
    pstack -> entry [ pstack -> top ++ ] = element;
}

/**
 * @brief Removes the top-most element of the stack.
 * @details Pre-conditions: The stack must be created and not empty. \n
 *          Post condition: The top-most level of the stack is removed.
 * @warning A check on the status of the stack must be performed before performing the pop.
 * @param pstack Address of the created stack.
 * @return The top-most element of the stack.
 */
StackEntry Pop (Stack_t *pstack)
{
    return ( pstack -> entry [ -- pstack -> top ] );
}

/**
 * @brief Checks if the stack is full.
 * @details Pre-condition: The stack has been created and initialized. \n
 *          Post condition: The function returns True (1) if the stack is full otherwise it returns False (0).
 * @param pstack Address of the created stack.
 * @return The state of the stack.
 */
uint8_t StackFull (Stack_t *pstack)
{
    if ( pstack -> top == MAXSTACK )
    {
        return True;
    }
    else
    {
        return False;
    }
}

/**
 * @brief Checks if the stack is empty.
 * @details Pre-condition: The stack has been created and initialized. \n
 *          Post condition: The function returns True (1) if the stack is empty otherwise it returns False (0).
 * @param pstack Address of the created stack.
 * @return The state of the stack.
 */
uint8_t StackEmpty (Stack_t *pstack)
{
    if ( pstack -> top == 0)
    {
        return True;
    }
    else
    {
        return False;
    }
}

/**
 * @brief Initializes the values of the stack.
 * @details Pre-condition: The stack must be created. \n
 *          Post condition: The stack is initialized to be empty.
 *          The function initializes the value of the top pointer which points to the top of the stack to 0.
 * @param pstack Address of the created stack.
 * @return None.
 */
void InitStack (Stack_t *pstack)
{
    pstack -> top = 0;
}

/**
 * @brief Returns the top-most element of the stack.
 * @details Pre-condition: The stack exists and not empty. \n
 *          Post condition: The top-most element of the stack is returned without changing the stack itself.
 * @param pstack Address of the created stack.
 * @return The top-most element of the stack.
 */
StackEntry StackTop (Stack_t *pstack)
{
    return ( pstack -> entry [ pstack -> top ] );
}

/**
 * @brief Returns the size of the stack.
 * @details Pre-condition: The stack exits and has been initialized. \n
 *          Post condition: The function returns the number of elements present in the stack.
 * @param pstack Address of the created stack.
 * @return The size of the stack.
 */
uint8_t StackSize (Stack_t *pstack)
{
    return ( pstack -> top - 1 );
}

/**
 * @brief Clears the stack.
 * @details Pre-condition: The stack has been created. \n
 *          Post condition: All the elements of the stack has been deleted and the stack is reset.
 * @param pstack Address of the created stack.
 * @return None.
 */
void ClearStack (Stack_t *pstack)
{
    pstack -> top = 0;
}

/**
 * @brief Prints all the elements in the stack.
 * @details Pre-condition: The stack has been created and not empty. \n
 *          Post condition: All the elements of the stack are printed on the screen.
 * @param pstack Address of the created stack.
 * @param pf Address of the display function.
 * @return None.
 */
void TraverseStack ( Stack_t *pstack, void (*pf) (StackEntry element) )
{
    uint8_t i;
    for (i = (pstack -> top); i > 0; i--)
    {
        (*pf) (pstack -> entry [i - 1]);
    }
}

/**
 * @brief Returns the first element that has been pushed onto the stack.
 * @details Pre-condition: The stack has been initialized and not empty. \n
 *          Post condition: The first element is returned.
 * @param pstack Address of the created stack.
 * @return First element in the stack.
 */
StackEntry StackFirstElement (Stack_t *pstack)
{
    return pstack -> entry [0];
}