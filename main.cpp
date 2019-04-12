#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Fano.h"
#include <stdio.h>
void fano(string input);

int main(int argc, char* argv[]){

//    string input;
//    getline(cin, input);
//    fano(input);
//    cout << endl;

    string input = "it is test string";
    fano(input);
    cout << endl;

    string input1 = "There are only two ways to live your life. One is as though nothing is a miracle. The other is as though everything is a miracle.";
    //getline(cin, input);
    fano(input1);
    cout << endl;

    string input2 = "When you start thinking a lot about your past, it becomes your present and you can’t see your future without it.";
    fano(input2);
    cout << endl;

    string input3 = "Robin Hood was born near the end of the 12th century. His real name was Robert. He was the son of the Earl of Huntingdon. At that time, England had many problems. King Richard was away on a crusade in the Holy Land. He was away many years.";
    fano(input3);
    cout << endl << endl;

//    testing::InitGoogleTest(&argc, argv);
//    int b = RUN_ALL_TESTS();

    return 0;
}