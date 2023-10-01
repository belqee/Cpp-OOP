#include "gtest/gtest.h"
#include "word_counter.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>

using namespace std;

TEST(class_word_counter, correct_out) {
    stringstream in, out;
    word_counter_class counter;
    //first test
    in << "abc abc ab abc ab a a";
    counter.count_words(in);
    counter.write_result(out);
    EXPECT_EQ(out.str(), "abc;3;42%\na;2;28%\nab;2;28%\n");
    
    in.clear();
    out.clear();
    in.str("");
    out.str("");
    
    //second test
    in << "Better late ''' than ..,, never, ever never";
    counter.count_words(in);
    counter.write_result(out);
    EXPECT_EQ(out.str(), "never;2;33%\nBetter;1;16%\never;1;16%\nlate;1;16%\nthan;1;16%\n");
}

