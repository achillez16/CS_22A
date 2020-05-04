cmake_minimum_required(VERSION 3.16)
project(CS_22A)

set(CMAKE_CXX_STANDARD 14)

add_executable(CS_22A HelloWorld.cpp BuyItems.cpp PrintShape.cpp EvaluateGrade.cpp AskForThreeAscendingNumbers.cpp GenerateWithinRange.cpp CalcTax.cpp)
add_executable(BuyItems BuyItems.cpp)
add_executable(HelloWorld HelloWorld.cpp)
add_executable(PrintShape PrintShape.cpp)
add_executable(EvaluateGrade EvaluateGrade.cpp)
add_executable(AskForThreeAscendingNumbers AskForThreeAscendingNumbers.cpp)
add_executable(GenerateWithinRange GenerateWithinRange.cpp)
add_executable(CalcTax CalcTax.cpp)