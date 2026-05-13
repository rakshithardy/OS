#include <stdio.h>

int main()
{
    int n, m, i, j, k;

    printf("Enter number of processes -- ");
    scanf("%d", &n);

    printf("Enter number of resource types -- ");
    scanf("%d", &m);

    int allocation[n][m], request[n][m];
    int available[m];

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input Request Matrix
    printf("\nEnter Request Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }

    // Input Available Resources
    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }

    int work[m], finish[n];

    // Initialize Work = Available
    for(i = 0; i < m; i++)
    {
        work[i] = available[i];
    }

    // Initialize Finish
    for(i = 0; i < n; i++)
    {
        int flag = 0;

        for(j = 0; j < m; j++)
        {
            if(allocation[i][j] != 0)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 1)
            finish[i] = 0;
        else
            finish[i] = 1;
    }

    // Detection Algorithm
    int found;

    do
    {
        found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(j = 0; j < m; j++)
                {
                    if(request[i][j] > work[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if(possible)
                {
                    printf("P%d is executed\n", i);

                    for(k = 0; k < m; k++)
                    {
                        work[k] += allocation[i][k];
                    }

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

    } while(found);

    // Check Deadlock
    int deadlock = 0;

    printf("\nDeadlocked Processes are: ");

    for(i = 0; i < n; i++)
    {
        if(finish[i] == 0)
        {
            printf("P%d ", i);
            deadlock = 1;
        }
    }

    if(deadlock == 0)
    {
        printf("None");
    }

    printf("\n");

    return 0;
}
