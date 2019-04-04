#include "map.h"
#include <stdio.h>
#include <string>
#include <iomanip>

using namespace std;
class Fano{
private:
    string input;
    string encodedStr;
    string decodedStr;
    Map<char, int> symbolsInString;
    MapNode<char, int> *arrayOfSymbols[64];
public:
    Fano(string input){
        this->input = input;
    }

    void fanoCoding();
    void fanoDecoding();
    void printInfo();
};

void fanoCreateCode(int size, MapNode<char, int> *arrayOfSymbols[]){
    if (size > 1){
        int frequenciesSum = 0;
        for (int i = 0; i < size; i++){
            frequenciesSum = frequenciesSum + arrayOfSymbols[i]->value;
        }

        bool flag = false;
        if (frequenciesSum - arrayOfSymbols[size - 1]->value < frequenciesSum/2) flag = true;

        // if all elements without the last will be less than half of total frequency
        // algorithm will add the last item in new chain and we get an endless cycle,
        // to eliminate this error, we will not add the last element in new chain

        MapNode<char, int> *left[size];
        int sumOfFrequenciesInNewChain = 0;
        int sizeLeft = 0;
        do{
            if (sizeLeft == size - 1 && flag) break; // here we consider the case described above
            left[sizeLeft] = arrayOfSymbols[sizeLeft];
            sumOfFrequenciesInNewChain = sumOfFrequenciesInNewChain + arrayOfSymbols[sizeLeft]->value;
            left[sizeLeft]->code = left[sizeLeft]->code + '1';
            sizeLeft++;
        } while (sumOfFrequenciesInNewChain < frequenciesSum/2);
        fanoCreateCode(sizeLeft, left);

        MapNode<char, int> *right[size]; //create right chain from remained elements
        int sizeRight = 0;
        for (sizeLeft; sizeLeft < size; sizeLeft++){
            right[sizeRight] = arrayOfSymbols[sizeLeft];
            right[sizeRight]->code = right[sizeRight]->code + '0';
            sizeRight++;
        }
        fanoCreateCode(sizeRight, right);
    }
}
void Fano::fanoCoding() {
    int frequency = 0;
    for (int i = 0; i < input.length(); i++){
        frequency = 0;
        char currentSymb = input[i];
        for (int j = i; j < input.length(); j++){
            if (input[j] == currentSymb) frequency++;
        }
        symbolsInString.insert(currentSymb, frequency);
    }

    int size = symbolsInString.getSize();
    // add symbols-frequencies in map

    List<char> keys = symbolsInString.get_keys();
    for (int i = 0; i < size; i++){
        arrayOfSymbols[i] = symbolsInString.find(keys.At(i));
    }
    // create array of symbols


    for (int i = 0; i < size - 1; i++){
        MapNode<char, int> *currentItem = arrayOfSymbols[i];
        if (arrayOfSymbols[i]->value > arrayOfSymbols[i+1]->value){
            arrayOfSymbols[i] = arrayOfSymbols[i+1];
            arrayOfSymbols[i+1] = currentItem;
            i = -1;
        }
    }

    fanoCreateCode(size, arrayOfSymbols);

    string codedString = "";
    for (char o: input){
        codedString = codedString + symbolsInString.find(o)->code;
    }

    encodedStr = codedString;
}


void Fano::fanoDecoding(){

    string oneSymbol;

    for (int i = 0; i < encodedStr.size(); i++){
        oneSymbol = oneSymbol + encodedStr[i];
        for (int j = 0; j < symbolsInString.getSize(); j++){
            if (arrayOfSymbols[j]->code == oneSymbol) {
                decodedStr = decodedStr + arrayOfSymbols[j]->key;
                oneSymbol = "";
            }
        }
    }
}

void Fano::printInfo() {

    cout << "------------------------------------" << endl;
    cout << "|  Symbol  | " << "Frequency  |" << " Code";
    cout << "\n------------------------------------";

    for (int i = 0; i < symbolsInString.getSize(); i++) {
        cout << endl << "| ";
        cout.setf(ios::right);
        cout.width(3);
        cout << "[" << arrayOfSymbols[i]->key << "]";
        cout << setw(5) << " |";
        cout.setf(ios::right);
        cout.width(5);
        cout << "[" << arrayOfSymbols[i]->value << "]";
        cout << setw(6) << " |";
        cout << " [" << arrayOfSymbols[i]->code << "]";
    }
    cout << "\n------------------------------------" << endl;
    cout << "Input: " << "[ " << input << " ]";
    cout << "\nCoded string: [ " << encodedStr << " ]";
    cout << "\nEncoded string: [ " << decodedStr << " ]";
    cout << "\nSize of input: [ " << (input.size())*8 << " ]";
    cout << "\nSize of coded string: [ " << encodedStr.size() << " ]";
    cout << "\nCompression ratio: [ " << (double)(input.size())*8/encodedStr.size() << " ]\n";
}

void fano(string input){
    Fano *fano = new Fano(input);
    fano->fanoCoding();
    fano->fanoDecoding();
    fano->printInfo();
}

int main(){
    string stroka = "it is test string";
    fano(stroka);

    return 0;
}