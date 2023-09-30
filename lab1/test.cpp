#include "gtest/gtest.h"
#include "word_counter.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>

using namespace std;

TEST(classWordCounter, correctOutput) {
    stringstream in, out;
    Word_counter counter;
    //test 1
    in << "xxx xx xxx xxx x";
    counter.countWords(in);
    counter.write_result(out);

    EXPECT_EQ(out.str(), "xxx;3;60%\nx;1;20%\nxx;1;20%\n");
    //test 2
    in.clear();
    out.clear();
    in.str("");
    out.str("");
    counter.clear();

    in << "give papa a ,,, cup    of proper\n\n\n coffe\t in a copper coffe cup.";
    counter.countWords(in);
    counter.write_result(out);

    EXPECT_EQ(out.str(), "a;2;16%\ncoffe;2;16%\ncup;2;16%\ncopper;1;8%\ngive;1;8%\nin;1;8%\nof;1;8%\npapa;1;8%\nproper;1;8%\n");
}