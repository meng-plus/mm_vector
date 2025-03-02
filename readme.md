# MM Vector - 一个简单的嵌入式动态数组库

## 简介

MM Vector 是一个轻量级的动态数组库，专为嵌入式系统设计。它提供了一系列基本的数组操作函数，如初始化、插入、删除、获取、设置等，能够帮助开发者在资源受限的环境下高效地管理动态数据。

## 特点

- **轻量级**：代码简洁，内存占用小，适合嵌入式系统使用。
- **通用性**：支持任意类型的数据存储，通过 `type_size` 参数指定元素大小。
- **安全性**：所有操作均进行边界检查，避免内存越界等潜在问题。
- **易用性**：提供了直观的 API，便于集成和使用。

## 使用指南

### 1. 初始化

使用 `mm_vector_init` 函数初始化一个向量。需要指定元素的大小（`type_size`）、缓冲区（`buff`）和缓冲区的总大小（`size`）。

```c
mm_vector_t vec;
uint8_t buffer[256];
mm_vector_init(&vec, sizeof(uint8_t ), buffer, sizeof(buffer));
```

### 2. 添加元素

使用 `mm_vector_push` 函数向向量中添加元素。可以通过该函数一次添加多个元素。

```c
uint8_t  data[] = {1, 2, 3};
mm_vector_push(&vec, data, 3);
```

### 3. 删除元素

使用 `mm_vector_pop` 函数从向量中删除元素。可以通过该函数一次删除多个元素。

```c
uint8_t  popped_data[2];
mm_vector_pop(&vec, popped_data, 2);
```

### 4. 获取元素

使用 `mm_vector_get` 函数从向量中获取指定位置的元素。

```c
uint8_t  value;
mm_vector_get(&vec, 1, &value, 1);
```

### 5. 设置元素

使用 `mm_vector_set` 函数设置向量中指定位置的元素。

```c
uint8_t  new_value = 10;
mm_vector_set(&vec, 1, &new_value, 1);
```

### 6. 插入元素

使用 `mm_vector_insert` 函数在向量中的指定位置插入元素。

```c
uint8_t  insert_data[] = {4, 5};
mm_vector_insert(&vec, 1, insert_data, 2);
```

### 7. 删除元素

使用 `mm_vector_delete` 函数从向量中的指定位置删除元素。

```c
uint8_t  deleted_data[2];
mm_vector_delete(&vec, 1, deleted_data, 2);
```

### 8. 清除向量

使用 `mm_vector_clear` 函数清空向量中的所有元素。

```c
mm_vector_clear(&vec);
```

### 9. 获取向量大小和容量

使用 `mm_vector_size` 和 `mm_vector_capacity` 函数分别获取向量中当前元素的数量和总容量。

```c
size_t size = mm_vector_size(&vec);
size_t capacity = mm_vector_capacity(&vec);
```

### 10. 检查向量是否为空

使用 `mm_vector_is_empty` 函数检查向量是否为空。

```c
bool is_empty = mm_vector_is_empty(&vec);
```

### 11. 获取向量数据指针

使用 `mm_vector_data` 函数获取向量中数据的指针。

```c
void *data_ptr = mm_vector_data(&vec);
```

### 12. 调整向量大小

使用 `mm_vector_resize` 函数调整向量的大小。注意，新的大小不能超过向量的容量。

```c
mm_vector_resize(&vec, 10);
```

### 13. 交换两个向量

使用 `mm_vector_swap` 函数交换两个向量的内容。

```c
mm_vector_t vec2;
mm_vector_swap(&vec, &vec2);
```

## 应用场景

- 实时数据处理
- 传感器数据存储
- 通信协议解析
- 嵌入式系统中的动态存储管理

## 注意事项

- 确保在初始化时提供的缓冲区大小足够容纳所有元素。
- 在进行插入、删除等操作时，注意边界条件，避免内存越界。
- 由于是静态内存分配，向量的大小受限于初始化的缓冲区大小。

## 贡献

欢迎提交问题和改进建议，共同完善 MM Vector 库。

## 许可证

MM Vector 遵循 MIT 许可证，详细信息请参阅 [LICENSE](LICENSE) 文件。

---

希望 MM Vector 能帮助您在嵌入式开发中更高效地管理数据。如果有任何问题或建议，欢迎在 GitHub 上反馈！
