#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define EPSILON 0.001

float g, h, i, j, k, l, m, w, o, q, r, s, t, u, v;
int choice1;
float fun(float x)
{
    if (choice1 = 1)
    {
        return (g * x * x * x + h * x * x + i * x + j);
    }
    else if (choice1 = 2)
    {
        return (k * x * x * x * x + l * x * x * x + m * x * x + w * x + o);
    }
    else
    {
        return (q * x * x * x * x * x + r * x * x * x * x + s * x * x * x + t * x * x + u * x + v);
    }
}

void bisection(float *x, float a, float b, int *itr)
/* this function performs and prints the result of one iteration */
{
    *x = (a + b) / 2;
    ++(*itr);
    printf("Iteration no.%d X = %7.5f\n", *itr, *x);
}

int n;
int flag;

//Helper function
float findSum(int i, float a[][n + 1])
{
    float sum = 0;
    for (int j = 0; j < n; j++)
    {
        if (i != j)
            sum += a[i][j];
    }
    return sum;
}

//checks if Gauss Jacobi Method is applicable and return true if yes otherwise return false
bool isMethodApplicable(float a[][n + 1])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (fabs(a[i][i]) > findSum(i, a))
                break;
            else
                return false;
        }
    }
    return true;
}

//prints the Value of Unknowns
void print(int iteration, float values[n])
{
    printf("Iteration %d ", iteration);
    for (int i = 0; i < n; i++)
    {
        printf("value[%d]=%f ", i + 1, values[i]);
    }
    printf("\n");
}

void findValues(float a[][n + 1], int maxIterations, float values_old[n])
{
    int i, j, k, iteration;
    float sum = 0;
    float values_new[n];
    for (iteration = 1; iteration <= maxIterations; iteration++)
    {
        for (i = 0; i < n; i++)
        {
            sum = 0;
            for (j = 0; j < n; j++)
            {
                if (i != j)
                    sum += a[i][j] * values_old[j];
            }
            values_new[i] = (a[i][n] - sum) / a[i][i];
        }

        for (k = 0; k < n; k++)
        {
            if (fabs(values_old[k] - values_new[k]) < EPSILON)
            {
                continue;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            print(iteration, values_new);
            return;
        }
        flag = 0; //resetting the flag

        print(iteration, values_new); //To print intermediate values of unknowns

        //copy new values of unknowns to old value array
        for (k = 0; k < n; k++)
            values_old[k] = values_new[k];

    } //end of iteration loop

} //end of findValues()
int main()
{
    int choice;
main_menu:
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
    printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
    printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::: Main Menu ::::::::::::::::::::::::::::::::::::::::::::::::::::");
    printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
    printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\n\t\t\t\t\t\tEnter (1) for Bisection Method\n\t\t\t\t\t\tEnter (2) for Jacobis Method\n\t\t\t\t\t\tEnter (3) to end the program\nEnter Your Choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    default:
        printf("\n\t\t\t\t\t\t!!!Invalid Input!!!\n\n");
        goto main_menu;
    case 1:
    {

        system("cls");
        printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
        printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
        printf("\n:::::::::::::::::::::::::::::::::::::::::: Finding root using-Bisection Method ::::::::::::::::::::::::::::::::::::::::");
        printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
        printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        int itr = 0, maxmitr, choice1;
        float x, a, b, allerr, x1;
    input_data:
        printf("\n\t\t\t\t\t   **Select the Degree of Equation**\n\t\t\t\t\t   #Enter (1) for 3rd degree Equation\n\t\t\t\t\t   #Enter (2) for 4th degree Equation\n\t\t\t\t\t   #Enter (3) for 5th degree Equation\n\nEnter Your Choice:");
        scanf("%d", &choice1);
        system("cls");
        printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
        printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
        printf("\n:::::::::::::::::::::::::::::::::::::::::: Finding root using-Bisection Method ::::::::::::::::::::::::::::::::::::::::");
        printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
        printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        switch (choice1)
        {
        case 1:
            printf("\n\t\t\t\t  Enter a equation in the format of:");
            printf("'A*X^3 + B*X^2 + C*X + D'\n\t\t\t\t\t\tEnter the values of A,B,C,D.\n\n\t\t\t\t\t\t\t!!!NOTE THAT!!!\n\n*Enter 0 if you don't have a value for any place.\n*Include '-' Sign before the value if the value is negative.\n\nEquation:");
            scanf("%f%f%f%f", &g, &h, &i, &j);
            break;
        case 2:
            printf("\n\t\t\t      Enter a equation in the format of:");
            printf("A*X^4 + B*X^3 + C*X^2 + D*X + E\n\t\t\t\t\t\tEnter the values of A,B,C,D,E.\n\n\t\t\t\t\t\t\t!!!NOTE THAT!!!\n\n*Enter 0 if you don't have a value for any place.\n*Include '-' Sign before the value if the value is negative.\n\nEquation:");
            scanf("%f%f%f%f%f", &k, &l, &m, &w, &o);
            break;
        case 3:
            printf("\t\t\t\  Enter a equation in the format of:");
            printf("A*X^5 + B*X^4 + C*X^3 + D*X^2 + E*X + F\n\t\t\t\t\t      Enter the values of A,B,C,D,E,F.\n\n\t\t\t\t\t\t\t!!!NOTE THAT!!!\n\n*Enter 0 if you don't have a value for any place.\n*Include '-' Sign before the value if the value is negative.\n\nEquation:");
            scanf("%f%f%f%f%f%f", &q, &r, &s, &t, &u, &v);
            break;
        default:
            printf("\n\t\t\t\t\t\t    !!!Invalid Input!!!\n");
            goto input_data;
        }
        printf("\nEnter the values of a, b between which root lies:");
        scanf("%f %f", &a, &b);
        printf("\nAllowed error:");
        scanf("%f", &allerr);
        printf("\nMaximum iterations:");
        scanf("%d", &maxmitr);
        bisection(&x, a, b, &itr);
        do
        {
            if (fun(a) * fun(x) < 0)
                b = x;
            else
                a = x;
            bisection(&x1, a, b, &itr);
            if (fabs(x1 - x) < allerr)
            {
                printf("After %d iterations, root = %6.4f\n\n", itr, x1);
                goto main_menu;
                return 0;
            }
            x = x1;
        } while (itr < maxmitr);
        printf("The solution does not converge or iterations are not sufficient.\n\n");
        goto main_menu;
        return 1;
    }
    case 2:
    {
        system("cls");
        int i, j, k, x, y, maxIterations;
        float ratio;
        printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
        printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
        printf("\n::::::::::::::::::::::::::::::::::::::::::::: Root finding using Jacobi Method :::::::::::::::::::::::::::::::::::::::::");
        printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
        printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("\nEnter no. of Unknowns:");
        scanf("%d", &n);
        printf("Enter no. of iterations:");
        scanf("%d", &maxIterations);
        float a[n][n + 1];
        float values[n];

        printf("Enter the Augmented Matrix:\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n + 1; j++)
                scanf("%f", &a[i][j]);
        }

        if (!isMethodApplicable(a))
        {
            printf("Gauss Jacobi Method can't be applied\n");
            return 0;
        }
        else
        {
            printf("Gauss Jacobi Method is applicable\n");
        }
        for (int i = 0; i < n; i++)
            values[i] = 0;
        findValues(a, maxIterations, values);
        printf("\n");
        goto main_menu;
        return 0;
    }
    case 3:
    {
        printf("\n\t\t\t\t\t\t\tThank You\n");
    }
    }
}