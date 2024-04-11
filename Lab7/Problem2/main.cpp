#include <iostream>
#include <stdio.h>
#include <string.h>

#include "Tree.h"



int main() {
 

    Tree<int> intTree(6);

    Node<int>* parentNode = nullptr;
    intTree.add_node(parentNode, 10);
    intTree.add_node(intTree.root, 200);
    intTree.add_node(intTree.root, 30);
    intTree.add_node(intTree.root, 40);


    std::cout << "Children of root node: ";
    intTree.printChildren(intTree.root);
    std::cout << std::endl;


    intTree.sort(intTree.root, compare);


    std::cout << "Sorted children of root node: ";
    intTree.printChildren(intTree.root);
    std::cout << std::endl;


    Node<int>* foundNode = intTree.find(compare, 30);
    if (foundNode != nullptr) {
        std::cout << "Found node with value 30" << std::endl;
    }
    else {
        std::cout << "Node with value 30 not found" << std::endl;
    }

    Node<int>* notFoundNode = intTree.find(compare, 36);

    if (notFoundNode != nullptr) {
        std::cout << "Found node with value 36" << std::endl;
    }
    else {
        std::cout << "Node with value 36 not found" << std::endl;
    }


    intTree.insert(intTree.root, 1, 25);

    std::cout << "Children of root node after insertion: ";
    intTree.printChildren(intTree.root);
    std::cout << std::endl;


    std::cout << "Total number of nodes in the tree: " << intTree.count(nullptr) << std::endl;


    intTree.delete_node(intTree.root);



    Tree<char*> charTree(5);

    charTree.add_node(nullptr, "Hello");
    charTree.add_node(charTree.root, "World");
    charTree.add_node(charTree.root->children[0], "from");
    charTree.add_node(charTree.root->children[0], "the");
    charTree.add_node(charTree.root->children[0], "other");
    charTree.add_node(charTree.root->children[0], "side");


    std::cout << "Children of root node: ";
    charTree.printChildren(nullptr);
    std::cout << std::endl;


    charTree.sort(charTree.root->children[0], compareString);

    std::cout << "Sorted children of root node: ";
    charTree.printChildren(charTree.root);
    std::cout << std::endl;

 
    Node<char*>* foundCharNode = charTree.find(compareString, "from");
    if (foundCharNode != nullptr) {
        std::cout << "Found node with value 'from'" << std::endl;
    }
    else {
        std::cout << "Node with value 'from' not found" << std::endl;
    }

    charTree.insert(charTree.root->children[0], 3, "Amazing");


    std::cout << "Children of root node after insertion: ";
    charTree.printChildren(charTree.root);
    std::cout << std::endl;


    std::cout << "Total number of nodes in the tree: " << charTree.count(nullptr) << std::endl;

    charTree.delete_node(charTree.root);

    return 0;



}