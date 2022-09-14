#include <stdint.h>

#define StackEntry int
#define MAXSTACK 100

#define True 1
#define False 0

/**
 * @brief Stack structure.
 */
typedef struct stack
{
    StackEntry entry [MAXSTACK];
    uint8_t top;
}Stack_t;

/**
 * @brief Appends an element to the the top of the stack.
 * @warning A check on the status of the stack must be performed before performing the push.
 * @param element Value to be pushed to the stack.
 * @param pstack Address of the created stack.
 * @return None.
 */
void Push (StackEntry element, Stack_t *pstack);

/**
 * @brief Removes the top-most element of the stack.
 * @warning A check on the status of the stack must be performed before performing the pop.
 * @param pstack Address of the created stack.
 * @return The top-most element of the stack.
 */
StackEntry Pop (Stack_t *pstack);

/**
 * @brief Checks if the stack is full.
 * @param pstack Address of the created stack.
 * @return The state of the stack.
 */
uint8_t StackFull (Stack_t *pstack);

/**
 * @brief Checks if the stack is empty.
 * @param pstack Address of the created stack.
 * @return The state of the stack.
 */
uint8_t StackEmpty (Stack_t *pstack);

/**
 * @brief Initializes the values of the stack.
 * @param pstack Address of the created stack.
 * @return None.
 */
void InitStack (Stack_t *pstack);

/**
 * @brief Returns the top-most element of the stack.
 * @param pstack Address of the created stack.
 * @return The top-most element of the stack.
 */
StackEntry StackTop (Stack_t *pstack);

/**
 * @brief Returns the size of the stack.
 * @param pstack Address of the created stack.
 * @return The size of the stack.
 */
uint8_t StackSize (Stack_t *pstack);

/**
 * @brief Clears the stack.
 * @param pstack Address of the created stack.
 * @return None.
 */
void ClearStack (Stack_t *pstack);

/**
 * @brief Prints all the elements in the stack.
 * @warning An address of a display function implemented by the user must be provided to this function.
 * @param pstack Address of the created stack.
 * @param pf Address of the display function.
 * @return None.
 */
void TraverseStack ( Stack_t *pstack, void (*pf) (StackEntry element) );

/**
 * @brief Returns the first element that has been pushed onto the stack.
 * @param pstack Address of the created stack.
 * @return First element in the stack.
 */
StackEntry StackFirstElement (Stack_t *pstack);