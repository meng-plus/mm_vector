/**
 * @file mm_vector.h
 * @author 蒙蒙plus (chengmeng_2@outlook.com)
 * @brief C语言版本的vector 尽可能实现所有特性
 * @version 0.1
 * @date 2025-01-19
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef __MM_VECTOR_H_
#define __MM_VECTOR_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
typedef struct MM_VECTOR
{
    uint16_t size;      /*!< 缓存区大小 */
    uint16_t type_size; /*!< 存储类型的大小 */
    uint16_t capacity;  /*!< 当前容量 */
    uint8_t *data;      /*!< 数据开始地址 */
} mm_vector_t;


/* 遍历链表 */
#define mm_vector_for_each(pos, type, head)                                             \
    for (pos = (type *)(head)->data;                                                    \
         (uint8_t *)(pos) < (uint8_t *)(head)->data + (head)->size * (head)->type_size; \
         pos++)


bool mm_vector_init(mm_vector_t *self, uint16_t type_size, void *buff, size_t size);
bool mm_vector_push(mm_vector_t *self, const void *buff, size_t size);
size_t mm_vector_pop(mm_vector_t *self, void *buff, size_t size);
size_t mm_vector_size(const mm_vector_t *self);
size_t mm_vector_capacity(const mm_vector_t *self);
bool mm_vector_resize(mm_vector_t *self, size_t new_size);
void *mm_vector_data(const mm_vector_t *self);
void mm_vector_clear(mm_vector_t *self);
bool mm_vector_is_empty(const mm_vector_t *self);
bool mm_vector_get(const mm_vector_t *self, size_t index, void *buff, size_t size);
bool mm_vector_set(mm_vector_t *self, size_t index, const void *buff, size_t size);
bool mm_vector_insert(mm_vector_t *self, size_t index, const void *buff, size_t size);
bool mm_vector_delete(mm_vector_t *self, size_t index, void *buff, size_t size);
bool mm_vector_swap(mm_vector_t *self, mm_vector_t *new_vector);

#endif //__MM_VECTOR_H_
