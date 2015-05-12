//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab5/lab5.h
///
/// @author Alec Wallace [awall006@ucr.edu]
/// @student id 861102503
/// @date 5 11 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 023
/// BST Tree with functions to find and display the smallest
/// Vector cover, find sum paths, and find vertical sums.
//  ================== END ASSESSMENT HEADER ===============
// -*- bst.h -*-
#ifndef BST_H
#define BST_H
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>

using namespace std;
#define nil 0

// #define Value int // restore for testing.
template <typename Value>
class BST{
    class Node{ // binary tree node
        public:
        Value value;
        Node* left;
        Node* right;
        bool selected;
        Node(const Value v = Value())
            : value(v), left(nil), right(nil), selected(false){}
        Value& content(){return value;}
        bool isInternal(){return left != nil && right != nil;}
        bool isExternal(){return left != nil || right != nil;}
        bool isLeaf(){return left == nil && right == nil;}
        int height(){
            // returns the height of the subtree rooted at this node
            if(left == 0 && right == 0){
                return 1;
            }
            else if(left == 0){
                return right->height() + 1;
            }
            else if(right == 0){
                return left->height() + 1;
            }
            else{
                int L = left->height();
                int R = right->height();
                if(L > R){
                    return L + 1;
                }
                return R + 1;
            }
            return 0;
        }
        int size(){
            // returns the size of the subtree rooted at this node,
            if(left == 0 && right == 0){
                return 0;
            }
            else if(left == 0){
                return right->size() + 1;
            }
            else if(right == 0){
                return left->size() + 1;
            }
            return left->size() + right->size() + 2;
        }
    }; // Node
    // const Node* nil; // later nil will point to a sentinel node.
    int count;
    Node* root;
    int VertexCoverSize;

    
    public:
    //recursive function to find the smallest vector cover
    int mCover(Node* r)
    {
        // The size of minimum vertex cover is zero if tree is empty or there
        // is only one node
        if (r == NULL){
            return 0;
        }
        if (r->left == NULL && r->right == NULL){
            return 0;
        }
     
        // Calculate size of vertex cover when r is part of it
        int size_incl = 1 + mCover(r->left) + mCover(r->right);
     
        // Calculate size of vertex cover when r left and right are not part of it
        int size_excl = 0;
        if (r->left){ size_excl += 1 + mCover(r->left->left) + mCover(r->left->right); }
        if (r->right){ size_excl += 1 + mCover(r->right->left) + mCover(r->right->right); }
        
        // Return the minimum of two sizes
        if(size_incl <= size_excl){
            r->selected = true;
            return size_incl;
        }
        
        return size_excl;
    }
    //function to find the smallest vector cover
    void minCover(){
        VertexCoverSize = mCover(root->right) + mCover(root->left);
    }
    
    //recursive function for displaying the smallest vector cover
    void displayMCover(Node* r){
        if (r->left!=0){
            displayMCover(r->left);
        }
        if (r->selected){
            cout << r->value << " ";
        }
        if (r->right!=0){
            displayMCover(r->right);
        }
    }
    
    //displayes the smallest vector cover
    void displayMinCover(){
        minCover();
        displayMCover(root);
        cout << endl << VertexCoverSize;
    }
    
    // recursive function finds the sum path from node n up towards root, 
    // prints 0 if path doesn't exist
    int findSumPathR(Node* n, Node* r, int sum, int buffer[]){
        if(r == NULL){
            return -1;
        }
        if(r->value == n->value){
            buffer[0] = r->value;
            return 0;
        }
        if(n->value < r->value){
            if(r->left == 0){
                return -1;
            }
            int temp = findSumPathR(n,r->left,sum,buffer);
            if(temp == -1){
                return -1;
            }
            temp ++;
            buffer[temp] = r->value;
            return temp;
        }
        else{
            if(r->right == 0){
                return -1;
            }
            int temp = findSumPathR(n,r->right,sum,buffer);
            if(temp == -1){
                return -1;
            }
            temp++;
            buffer[temp] = r->value;
            return temp;
        }
        return -1;
    }
    
    // finds the sum path from node n up towards root, prints 0 if path doesn't exist
    void findSumPath(Node* n, int sum, int buffer[]){
        int temp = findSumPathR(n, root, sum, buffer);
        int count = 0;
        while(sum != 0 && count <= temp){
            sum -= buffer[count];
            count++;
            //check to make sure it is a sum
            if(sum < 0){
                temp = -1;
                break;
            }
        }
        //check to make sure it is a sum
        if(sum !=0){
            temp = -1;
        }
        //check to make sure it is a sum
        if(temp == -1){
            cout << "0";
        }
        //print
        else{
            for(int i = 0; i < count; i++){
                cout << buffer[i] << " ";
            }
        }
    }
    //test because the Node* cannot be declared in main
    void FINDSUMPATHTEST(int T){
        Node* N = root;
        int Buffer[10];
        while(N->left != 0){
            N = N->left;
        }
        findSumPath(N,T,Buffer);
    }
    
