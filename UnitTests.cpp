//
// Created by Мария on 03.04.2019.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "Fano.h"
#include "map.h"
using testing::Eq;

void fanoCreateCode(int size, MapNode<char, int> *arrayOfSymbols[]);

namespace {
    class ClassDeclaration: public testing::Test{
    public:
        ClassDeclaration(){
        }
    };
}

TEST_F(ClassDeclaration, fanoCodingEmpty_check){
    try {
        string check;
        Fano *newFano = new Fano(check);

    } catch (exception& ex) {
        EXPECT_STREQ("Empty input", ex.what());
    }
}

TEST_F(ClassDeclaration, fanoCoding_check){
    string check = "abbcccdddd";
    Fano *newFano = new Fano(check);

    ASSERT_EQ("1111101101010100000", newFano->getCoded());
}

TEST_F(ClassDeclaration, fanoDecoding_check){
    string check = "it is test string";
    Fano *newFano = new Fano(check);

    ASSERT_EQ(check, newFano->getDecoded());
}

TEST_F(ClassDeclaration, fanoCodingFirstBlock_check) {
    string check = "aabbcc";
    Fano *newFano = new Fano(check);
    List<char> keys = newFano->getSymb();

    ASSERT_EQ(keys.At(0), 'a');
    ASSERT_EQ(keys.At(1), 'b');
    ASSERT_EQ(keys.At(2), 'c');
}


TEST_F(ClassDeclaration, fanoCodingSecondBlock1_check){
    Map<char, int> symbols;
    MapNode<char, int> *arrayOfSymbols[4];
    symbols.insert('a', 1);
    symbols.insert('b', 2);
    symbols.insert('c', 3);
    symbols.insert('d', 4);

    arrayOfSymbols[0] = symbols.find('a');
    arrayOfSymbols[1] = symbols.find('b');
    arrayOfSymbols[2] = symbols.find('c');
    arrayOfSymbols[3] = symbols.find('d');

    fanoCreateCode(4, arrayOfSymbols);
    ASSERT_EQ(arrayOfSymbols[0]->key, 'a');
    ASSERT_EQ(arrayOfSymbols[1]->key, 'b');
    ASSERT_EQ(arrayOfSymbols[2]->key, 'c');
    ASSERT_EQ(arrayOfSymbols[3]->key, 'd');
}

TEST_F(ClassDeclaration, fanoCodingSecondBlock2_check){
    Map<char, int> symbols;
    MapNode<char, int> *arrayOfSymbols[4];
    symbols.insert('a', 1);
    symbols.insert('b', 2);
    symbols.insert('c', 3);
    symbols.insert('d', 4);

    arrayOfSymbols[0] = symbols.find('a');
    arrayOfSymbols[1] = symbols.find('b');
    arrayOfSymbols[2] = symbols.find('c');
    arrayOfSymbols[3] = symbols.find('d');

    fanoCreateCode(4, arrayOfSymbols);
    ASSERT_EQ(arrayOfSymbols[0]->value, 1);
    ASSERT_EQ(arrayOfSymbols[1]->value, 2);
    ASSERT_EQ(arrayOfSymbols[2]->value, 3);
    ASSERT_EQ(arrayOfSymbols[3]->value, 4);
}

TEST_F(ClassDeclaration, fanoCreateCode_check){
    Map<char, int> symbols;
    MapNode<char, int> *arrayOfSymbols[4];
    symbols.insert('a', 1);
    symbols.insert('b', 2);
    symbols.insert('c', 3);
    symbols.insert('d', 4);

    arrayOfSymbols[0] = symbols.find('a');
    arrayOfSymbols[1] = symbols.find('b');
    arrayOfSymbols[2] = symbols.find('c');
    arrayOfSymbols[3] = symbols.find('d');

    fanoCreateCode(4, arrayOfSymbols);
    ASSERT_EQ(arrayOfSymbols[0]->code, "111");
    ASSERT_EQ(arrayOfSymbols[1]->code, "110");
    ASSERT_EQ(arrayOfSymbols[2]->code, "10");
    ASSERT_EQ(arrayOfSymbols[3]->code, "0");
}