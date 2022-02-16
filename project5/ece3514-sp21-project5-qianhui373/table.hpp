#ifndef TABLE_HPP
#define TABLE_HPP

// TODO
#include <string>
#include <iostream>



#include "abstract_table.hpp"
#include "array_list.hpp"
#include "linked_list.hpp"


template<typename T>
class Table: public AbstractTable<T>{
public:

    //default constructor
    Table() = default;

    //copy constructor
    //Table(const Table<T>& rhs) = default;

    //move constructor
    //Table(Table<T> && rhs) = default;

    //copy assignment
    //Table<T>& operator = (const Table<T>& rhs) = default;

    //move assignment
    //Table<T>& operator=(Table<T> && rhs) = default;

    //destructor
    ~Table() = default;

    
    //////////////////////////////////////////////////////////////////////////////////

    // return the number of rows in the Table
    std::size_t numRows() const noexcept;

    // return the number of columns in the Table
    std::size_t numCols() const noexcept;

    // set column header to the string name
    // valid values for col is [1,numCols()]
    // throws std::invalid_argument if invalid column
    void setHeader(std::size_t col, std::string name);

    // get column header as string
    // valid values for col is [1,numCols()]
    // throws std::invalid_argument if invalid column
    std::string getHeader(std::size_t col);

    // insert row into table at position set to value
    // valid values for position is [1,numRows()+1]
    // throws std::invalid_argument if invalid
    void insertRow(std::size_t position, T value);


    void setRowCol(std::size_t row, std::size_t col, T value);

    // append row to table set to value
    void appendRow(T value);

    // insert column into table at position set to value
    // valid values for position is [1,numCols()+1]
    // throws std::invalid_argument if invalid
    void insertCol(std::size_t position, std::string name, T value);

    // append column to table set to value
    void appendCol(std::string name, T value);



    // return constant reference to table entry at (row, col)
    // throws std::invalid_argument if invalid row or column
    const T& operator()(std::size_t row, std::size_t col) const;

    // return reference to table entry at (row, col)
    // throws std::invalid_argument if invalid row or column
    T& operator()(std::size_t row, std::size_t col);

    size_t getIndex(std::string colname);
    // stable sort (low to high) of table rows using column col
    // throws std::invalid_argument if invalid column
    void sortBy(std::size_t col);

    // stable sort (low to high) of table rows using column with name
    // throws std::invalid_argument if invalid column name
    void sortBy(std::string colname);

    // stable sort (high to low) of table rows using column col
    // throws std::invalid_argument if invalid column
    void reverseSortBy(std::size_t col);

    // stable sort (high to low) of table rows using column with name
    // throws std::invalid_argument if invalid column name
    void reverseSortBy(std::string colname);

    

private:

    std::size_t m_cols=0;
    std::size_t m_rows=0;

    ArrayList<LinkedList<T>> m_data;
    ArrayList<std::string> m_header;
};

#include "table.tpp"
#endif
