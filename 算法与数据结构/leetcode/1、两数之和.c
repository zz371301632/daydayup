#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct node
{
    int position;
    int key;
    struct node *next;
} NODE;

typedef struct map
{
    int key;
    int position;
    int hash;
    NODE *next;
} MAP;

#define pro_hash(key) ((abs(key) % arr_size))

void insert_hash(MAP *map, int key, int position, int arr_size);
void insert(MAP *map, int tmp_hash, int i, NODE *node, int key);
int find_hash(MAP *map, int key, int position, int *result_position, int arr_size);

void insert_hash(MAP *map, int key, int position, int arr_size)
{
    int tmp_hash = pro_hash(key);

    if (map[tmp_hash].hash == tmp_hash)
    {
        NODE *node = map[tmp_hash].next;
        if (node == NULL)
        {
            NODE *tmp = malloc(sizeof(NODE));
            tmp->next = NULL;
            tmp->key = key;
            tmp->position = position;
            map[tmp_hash].next = tmp;
        }
        else
        {
            insert(map, tmp_hash, position, node, key);
        }
    }
    else
    {
        map[tmp_hash].key = key;
        map[tmp_hash].position = position;
        map[tmp_hash].hash = tmp_hash;
        map[tmp_hash].next = NULL;
    }
}

void insert(MAP *map, int tmp_hash, int i, NODE *node, int key)
{
    if (node->next == NULL)
    {
        NODE *tmp_node = malloc(sizeof(NODE));
        tmp_node->next = NULL;
        tmp_node->key = key;
        tmp_node->position = i;
        node->next = tmp_node;
    }
    else
    {
        NODE *tmp_node = node->next;
        insert(map, tmp_hash, i, tmp_node, key);
    }
}

int find_hash(MAP *map, int key, int position, int *result_position, int arr_size)
{
    int tmp_hash = pro_hash(key);
    if (tmp_hash == map[tmp_hash].hash && position != map[tmp_hash].position)
    {
        if (key == map[tmp_hash].key)
        {
            *result_position = map[tmp_hash].position;
            return 1;
        }

        NODE *node = map[tmp_hash].next;
        if (node == NULL)
        {
            return 0;
        }

        while (key != node->key)
        {

            node = node->next;

            if (node == NULL)
            {
                return 0;
            }
        }
        *result_position = node->position;
        return 1;
    }
    else
    {
        return 0;
    }
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *result_arr = malloc(sizeof(MAP) * numsSize * 2);
    MAP *map = malloc(sizeof(MAP) * numsSize * 2);
    int right = 0;
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++)
    {
        int now_num = target - nums[i];
        if (find_hash(map, now_num, i, &right, numsSize))
        {
            result_arr[0] = right;
            result_arr[1] = i;
            return result_arr;
        }
        else
        {
            insert_hash(map, nums[i], i, numsSize);
        }
    }

    free(map);
    return 0;
}

int main(){
  int nums[] = {1,5,29,10,8};
  int n_size = sizeof(nums) / sizeof(int);
  int n_result = 0;

  int* result = twoSum(nums,n_size,9,&n_result);

  for (int i = 0; i < n_result; i++)
  {
      printf("result %d\n",nums[result[i]]);
  }
  
  
  return 0;
}

