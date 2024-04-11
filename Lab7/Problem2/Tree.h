#pragma once
#include <iostream>
template <typename T>
struct Node
{
    T value;
    Node** children;
    Node* parent;
    unsigned int nrChildren;
};

template <typename T>
int compare(T firstValue, T secondValue) {
    if (firstValue < secondValue) {
        return -1;
    }
    else
    if (firstValue > secondValue) {
        return 1;
    }
    else
    {
        return 0;
    }
}
template <typename T>
int compareString(T str1, T str2) {
    return strcmp(str1, str2);
}

template <typename T>
int compare2(T firstValue, T secondValue) {
    if (firstValue > secondValue) {
        return -1;
    }
    else
    if (firstValue < secondValue) {
        return 1;
    }
    else
    {
        return 0;
    }
}


template <class T>
class Tree
{
public:
    Node<T> *root;
    unsigned int maxNrChildrenPerNode;
public:
    Tree(unsigned int nrChildren) {
        this->maxNrChildrenPerNode = nrChildren;
        root = nullptr;
    }
    void add_node(Node<T>* parent, T value) {

        if (parent == nullptr) {
            root = new Node<T>;
            root->parent = nullptr;
            root->value = value;
            root->nrChildren = 0;
            root->children = new Node<T> *[maxNrChildrenPerNode]{};

        }
        else {
            parent->children[parent->nrChildren] = new Node<T>;
            parent->children[parent->nrChildren]->value = value;
            parent->children[parent->nrChildren]->parent = parent;
            parent->children[parent->nrChildren]->nrChildren = 0;
            parent->children[parent->nrChildren]->children = new Node<T> *[maxNrChildrenPerNode]{};
            parent->nrChildren++;

        }
    }

    void printChildren(Node<T>* parent) {
        unsigned int i;
        if (parent == nullptr) {
            parent = root;
        }
        for (i = 0; i < parent->nrChildren; i++) {
            std::cout << parent->children[i]->value << " ";
            if (parent->children[i]->nrChildren != 0) {
                printChildren(parent->children[i]);
            }
        }
    }

    void sort(Node<T>* parent, int (*compara)(T, T))
    {
        unsigned int i, j;
        if (compara == nullptr) 
        {
            for (i = 0; i < parent->nrChildren - 1; i++) {
                for (j = i + 1; j < parent->nrChildren; j++) {
                    if (parent->children[i]->value < parent->children[j]->value) {
                        T aux;
                        aux = parent->children[i]->value;
                        parent->children[i]->value = parent->children[j]->value;
                        parent->children[j]->value = aux;
                    }
                }
            }
        }
        else 
        {
            for (i = 0; i < parent->nrChildren - 1; i++) {
                for (j = i + 1; j < parent->nrChildren; j++) {
                    if (compara(parent->children[i]->value, parent->children[j]->value) > 0) {
                        T aux;
                        aux = parent->children[i]->value;
                        parent->children[i]->value = parent->children[j]->value;
                        parent->children[j]->value = aux;
                    }
                }
            }
        }
    }

    //get_node method(returns a reference / method to a node).The method receives a pointer / reference to
    //its parent(if the reference is nullptr, than the root node will be returned).
    Node<T>& get_node(Node<T>* leaf) {
        if (leaf == nullptr) {
            return *(root);
        }
        else {
            return *(leaf);
        }
    }
    //delete_node method (deletes a node and all its children)
    void delete_node(Node<T>* leaf) {
        if (leaf == nullptr) {
            return;
        }
            

        Node<T>* parent = leaf->parent == nullptr ? nullptr : leaf->parent;
        unsigned int leafIndex = 0;

        if (parent != nullptr) {
            for (unsigned int i = 0; i < parent->nrChildren; ++i) {
                if (parent->children[i] == leaf) {
                    leafIndex = i;
                    break;
                }
            }

            for (unsigned int i = leafIndex; i < parent->nrChildren - 1; ++i) {
                parent->children[i] = parent->children[i + 1];
            }

            parent->nrChildren--;
        }

        for (unsigned int i = 0; i < leaf->nrChildren; ++i) {
            delete_node(leaf->children[i]);
        }

        delete[] leaf->children;
        delete leaf;
    }
    //find method-- > recursively search all nodes for a parameter.The method will receive a pointer to a function that will compare the parameter
    //received to the value T from each node.Thre method returns the first occurence.
    Node<T>* find(Node<T>* currentNode, int (*compare)(T, T), const T& parameter) {

        if (currentNode == nullptr)
            return nullptr;

        if (compare(currentNode->value, parameter) == 0)
            return currentNode;
  
        for (unsigned int i = 0; i < currentNode->nrChildren; ++i) {
            Node<T>* result = find(currentNode->children[i], compare, parameter);
            
            if (result != nullptr)
                return result;
        }
        
        return nullptr;
    }

    Node<T>* find(int (*compare)(T, T), const T& parameter) {

        return find(root, compare, parameter);

    }
    //insert method (insert an new node in a tree at a specific index, given its parent note.)
    void insert(Node<T>* parent, unsigned int index, T value) {
        
        if (parent == nullptr) {
            return;
        }
        if (index > parent->nrChildren) {
            index = parent->nrChildren;
        }

        Node<T>* newNode = new Node<T>;
        newNode->value = value;
        newNode->nrChildren = 0;
        newNode->children = new Node<T>*[maxNrChildrenPerNode];
        newNode->parent = parent;

        Node<T>** newChildren = new Node<T>*[parent->nrChildren + 1];
        for (unsigned int i = 0; i < index; ++i) {
            newChildren[i] = parent->children[i];
        }
        newChildren[index] = newNode;

        for (unsigned int i = index; i < parent->nrChildren; ++i) {
            newChildren[i + 1] = parent->children[i];
        }
        delete[] parent->children;
        parent->children = newChildren;

        parent->nrChildren++;

    }
    //count method(returns how many children a node has).This method walks recursively through all children.If call with nullptr
    //, it returns the count of all children from the root of the tree
    unsigned int count(Node<T>* parent) {
        if (parent == nullptr) {
            parent = root;
        }
        unsigned int totalCount = parent->nrChildren;
        for (unsigned int i = 0; i < parent->nrChildren; ++i) {
            totalCount += count(parent->children[i]);
        }
        return totalCount;
    }
};

