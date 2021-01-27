#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericBinTree.h"

#define MAX_LEN 80

Ptr allocate_int() {
    return malloc(sizeof(int));
}

Ptr allocate_str() {
    return malloc(sizeof(char) * MAX_LEN);
}

void destroy_int(Ptr e) {
    free(e);
}

void destroy_str(Ptr e) {
    free(e);
}

void copy_int(Ptr e1, Ptr e2) {
    int* p1 = (int*) e1;
    int* p2 = (int*) e2;
    *p1 = *p2;
}

void copy_str(Ptr e1, Ptr e2) {
    char* p1 = (char*) e1;
    char* p2 = (char*) e2;
    strcpy(p1, p2);
}

int compare_int (Ptr e1, Ptr e2) {
    int* p1 = (int*) e1;
    int* p2 = (int*) e2;
    return *p1 - *p2;
}

int compare_str(Ptr e1, Ptr e2) {
    char* p1 = (char*) e1;
    char* p2 = (char*) e2;
    return strcmp(p1,p2);
}

void print_int(Ptr e) {
    int* p = (int*) e;
    printf("%d ", *p);
}

void print_str(Ptr e) {
    char* p = (char*) e;
    printf("%s ", p);
}

static const BinTreeFunctions int_funcs = {allocate_int, destroy_int, copy_int, compare_int, print_int};
static const BinTreeFunctions str_funcs = {allocate_str, destroy_str, copy_str, compare_str, print_str};

void printTree(BinTree* root) {
    printf("Pre Order: ");
    print_pre_order(root);
    printf("\n");
    printf("In Order: ");
    print_in_order(root);
    printf("\n");
    printf("Post Order: ");
    print_post_order(root);
    printf("\n");
}

void printTreeInOrder(BinTree* root) {
    printf("In Order: ");
    print_in_order(root);
    printf("\n");
}

void main() {
    int int_arr[] = {8,9,2,1,4,3,6,5,7};
    int int_size = sizeof(int_arr) / sizeof(int);
    BinTree* int_root = create_bin_tree(int_funcs);
    for (int i = 0; i < int_size; i++) {
        add_to_bin_tree(int_root, int_arr + i);
    }
    printTree(int_root);
    remove_from_bin_tree(&int_root, int_arr + 4);
    printTreeInOrder(int_root);
    BinTree* int_sub_root = find_in_bin_tree(int_root, int_arr + 2);
    printTreeInOrder(int_sub_root);
    destroy_bin_tree(int_root);

    char* str_arr[] = {"ido","ronit","sari","eyal","alon","omer","ori"};
    int str_size = sizeof(str_arr) / sizeof(char*);
    BinTree* str_root = create_bin_tree_from_arr(str_funcs, (void**) str_arr, str_size);
    printTree(str_root);
    remove_from_bin_tree(&str_root, str_arr[3]);
    printTreeInOrder(str_root);
    BinTree* str_sub_root = find_in_bin_tree(str_root, str_arr[1]);
    printTreeInOrder(str_sub_root);
    destroy_bin_tree(str_root);
}
