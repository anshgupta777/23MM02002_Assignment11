#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char data)
{
    if (top == 99)
    {
        printf("Overflow stack!\n");
        return;
    }

    top++;
    stack[top] = data;
}

char pop()
{
    if (top == -1)
    {
        printf("Empty Stack!\n");
        return '\0';
    }
    
    char data = stack[top];
    
    top--;
    return data;
}

void reverse_string(char *str)
{
    
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        push(str[i]);
    }

    for (int i = 0; i < len; i++)
    {
        str[i] = pop();
    }
}

int main()
{
    char text[100];

    printf("Input a string: ");

    fgets(text, 100, stdin);
    reverse_string(text);

    printf("Reversed string using a stack is: %s\n", text);

    return 0;
}