#include "catch.hpp"

// TODO
#include "table.hpp"

TEST_CASE("Test basic operations of Table", "[Table]")
{
    Table<int> table;

    table.insertCol(1, "ID", 0);


    CHECK(table.numRows() == 0);
    CHECK_FALSE(table.numCols() == 0);
    CHECK(table.numCols() == 1);

    table.insertRow(1, 4);

    CHECK(table.numRows() == 1);

}

TEST_CASE("Test () operations of Table", "[Table]")
{
    Table<int> table;
    table.insertCol(1, "ID", 0);
    table.insertCol(2, "c1", 1);
    table.insertCol(3, "c2", 3);
    table.insertCol(4, "c3", 3);
    table.insertCol(5, "c5", 4);
    table.insertRow(1, 12345);
    table.insertRow(2, 55634);
    table.insertRow(3, 98637);



    CHECK(table(2, 2) == 55634);

    table.setRowCol(1, 2, 80);
    table.setRowCol(1, 3, 74);
    table.setRowCol(1, 4, 92);
    table.setRowCol(1, 5, 65);

    table.setRowCol(2, 2, 98);
    table.setRowCol(2, 3, 94);
    table.setRowCol(2, 4, 90);
    table.setRowCol(2, 5, 94);

    CHECK(table(2, 2) == 98);

}

TEST_CASE("Test sortBy col operations of Table", "[Table]")
{
    Table<int> table;
    table.insertCol(1, "ID", 0);
    table.insertCol(2, "c1", 1);
    table.insertCol(3, "c2", 3);
    table.insertCol(4, "c3", 3);
    table.insertCol(5, "c5", 4);
    table.insertRow(1, 12345);
    table.insertRow(2, 55634);
    table.insertRow(3, 98637);

    table.setRowCol(1, 2, 80);
    table.setRowCol(1, 3, 74);
    table.setRowCol(1, 4, 92);
    table.setRowCol(1, 5, 65);

    table.setRowCol(2, 2, 98);
    table.setRowCol(2, 3, 94);
    table.setRowCol(2, 4, 90);
    table.setRowCol(2, 5, 94);

    table.setRowCol(3, 2, 54);
    table.setRowCol(3, 3, 49);
    table.setRowCol(3, 4, 66);
    table.setRowCol(3, 5, 72);

    REQUIRE(table(2, 1) == 55634);
    REQUIRE(table(2, 5) == 94);

    table.sortBy(5);

    REQUIRE(table(2, 1) == 98637);
    REQUIRE(table(2, 5) == 72);
}


TEST_CASE("Test sortBy colname operations of Table", "[Table]")
{
    Table<int> table;
    table.insertCol(1, "ID", 0);
    table.insertCol(2, "c1", 1);
    table.insertCol(3, "c2", 3);
    table.insertCol(4, "c3", 3);
    table.insertCol(5, "c5", 4);
    table.insertRow(1, 12345);
    table.insertRow(2, 55634);
    table.insertRow(3, 98637);

    table.setRowCol(1, 2, 80);
    table.setRowCol(1, 3, 74);
    table.setRowCol(1, 4, 92);
    table.setRowCol(1, 5, 65);

    table.setRowCol(2, 2, 98);
    table.setRowCol(2, 3, 94);
    table.setRowCol(2, 4, 90);
    table.setRowCol(2, 5, 94);

    table.setRowCol(3, 2, 54);
    table.setRowCol(3, 3, 49);
    table.setRowCol(3, 4, 66);
    table.setRowCol(3, 5, 72);

    REQUIRE(table(2, 1) == 55634);
    REQUIRE(table(2, 5) == 94);

    table.sortBy("c5");

    REQUIRE(table(2, 1) == 98637);
    REQUIRE(table(2, 5) == 72);
}


TEST_CASE("Test reverseSortBy col operations of Table", "[Table]")
{
    Table<int> table;
    table.insertCol(1, "ID", 0);
    table.insertCol(2, "c1", 1);
    table.insertCol(3, "c2", 3);
    table.insertCol(4, "c3", 3);
    table.insertCol(5, "c5", 4);
    table.insertRow(1, 12345);
    table.insertRow(2, 55634);
    table.insertRow(3, 98637);

    table.setRowCol(1, 2, 80);
    table.setRowCol(1, 3, 74);
    table.setRowCol(1, 4, 92);
    table.setRowCol(1, 5, 65);

    table.setRowCol(2, 2, 98);
    table.setRowCol(2, 3, 94);
    table.setRowCol(2, 4, 90);
    table.setRowCol(2, 5, 94);

    table.setRowCol(3, 2, 54);
    table.setRowCol(3, 3, 49);
    table.setRowCol(3, 4, 66);
    table.setRowCol(3, 5, 72);

    REQUIRE(table(1, 1) == 12345);
    REQUIRE(table(2, 5) == 94);

    table.reverseSortBy(5);

    REQUIRE(table(1, 1) == 55634);
    REQUIRE(table(2, 5) == 72);
}

TEST_CASE("Test reverseSortBy colname operations of Table", "[Table]")
{
    Table<int> table;
    table.insertCol(1, "ID", 0);
    table.insertCol(2, "c1", 1);
    table.insertCol(3, "c2", 3);
    table.insertCol(4, "c3", 3);
    table.insertCol(5, "c5", 4);
    table.insertRow(1, 12345);
    table.insertRow(2, 55634);
    table.insertRow(3, 98637);

    table.setRowCol(1, 2, 80);
    table.setRowCol(1, 3, 74);
    table.setRowCol(1, 4, 92);
    table.setRowCol(1, 5, 65);

    table.setRowCol(2, 2, 98);
    table.setRowCol(2, 3, 94);
    table.setRowCol(2, 4, 90);
    table.setRowCol(2, 5, 94);

    table.setRowCol(3, 2, 54);
    table.setRowCol(3, 3, 49);
    table.setRowCol(3, 4, 66);
    table.setRowCol(3, 5, 72);

    REQUIRE(table(1, 1) == 12345);
    REQUIRE(table(2, 5) == 94);

    table.reverseSortBy("c5");

    REQUIRE(table(1, 1) == 55634);
    REQUIRE(table(2, 5) == 72);
}