template <>
class Tree<char*>
{
public:
    Node<char*>* root;
    unsigned int maxNrChildrenPerNode;
public:
    Tree(unsigned int nrChildren) {
        this->maxNrChildrenPerNode = nrChildren;
        root = nullptr;
    }
    void add_node(Node<char*>* parent, const char* value) {

        Node<char*>* newparent = new Node<char*>;
        newparent = parent;
        if (parent == nullptr) {
            root = new Node<char*>;
            root->value = new char[100];
            strcpy(root->value, value);
            root->nrChildren = 0;
            root->children = new Node<char*> *[maxNrChildrenPerNode] {};
            root->parent = nullptr;
        }
        else {

            Node<char*>* newNode = new Node<char*>;
            newNode->value = new char[100];
            strcpy(newNode->value, value);
            newNode->nrChildren = 0;
            newNode->children = new Node<char*>*[maxNrChildrenPerNode];
            newNode->parent = newparent;

            parent->children[parent->nrChildren] = newNode;
            parent->nrChildren++;

        }
    }

    void printChildren(Node<char*>* parent) {
        unsigned int i;
        if (parent == nullptr) {
            parent = root;
        }
        for (i = 0; i < parent->nrChildren; i++) {
            std::cout << parent->children[i]->value << " ";
            if (parent->children[i]->nrChildren != 0) {
                printChildren(parent->children[i]);
            }
        }
    }

    void sort(Node<char*>* parent, int (*compara)(char*, char*))
    {
        unsigned int i, j;
        if (compara == nullptr)
        {
            for (i = 0; i < parent->nrChildren - 1; i++) {
                for (j = i + 1; j < parent->nrChildren; j++) {
                    if (parent->children[i]->value < parent->children[j]->value) {
                        char* aux;
                        aux = parent->children[i]->value;
                        parent->children[i]->value = parent->children[j]->value;
                        parent->children[j]->value = aux;
                    }
                }
            }
        }
        else
        {
            for (i = 0; i < parent->nrChildren - 1; i++) {
                for (j = i + 1; j < parent->nrChildren; j++) {
                    if (compara(parent->children[i]->value, parent->children[j]->value) > 0) {
                        char* aux;
                        aux = parent->children[i]->value;
                        parent->children[i]->value = parent->children[j]->value;
                        parent->children[j]->value = aux;
                    }
                }
            }
        }
    }

    Node<char*>& get_node(Node<char*>* leaf) {
        if (leaf == nullptr) {
            return *(this->root);
        }
        else {
            return *(leaf);
        }
    }

    void delete_node(Node<char*>* leaf) {
        if (leaf == nullptr)
            return;


        Node<char*>* parent = leaf->parent;
        unsigned int leafIndex = 0;

        if (parent != nullptr) {

            for (unsigned int i = 0; i < parent->nrChildren; ++i) {
                if (parent->children[i] == leaf) {
                    leafIndex = i;
                    break;
                }
            }

            for (unsigned int i = leafIndex; i < parent->nrChildren - 1; ++i) {
                parent->children[i] = parent->children[i + 1];
            }


            parent->nrChildren--;
        }

        for (unsigned int i = 0; i < leaf->nrChildren; ++i) {
            delete_node(leaf->children[i]);
        }

        delete[] leaf->children;

        delete[] leaf->value;

        delete leaf;
    }

    Node<char*>* find(Node<char*>* currentNode, int (*compare)(char*, char*), const char* value) {

        if (currentNode == nullptr)
            return nullptr;

        if (compare(currentNode->value, (char*)value) == 0)
            return currentNode;

        for (unsigned int i = 0; i < currentNode->nrChildren; ++i) {
            Node<char*>* result = find(currentNode->children[i], compare, value);

            if (result != nullptr)
                return result;
        }

        return nullptr;
    }

    Node<char*>* find(int (*compare)(char*, char*), const char* value) {

        return find(root, compare, value);

    }

    void insert(Node<char*>* parent, unsigned int index, const char* value) {

        if (parent == nullptr) {
            return;
        }
        if (index < 0) {
            return;
        }
        if (index > parent->nrChildren) {
            index = parent->nrChildren;
        }

        Node<char*>* newNode = new Node<char*>;
        newNode->value = new char[strlen(value) + 1];
        strcpy(newNode->value, value);
        newNode->nrChildren = 0;
        newNode->children = new Node<char*>*[maxNrChildrenPerNode];
        newNode->parent = parent;

        Node<char*>** newChildren = new Node<char*>*[parent->nrChildren + 1];

        for (unsigned int i = 0; i < index; ++i) {
            newChildren[i] = parent->children[i];
        }


        newChildren[index] = newNode;


        for (unsigned int i = index; i < parent->nrChildren; ++i) {
            newChildren[i + 1] = parent->children[i];
        }

        delete[] parent->children;


        parent->children = newChildren;

        parent->nrChildren++;

    }
    unsigned int count(Node<char*>* parent) {
        if (parent == nullptr) {
            parent = root;
        }
        unsigned int totalCount = parent->nrChildren;
        for (unsigned int i = 0; i < parent->nrChildren; ++i) {
            totalCount += count(parent->children[i]);
        }
        return totalCount;
    }



};



