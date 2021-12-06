//
// Created by god on 2021/12/5.
//

#ifndef HUFFMAN_EXAMPLE_HUFFMAN_H
#define HUFFMAN_EXAMPLE_HUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10000
typedef struct Node {
    char value;                 //节点值
    int weight;                 //权重
    int lchild, rchild, parent; //顺序存储会更方便
} HTreeNode;
typedef struct {
    char bit[8]; //存放当前节点编码
    int start;
} HCode;
typedef struct {
    char huffman_code[3000];
    long int code_length;
}Huffmancode;



Huffmancode *huffman_encode_from_string(char *string);
Huffmancode *huffman_encode_from_file(FILE *ip);
int generate_huffmanNode(char *string, HTreeNode *HuffmanNode[]);
void generate_huffmanTree(HTreeNode* HuffmanNode[],int n);
void generate_huffmanCode(HTreeNode* HuffmanNode[],HCode *HuffmanCode[],int node_num);
#endif //HUFFMAN_EXAMPLE_HUFFMAN_H