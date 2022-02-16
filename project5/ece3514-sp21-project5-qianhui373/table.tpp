#include "table.hpp"

// TODO
#include <stdexcept>


//template<typename T>
//Table<T>::Table(std::size_t  size)
//{
//
//}
template<typename T>
std::size_t Table<T>::numRows() const noexcept
{
    return m_rows;
}

template<typename T>
std::size_t Table<T>::numCols() const noexcept
{
    return m_cols;
}

template<typename T>
void Table<T>::setHeader(std::size_t col, std::string name)
{
    if (col == 0 || col > m_cols + 1)
        throw std::invalid_argument("col over index");
    int index = getIndex(name);
    if (index != -1)
        throw std::invalid_argument("this col name same ");
    m_header.remove(col);
    m_header.insert(col, name);
}

template<typename T>
std::string Table<T>::getHeader(std::size_t col)
{
    if (col == 0 || col > m_cols + 1)
        throw std::invalid_argument("col over index");
    return m_header.getEntry(col);
}

template<typename T>
void Table<T>::insertRow(std::size_t position, T value)
{
    if (position == 0 || position > m_rows + 1)
        throw std::invalid_argument("position over index");
    LinkedList<T> temp;
    for (int i = 0; i < m_header.getLength(); i++)
        temp.insert(temp.getLength() + 1, value);

    m_data.insert(position, temp);
    m_rows++;
}

template<typename T>
void Table<T>::appendRow(T value)
{
    m_data.insert(m_rows + 1, value);//insert data
    m_rows++;
}

template<typename T>
void Table<T>::insertCol(std::size_t position, std::string name, T value)
{
    if (position == 0 || position > m_cols + 1)
        throw std::invalid_argument("position over index");
    int index = getIndex(name);
    if (index != -1)
        throw std::invalid_argument("this col name same ");
    m_header.insert(position, name); //add header name
    for (int i = 1; i < m_rows + 1; i++)
    {
        m_data.getEntry(i).insert(position, value);//Add this value to each column
    }
    m_cols++;
}

template<typename T>
void Table<T>::appendCol(std::string name, T value)
{
    int index = getIndex(name);
    if (index != -1)
        throw std::invalid_argument("this col name same ");

    m_header.insert(m_cols + 1, name);
    for (int i = 1; i < m_rows + 1; i++)
    {
        m_data.getEntry(i).insert(m_cols + 1, value);//Add this value to each column
    }
    m_cols++;
}

template<typename T>
const T& Table<T>::operator()(std::size_t row, std::size_t col) const
{
    if (row == 0 || row > m_rows + 1 || col == 0 || col > m_cols + 1)
        throw std::invalid_argument("position over index");
    return m_data.getEntry(row).getEntry(col);

}

template<typename T>
T& Table<T>::operator()(std::size_t row, std::size_t col)
{
    if (row == 0 || row > m_rows + 1 || col == 0 || col > m_cols + 1)
        throw std::invalid_argument("position over index");
    return m_data.getEntry(row).getEntry(col);
}

template<typename T>
void Table<T>::setRowCol(std::size_t row, std::size_t col, T value)
{
    if (row == 0 || row > m_rows + 1 || col == 0 || col > m_cols + 1)
        throw std::invalid_argument("position over index");
    LinkedList<T> temp = m_data.getEntry(row);
    temp.remove(col);
    temp.insert(col, value);
    
    m_data.remove(row);
    m_data.insert(row, temp);
}


template<typename T>
void Table<T>::sortBy(std::size_t col)
{
    int a[1024];
    for (size_t i = 0; i < m_rows; i++)
    {
        a[i] = m_data.getEntry(i + 1).getEntry(col);
    }
    //
    for (size_t i = 0; i < m_rows; i++)
    {
        for (size_t j = 0; j < m_rows - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
                std::swap(m_data.getEntry(j + 1), m_data.getEntry(j + 2));
            }
        }
    }

}

template<typename T>
void Table<T>::sortBy(std::string colname)
{
    int index = getIndex(colname);
    if (index == -1)
        throw std::invalid_argument("this col no name");

    int a[1024];
    for (size_t i = 0; i < m_rows; i++)
    {
        a[i] = m_data.getEntry(i + 1).getEntry(index);
    }
    //
    for (size_t i = 0; i < m_rows; i++)
    {
        for (size_t j = 0; j < m_rows - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
                std::swap(m_data.getEntry(j + 1), m_data.getEntry(j + 2));
            }
        }
    }
}

template<typename T>
void Table<T>::reverseSortBy(std::size_t col)
{
    int a[1024];
    for (size_t i = 0; i < m_rows; i++)
    {
        a[i] = m_data.getEntry(i + 1).getEntry(col);
    }
    //
    for (size_t i = 0; i < m_rows; i++)
    {
        for (size_t j = 0; j < m_rows - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
                std::swap(m_data.getEntry(j + 1), m_data.getEntry(j + 2));
            }
        }
    }
}

template<typename T>
void Table<T>::reverseSortBy(std::string colname)
{
    int index = getIndex(colname);

    if (index == -1)
        throw std::invalid_argument("this col no name");

    int a[1024];
    for (size_t i = 0; i < m_rows; i++)
    {
        a[i] = m_data.getEntry(i + 1).getEntry(index);
    }
    //
    for (size_t i = 0; i < m_rows; i++)
    {
        for (size_t j = 0; j < m_rows - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
                std::swap(m_data.getEntry(j + 1), m_data.getEntry(j + 2));
            }
        }
    }
}

template<typename T>
size_t Table<T>::getIndex(std::string colname)
{
    for (size_t i = 1; i < m_cols + 1; i++)
    {
        if (m_header.getEntry(i) == colname)
            return i;
    }
    return -1;
}