#include "mm_vector.h"
#include <stdio.h>

int main()
{
    uint8_t buffer[128];
    mm_vector_t vector;
    mm_vector_init(&vector, buffer, sizeof(buffer));

    int data[] = {1, 2, 3, 4};
    MM_VEC_PUSH(&vector, int, data, 4);

    int poppedData[4];
    if (mm_vector_pop(&vector, (uint8_t *)poppedData, sizeof(poppedData)) == sizeof(poppedData))
    {
        for (int i = 0; i < 4; i++)
        {
            printf("%d ", poppedData[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Failed to pop data\n");
    }

    return 0;
}
