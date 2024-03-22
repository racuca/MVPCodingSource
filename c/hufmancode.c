#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#define MAX_ELEMENT 200 
typedef struct TreeNode { 
    int weight; 
    char ch; 
    struct TreeNode* left; 
    struct TreeNode* right; 
} TreeNode; 
typedef struct { 
    TreeNode* ptree; 
    char ch; 
    int key; 
    char name; 
} element; 
typedef struct { 
    element heap[MAX_ELEMENT]; 
    int heap_size; 
} HeapType; 
// Create heap 
HeapType* create() { 
    return (HeapType*)malloc(sizeof(HeapType)); 
} 
// Initialize heap 
void init(HeapType* h) { 
    h->heap_size = 0; 
} 
// Insert into min heap 
void insert_min_heap(HeapType* h, element item) { 
    int i; 
    i = ++(h->heap_size); 
    // Heapify 
    while ((i != 1) && (item.key < h->heap[i / 2].key)) { 
          h->heap[i] = h->heap[i / 2]; 
          i /= 2; 
   } 
   h->heap[i] = item; 
} 
// Delete from min heap 
element delete_min_heap(HeapType* h) { 
    int parent, child; 
    element item, temp; 
    item = h->heap[1]; 
    temp = h->heap[(h->heap_size)--]; 
    parent = 1; 
    child = 2; 
    while (child <= h->heap_size) { 
          if ((child < h->heap_size) && 
              (h->heap[child].key) > h->heap[child + 1].key) 
              child++; 
          if (temp.key < h->heap[child].key) break; 
          h->heap[parent] = h->heap[child]; 
          parent = child; 
          child *= 2; 
   } 
   h->heap[parent] = temp; 
   return item; 
} 
// Create tree node 
TreeNode* make_tree(TreeNode* left, TreeNode* right) { 
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); 
    node->left = left; 
    node->right = right; 
    return node; 
} 
// Destroy tree 
void destroy_tree(TreeNode* root) { 
    if (root == NULL) return; 
    destroy_tree(root->left); 
    destroy_tree(root->right); 
    free(root); 
} 
// Check if node is leaf 
int is_leaf(TreeNode* root) { 
    return !(root->left) && !(root->right); 
} 
// 허프만 코드 빈도수 출력 
void print_array(int codes[], int n) { 
    for (int i = 0; i < n; i++) 
        printf("%d", codes[i]); 
    printf("\n"); 
} 
// 허프만 코드 문자값 출력 
void print_codes(TreeNode* root, int codes[], int top) { 
    if (root->left) { 
          codes[top] = 1; 
          print_codes(root->left, codes, top + 1); 
   } 
   if (root->right) { 
         codes[top] = 0; 
         print_codes(root->right, codes, top + 1); 
  } 
  if (is_leaf(root)) { 
        printf("%c: ", root->ch); 
        print_array(codes, top); 
  } 
} 
// 전위 순회 방식으로 허프만 트리 노드 출력 
void print_tree_node(TreeNode* root) { 
    if (root) { 
          printf("%c", root->ch); 
          if (root->left || root->right) { 
                printf(" (H-%d ", root->weight); 
                print_tree_node(root->left); 
                printf(" "); 
                print_tree_node(root->right); 
                printf(")"); 
         } 
  } 
} 
// 허프만 트리 생성 
void huffman_tree(int freq[], char ch_list[], int n) { 
    int i; 
    TreeNode* node, * x; 
    HeapType* heap; 
    element e, e1, e2; 
    int codes[100]; 
    int top = 0; 
    heap = create(); 
    init(heap); 
    for (i = 0; i < n; i++) { 
          node = make_tree(NULL, NULL); 
          e.ch = node->ch = ch_list[i]; 
          e.key = node->weight = freq[i]; 
          e.ptree = node; 
          insert_min_heap(heap, e); 
   } 
   for (i = 1; i < n; i++) { 
         e1 = delete_min_heap(heap); 
         e2 = delete_min_heap(heap); 
         x = make_tree(e1.ptree, e2.ptree); 
         e.key = x->weight = e1.key + e2.key; 
         e.ptree = x; 
         e.name = i; 
         printf("%d+%d->%d(H-%d) \n", e1.key, e2.key, e.key, i); 
         insert_min_heap(heap, e); 
  } 
  e = delete_min_heap(heap); 
  print_codes(e.ptree, codes, top); 
  printf("\n***트리 노드 출력:***\n"); 
  print_tree_node(e.ptree); 
  printf("\n"); 
  destroy_tree(e.ptree); 
  free(heap); 
} 
// 중복 문자 검출 함수 
int duplicate(char new_char, int size, char* ch_list) { 
    for (int i = 0; i < size; i++) { 
          if (ch_list[i] == new_char) { 
                printf("문자가 중복되었습니다. 다시입력해주세요\n"); 
                return 1; 
         } 
  } 
  return 0; 
} 
int main(void) { 
    int num; 
    printf("문자 개수?: "); 
    scanf_s("%d", &num); 
    char* ch_list = (char*)malloc(num * sizeof(char)); 
    int* freq = (int*)malloc(num * sizeof(int)); 
    for (int i = 0; i < num; i++) { 
        char new_char = NULL; 
        printf("문자: "); 
        scanf_s(" %c", &new_char); 
        int k = duplicate(new_char, i , ch_list); 
        if (k == 1) { 
              exit(-1); 
        } 
        ch_list[i] = new_char; 
        printf("빈도수: "); 
        scanf_s("%d", &freq[i]); 
    }  
  printf("\n\n"); 
  huffman_tree(freq, ch_list, num); 
  
  free(ch_list); 
  free(freq); 
  return 0; 
} 