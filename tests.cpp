#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "OList.h"


TEST_CASE("Getting and setting within the list") {
    OList l;
    l.insert("a");
    CHECK(l.length() == 1);

    l.insert("aa");
    CHECK(l.length() == 2);

    l.insert("aaa");
    CHECK(l.length() == 3);

    l.insert("aaaa");
    CHECK(l.length() == 4);

    l.insert("aaaaaa");
    CHECK(l.length() == 5);

    l.insert("b");
    CHECK(l.length() == 6);



    CHECK(l.get(0) == "a");
    CHECK(l.get(1) == "aa");
    CHECK(l.get(2) == "aaa");
    CHECK(l.get(3) == "aaaa");
  
}

TEST_CASE("Contains") {
    OList l;
    l.insert("a");
    l.insert("b");

    CHECK(l.contains("a"));
    CHECK(l.contains("b"));
    CHECK(! l.contains("aa"));
    CHECK(! l.contains("bb"));

}


TEST_CASE("Reverse") {
    OList l;
    l.insert("a");
    l.insert("b");

    l.reverse();

    CHECK(l.get(1) == "a");
    CHECK(l.get(0) == "b");
}

TEST_CASE("Remove") {
    OList l;
    l.insert("0");
    l.insert("1");
    l.insert("2");  
    l.insert("3");

    l.remove(0);
    CHECK(l.length() == 3);
    CHECK(l.get(0) == "1");

    l.remove(0);
    CHECK(l.length() == 2);
    CHECK(l.get(0) == "2");

    l.remove(0);
    CHECK(l.length() == 1);
    CHECK(l.get(0) == "3");


}

TEST_CASE("Delete") {
  OList *l = new OList();
  l->insert("e");
  l->insert("d");
  l->insert("c");
  l->insert("b");  
  l->insert("a");

  delete l;

}