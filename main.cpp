#include "map.h"
#include <stdio.h>
using namespace std;

void fanoSum(int size, MapNode<char, int> *current[]){
    if (size > 1){

        int sum = 0;
        for (int i = 0; i < size; i++){
            sum = sum + current[i]->value;
        }
        bool flag = false;
        if (sum-current[size-1]->value < sum/2) flag = true;


        MapNode<char, int> *left[size];
        int sumOfVal = 0;
        int sizeLeft = 0;
        do{
            if (sizeLeft == size-1 && flag) break;
            left[sizeLeft] = current[sizeLeft];
            sumOfVal = sumOfVal + current[sizeLeft]->value;
            left[sizeLeft]->code = left[sizeLeft]->code + '1';
            sizeLeft++;

        } while (sumOfVal < sum/2);
        fanoSum(sizeLeft, left);
        //левая половина

        MapNode<char, int> *right[size];
        int sizeRight = 0;
        for (sizeLeft; sizeLeft < size; sizeLeft++){
            right[sizeRight] = current[sizeLeft];
            right[sizeRight]->code = right[sizeRight]->code + '0';
            sizeRight++;
        }
        fanoSum(sizeRight, right);
        // правая половина
    }
    else {

    }

}
int main(){
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
        cout << current[i]->key << "[" << current[i]->value << "] ";
    }

    for (int i = 0; i < symbols.getSize() - 1; i++){
        MapNode<char, int> *item = current[i];
        if (current[i]->value > current[i+1]->value){
            current[i] = current[i+1];
            current[i+1] = item;
            i = -1;
        }
    }


    cout << endl;

    for (int i = 0; i < symbols.getSize(); i++){
        cout << current[i]->key << "[" << current[i]->value << "] ";
    }

    // имеем отсортированную цепочку

    int size = symbols.getSize();
    fanoSum(size, current);

//    string check = "";
//    check = check + '1';
//    check = check + '1';
//    check = check + '1';
//    check = check + '0';

//    cout << check;

    for (int i = 0; i < symbols.getSize(); i++){
        cout << current[i]->key << "[" << current[i]->code << "] ";
    }

    cout << endl;
    for (char o: stroka){
        cout << symbols.find(o)->key << symbols.find(o)->code << " ";
    }

//
//    int sum = 0;
//    for (int i = 0; i < size; i++){
//        sum = sum + current[i]->value;
//    }
//
//    cout << endl << sum << endl;
//
//    MapNode<char, int> *current_new[size];
//    int checkSum = 0;
//    int i = 0;
//    while (checkSum < sum/2) {
//        current_new[i] = current[i];
//        checkSum = checkSum + current[i]->value;
//        i++;
//    }
//
//    MapNode<char, int> *current_new2[size];
//    int k = 0;
//    for (i; i < size; i++){
//        current_new2[k] = current[i];
//        k++;
//    }
    // есть мапа символ-частота
   // вернуть список частот
   // рекурсивно:
   // отсортировать список
   // дойти до половины, конструктор копии
   // вторая половина, конструктор копии
   // когда по 1 символу, стоп





   return 0;
}