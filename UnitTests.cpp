//
// Created by Мария on 03.04.2019.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "Fano.h"
using testing::Eq;

namespace {
    class ClassDeclaration: public testing::Test{
    public:
        //initialization of object that will be used in test

        ClassDeclaration(){

        }
    };
}

TEST_F(ClassDeclaration, fano_check){

    string check = "it is test string";
    Fano *newFano = new Fano(check);

    ASSERT_EQ(check, newFano->getDecoded());
}
