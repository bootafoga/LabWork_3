//
// Created by Мария on 03.04.2019.
//

#ifndef LABORATORYWORK_3_FANO_H
#define LABORATORYWORK_3_FANO_H


#include "map.h"
#include "List.h"
#include <stdio.h>
using namespace std;

void fano(){
    MapNode<char, int> *current[64];

    Map<char, int> symbols;
    string stroka = "it is test string";

    int currentCount = 0;
    for (int i = 0; i < stroka.length(); i++){
        currentCount = 0;
        char currChar = stroka[i];
        for (int j = i; j < stroka.length(); j++){
            if (stroka[j] == currChar) currentCount++;

        }
        symbols.insert(currChar, currentCount);
    }

    List<char> keys = symbols.get_keys();
    for (int i = 0; i < symbols.getSize(); i++){
        current[i] = symbols.find(keys.At(i));
        cout << current[i]->key;
    }

}

#endif //LABORATORYWORK_3_FANO_H
