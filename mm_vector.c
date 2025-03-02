#include "mm_vector.h"
#include <string.h>

bool mm_vector_init(mm_vector_t *self, uint16_t type_size, void *buff, size_t size)
{
    if (!self || !buff || type_size == 0 || size == 0)
    {
        return false;
    }
    self->size      = 0;
    self->type_size = type_size;
    self->capacity  = size;
    self->data      = buff;
    return true;
}

bool mm_vector_push(mm_vector_t *self, const void *buff, size_t size)
{
    if (!self || !buff || size == 0)
    {
        return false;
    }
    if (self->size + size > self->capacity)
    {
        return false; // No enough space
    }
    memcpy(self->data + self->size, buff, size * self->type_size);
    self->size += size;
    return true;
}

size_t mm_vector_pop(mm_vector_t *self, void *buff, size_t size)
{
    if (!self || !buff || size == 0 || size > self->size)
    {
        return 0;
    }
    memcpy(buff, self->data + (self->size - size) * self->type_size, size * self->type_size);
    self->size -= size;
    return size;
}

size_t mm_vector_size(const mm_vector_t *self)
{
    return self ? self->size : 0;
}

size_t mm_vector_capacity(const mm_vector_t *self)
{
    return self ? self->capacity : 0;
}

void mm_vector_clear(mm_vector_t *self)
{
    if (self)
    {
        self->size = 0;
    }
}

bool mm_vector_is_empty(const mm_vector_t *self)
{
    return self ? self->size == 0 : true;
}

bool mm_vector_get(const mm_vector_t *self, size_t index, void *buff, size_t size)
{
    if (!self || !buff || index >= self->size || size > self->size - index)
    {
        return false;
    }
    memcpy(buff, self->data + index, size * self->type_size);
    return true;
}

bool mm_vector_set(mm_vector_t *self, size_t index, const void *buff, size_t size)
{
    if (!self || !buff || index >= self->size || size > self->size - index)
    {
        return false;
    }
    memcpy(self->data + index, buff, size * self->type_size);
    return true;
}

bool mm_vector_insert(mm_vector_t *self, size_t index, const void *buff, size_t size)
{
    if (!self || !buff || index > self->size || size + self->size > self->capacity)
    {
        return false;
    }
    memmove(self->data + (index + size) * self->type_size, self->data + index * self->type_size, (self->size - index) * self->type_size);
    memcpy(self->data + index * self->type_size, buff, size * self->type_size);
    self->size += size;
    return true;
}

bool mm_vector_delete(mm_vector_t *self, size_t index, void *buff, size_t size)
{
    if (!self || !buff || index >= self->size || size > self->size - index)
    {
        return false;
    }
    memcpy(buff, self->data + index * self->type_size, size * self->type_size);
    memmove(self->data + index * self->type_size, self->data + (index + size) * self->type_size, (self->size - index - size) * self->type_size);
    self->size -= size;
    return true;
}
void *mm_vector_data(const mm_vector_t *self)
{
    return self ? self->data : NULL;
}

bool mm_vector_resize(mm_vector_t *self, size_t new_size)
{
    if (!self || new_size > self->capacity)
    {
        return false;
    }
    self->size = new_size;
    return true;
}
bool mm_vector_swap(mm_vector_t *self, mm_vector_t *new_vector)
{
    if (!self || !new_vector)
    {
        return false;
    }
    mm_vector_t tmp;
    tmp         = *self;
    *self       = *new_vector;
    *new_vector = tmp;
    return true;
}
