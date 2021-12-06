
#ifndef ORDERED_MAP_H
#define ORDERED_MAP_H


#include <iostream>
#include <string>
#include <vector>

using namespace std;



template<typename T>
class mapADT{
private:
    vector<T *> tree;


    int inOrderSearchForDelete(int &toReturn, int index){
        if(tree[index*2+2] == nullptr){
            if(tree[index*2+1] != nullptr){
                toReturn = inOrderSearchForDelete(toReturn, index * 2 + 1);
            }
            return index;
        }else{
            toReturn = inOrderSearchForDelete(toReturn, index * 2 + 2);
        }

        return toReturn;

    }




    int root(T &key) {
        if (tree[0] == nullptr){
            tree[0] = &key;
            return 1;
        }
        return 0;
    }

    int set_left(T &key, int parent) {
        if(tree[(parent * 2) + 1] == nullptr){
            tree[(parent * 2) + 1] = &key;
            return 1;
        }
        return 0;
    }

    int set_right(T &key, int parent) {
        if(tree[(parent * 2) + 2] == nullptr){

            tree[(parent * 2) + 2] = &key;
            return 1;
        }
        return 0;

    }

public:

    mapADT(){
        tree.resize(1);
    }

    ~mapADT(){
        for(int i = tree.capacity() - 1; i >= 0; i--){
            if(tree[i] != nullptr)
                delete tree[i];
        }
    }

    T* del(T &key){
        int index = 0;
        bool found = false;
        for(int i = 0; i < tree.capacity(); i++){
            if(tree[i] != nullptr)
                if(*tree[i] == key){
                    found = true;
                    index = i;
                }
        }

        if(!found){
            return nullptr;
        }

        int foundIndex = 0;
        foundIndex = inOrderSearchForDelete(foundIndex, index);
        T *toReturn = new T;
        toReturn = tree[index];
        tree[index] = tree[foundIndex];
        tree[foundIndex] = nullptr;

        return toReturn;
    }


    void insert(T &key){
        if(root(key) == 0){
            bool exitCondition = 0;
            int currentParent = 0;
            while(exitCondition == 0){

                if(currentParent*2 + 2 > tree.capacity()){
                    tree.resize(currentParent*2+2 + tree.capacity());
                }

                if(*tree[currentParent] > key){
                    exitCondition = set_right(key, currentParent);
                    currentParent = currentParent * 2 + 2;
                }
                else
                {
                    if(*tree[currentParent] < key){
                        exitCondition = set_left(key, currentParent);
                        currentParent = currentParent * 2 + 1;
                    }
                    else{
                        tree[currentParent] = &key;
                    }
                }
            }


        }

    }

    T* search(T &key){
        int index = 0;
        bool found = false;
        for(int i = 0; i < tree.capacity(); i++){
            if(tree[i] != nullptr)
                if(*tree[i] == key){
                    found = true;
                    index = i;
                }
        }

        if(!found){
            return nullptr;
        }

        return tree[index];

    }

    vector<T *> GetTree() const {
        return tree;
    }
};



#endif