    void vertSumN(Node* node, int hd, map<int, int>& m){
        int prevSum;
        if (node == NULL)
            return;
        if(node->left != 0){
            vertSumN(node->left, hd - 1, m);
        }
          
        // Update vertical sum for hd of this node
        map<int,int>::iterator i = m.find(hd);
        if(i == m.end()){
            prevSum = node->value;
            m.insert(pair<int,int>(hd, prevSum));
            // cout << hd << " " << i->second << " " << i->first << endl;
        }
        else{
            prevSum = i->second;
            i->second = prevSum + (node->value);
            // cout << hd << " " << i->second << " " << i->first << endl;
        }
        
        
         
        // Store the values in m for right subtree
        if(node->right != 0){
            vertSumN(node->right, hd + 1, m);
        }
        
    }
    
    void vertSum(Node* node, int hd, map<int, int>& m){
        vertSumN(node, hd, m);
        for(map<int,int>::iterator it = m.begin(); it != m.end(); ++it){
            cout << it->second << " ";
        }
    }
    
    //cant construct a node in main
    void VERSUMTEST(){
        map<int,int> M;
        vertSum(root, 0, M);
    }
    
    
    int size(){
        // size of the overall tree.
        return root->size();
    }
    bool empty(){return size() == 0;}
    void print_node(const Node* n){
        // Print the node’s value.
        cout << n->value;
    }
    bool searchHelper(Value x, Node* R){
        if(R->value == x){
            return true;
        }
        else if(R->left == 0 && R->right == 0){
            return false;
        }
        else if(R->left == 0){
            return searchHelper(x, R->right);
        }
        else if(R->right == 0){
            return searchHelper(x, R->left);
        }
        bool bL = searchHelper(x, R->left);
        bool bR = searchHelper(x, R->right);
        if(bL){
            return bL;
        }
        if(bR){
            return bR;
        }
        return false;
        
    }
    bool search(Value x){
        // search for a Value in the BST and return true iff it was found.
        return searchHelper(x, root);
    }
    void preorderHelper(Node* R)const{
        cout << R->value << endl;
        if(R->left != 0){
            preorderHelper(R->left);
        }
        if(R->right != 0){
            preorderHelper(R->right);
        }
    }
    void preorder()const{
        // Traverse and print the tree one Value per line in preorder.
        preorderHelper(root);
    }
    void postorderHelper(Node* R)const{
        if(R->left != 0){
            postorderHelper(R->left);
        }
        if(R->right != 0){
            postorderHelper(R->right);
        }
        cout << R->value << endl;
    }
    void postorder()const{
        // Traverse and print the tree one Value per line in postorder.
        postorderHelper(root);
    }
    void inorderHelper(Node* R)const{
        if(R->left != 0){
            inorderHelper(R->left);
        }
        cout << R->value << endl;
        if(R->right != 0){
            inorderHelper(R->right);
        }
    }
    void inorder()const{
        // Traverse and print the tree one Value per line in inorder.
        inorderHelper(root);
    }
    int at(int n, int num, Node* R, Value* V){
        if(R->left != 0){
            num = at(n, num, R->left, V) + 1;
        }
        if(num == n){
            *V = R->value;
        }
        if(R->right != 0){
            num = at(n, num+1, R->right, V);
        }
        return num;
    }
    Value& operator[](int n){
        // returns reference to the value field of the n-th Node.
        Value* V = new Value;
        *V = 0;
        if(n < 0){
            return *V;
        }
        if(n > size()){
            return *V;
        }
        at(n, 0, root, V);
        return *V;
    }
    BST() : count(0), root(nil){}
    void insert(Value X) {root = insert(X, root );}
    Node* insert(Value X, Node* T){
        // The normal binary-tree insertion procedure ...
        if(T == nil){
            T = new Node(X); // the only place that T gets updated.
        }
        else if(X < T->value){
            T->left = insert(X, T->left);
        }
        else if(X > T->value){
            T->right = insert(X, T->right);
        }
        else{
            T->value = X;
        }
        // later, rebalancing code will be installed here
        return T;
    }
    void remove(Value X){root = remove(X, root);}
    Node* remove(Value X, Node*& T){
        // The normal binary-tree removal procedure ...
        // Weiss’s code is faster but way more intricate.
        if(T != nil){
            if(X > T->value){
                T->right = remove(X, T->right);
            }
            else if(X < T->value){
                T->left = remove(X, T->left);
            }
            else{
                // X == T->value
                if(T->right != nil){
                    Node* x = T->right;
                    while(x->left != nil) x = x->left;
                    T->value = x->value; // successor’s value
                    T->right = remove(T->value, T->right);
                }
                else if(T->left != nil){
                    Node* x = T->left;
                    while (x->right != nil) x = x->right;
                    T->value = x->value; // predecessor’s value
                    T->left = remove(T->value, T->left);
                }
                else{ // *T is external
                    delete T;
                    T = nil; // the only updating of T
                }
            }
        }
        // later, rebalancing code will be installed here
        return T;
    }
    void okay(){okay(root);}
    void okay(Node* T){
        // diagnostic code can be installed here
        return;
    }
};// BST
#endif