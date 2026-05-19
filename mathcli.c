#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_user_number()
{   
    int myNum;
    char extra;
    while (1)
    {
        printf("Enter integer: ");

        if (scanf(" %d%c", &myNum, &extra) == 2 && (extra == '\n' || extra == ' '))
            break;
        
        printf("Invalid input\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
    return myNum;
}

char get_user_operand()
{
    char ch;
    printf("Enter an operand(+,-,*,/): ");
    scanf(" %c", &ch); // Leading whitespace to skip newlines/whitespace
    return ch;
}

int main() 
{
    printf("Welcome!\n");
    while(1)
    {
        int num = get_user_number();
        char op = get_user_operand();
        int num2 = get_user_number();
        int res;
        switch(op)
        {
            case '+':
                res = num + num2;
                break;
            case '-':
                res = num - num2;
                break;
            case '*':
                res = num * num2;
                break;
            case '/':
                if (num2 == 0)
                {
                    printf("Division by 0 is not permissable\n");
                    continue;
                }
                res = num / num2;
                break;
            default:
                printf("Invalid operator\n");
                continue;
        }
        printf("Result: %d\n", res);
    }
        

    // Return 0 if everything executed as planned
    return 0;
}