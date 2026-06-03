#include <stdio.h>

void printFrames(int frames[], int f)
{
    for (int i = 0; i < f; i++)
    {
        if (frames[i] == -1)
            printf("- ");
        else
            printf("%d ", frames[i]);
    }
    printf("\n");
}

int search(int frames[], int f, int key)
{
    for (int i = 0; i < f; i++)
    {
        if (frames[i] == key)
            return 1;
    }
    return 0;
}

void fifo(int pages[], int n, int f)
{
    int frames[f], index = 0, faults = 0;

    for (int i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nFIFO Page Replacement Process:\n");

    for (int i = 0; i < n; i++)
    {
        if (!search(frames, f, pages[i]))
        {
            frames[index] = pages[i];
            index = (index + 1) % f;
            faults++;

            printf("PF No. %d: ", faults);
            printFrames(frames, f);
        }
    }

    printf("FIFO Page Faults: %d\n", faults);
}

void lru(int pages[], int n, int f)
{
    int frames[f], time[f], faults = 0, count = 0;

    for (int i = 0; i < f; i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nLRU Page Replacement Process:\n");

    for (int i = 0; i < n; i++)
    {
        int found = 0;

        for (int j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                count++;
                time[j] = count;
                found = 1;
                break;
            }
        }

        if (!found)
        {
            int pos = 0;

            for (int j = 1; j < f; j++)
            {
                if (time[j] < time[pos])
                    pos = j;
            }

            frames[pos] = pages[i];
            count++;
            time[pos] = count;
            faults++;

            printf("PF No. %d: ", faults);
            printFrames(frames, f);
        }
    }

    printf("LRU Page Faults: %d\n", faults);
}

int predict(int pages[], int frames[], int n, int index, int f)
{
    int farthest = index, pos = -1;

    for (int i = 0; i < f; i++)
    {
        int j;

        for (j = index; j < n; j++)
        {
            if (frames[i] == pages[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }

        if (j == n)
            return i;
    }

    return (pos == -1) ? 0 : pos;
}

void optimal(int pages[], int n, int f)
{
    int frames[f], faults = 0, filled = 0;

    for (int i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nOptimal Page Replacement Process:\n");

    for (int i = 0; i < n; i++)
    {
        if (!search(frames, f, pages[i]))
        {
            if (filled < f)
            {
                frames[filled++] = pages[i];
            }
            else
            {
                int pos = predict(pages, frames, n, i + 1, f);
                frames[pos] = pages[i];
            }

            faults++;

            printf("PF No. %d: ", faults);
            printFrames(frames, f);
        }
    }

    printf("Optimal Page Faults: %d\n", faults);
}

int main()
{
    int f, n;

    printf("Enter the number of Frames: ");
    scanf("%d", &f);

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter the reference string: ");

    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    fifo(pages, n, f);
    lru(pages, n, f);
    optimal(pages, n, f);

    return 0;
}
