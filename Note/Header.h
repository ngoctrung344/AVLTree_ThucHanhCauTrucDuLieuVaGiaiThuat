#pragma once
#include "iostream"
using namespace std;

struct NODE {
    int key;
    NODE* left;
    NODE* right;
    int height;
};

NODE taoNode(int x);
int nodeHeight(NODE* node);
int getHeight(NODE* root);
NODE leftRotate(NODE* root);
NODE Insert(NODE* root, int x);