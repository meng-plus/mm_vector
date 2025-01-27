#include "mm_vector.h"
#include <stdio.h>

int main()
{
    uint8_t buffer[128];
    mm_vector_t vector;
    mm_vector_init(&vector, sizeof(uint32_t), buffer, sizeof(buffer) / sizeof(uint32_t));

    int data[] = {1, 2, 3, 4, 4, 5, 6, 7, 8};
    mm_vector_push(&vector, data, 8);

    uint32_t *pos;
    mm_vector_for_each(pos, uint32_t, &vector)
    {
        // pos 是当前元素的指针，你可以在这里进行操作
        printf("%d\n", *pos);
    }
    int poppedData[4];
    if (mm_vector_pop(&vector, poppedData, 4) == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            printf("%d ", poppedData[i]);
        }
        printf("\n");
    }


    return 0;
}
