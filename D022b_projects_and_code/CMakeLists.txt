cmake_minimum_required(VERSION 3.28)
project(D022b_projects_and_code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories("Proj 2 D022b")

add_executable(D022b_projects_and_code
        "Proj 2 D022b/Variable.cpp"
        "Proj 2 D022b/Variable.h"
        "Proj 2 D022b/VariableListMain.cpp"
        "Proj 2 D022b/VariableListManager.cpp"
        "Proj 2 D022b/VariableListManager.h"
        array2dim.cpp
        BankAccount.cpp
        BankAccount.h
        calcStudentScores.cpp
        ComputeAverage.cpp
        countScores.cpp
        cstring-traverse.cpp
        demoString.cpp
        dynamicArrayUsingNew.cpp
        functionPractice.cpp
        getArrayInfo.cpp
        inputStreamEx.cpp
        isHexadecimal.cpp
        isTheFirstThreeTheSameAsTheLastThree.cpp
        linkedListExs.cpp
        LinkedListZyBook.cpp
        ManageVariableObjects.cpp
        MoviesLinkedList.cpp
        MoviesLinkedList.h
        MySmallBank.cpp
        MySmallBank2.cpp
        outputPractice.cpp
        outputStringStream.cpp
        passByReferInt.cpp
        "passByReferWPointer (1).cpp"
        passByReferWPointer.cpp
        point3VectorOfPointers.cpp
        readSecretKey.cpp
        reportOutGrades.cpp
        "sample-comment (3).cpp"
        SinglyLinkedList.h
        string2upperLower.cpp
        structPracticeWithStream.cpp
        structTesting.cpp
        "studentLinkedDouble (1).cpp"
        studentLinkedDouble.cpp
        studentLinkedList.cpp
        studentLinkedList2.cpp
        studentLinkedLstInsert.cpp
        "studentstruct2 (1).cpp"
        vector-erase.cpp
        vectorGreaterThanNumber.cpp)
