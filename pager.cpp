#include <iostream>
#include "pager.h"
using namespace std;

Pager::Pager(unsigned page_size = 1) :
  m_cursor(0), m_pageNumber(0), m_pageSize(page_size), m_numElements(0) {}

// Accessors
int Pager::getCursor()         { return m_cursor; }
int Pager::getPageNumber()     { return m_pageNumber; }
int Pager::getPageFirst()      { return m_pageNumber * m_pageSize; }
int Pager::getPageLast()       {
  // Return last item on page
  int last = (m_pageNumber * m_pageSize) + m_pageSize;
  // Add in check if last item reached before end of page
  return (last < m_numElements) ? last : m_numElements - 1;
}
int Pager::getAtCursor()       {
  // Returns item number cursor is currently on
  return m_cursor + (m_pageNumber * m_pageSize);
}


// Mutators
void Pager::movePage(Pager::dir input) {
  switch(input) {
    case Pager::UP:
      if(--m_pageNumber < 0) {
        m_pageNumber = 0;
      }
      break;
	case Pager::DOWN:
      if(++m_pageNumber * m_pageSize > m_numElements) {
        m_pageNumber--;
      }
      break;
  }
}

void Pager::moveCursor(Pager::dir input) {
  switch(input) {
    case Pager::UP:
      if(--m_cursor < 0) {
        m_cursor = m_pageSize - 1;
        movePage(Pager::UP);
      }
      break;
	case Pager::DOWN:
      if(++m_cursor >= m_pageSize) {
        m_cursor = 0;
        movePage(Pager::DOWN);
      }
      break;
	case Pager::LEFT:
      movePage(Pager::UP);
      break;
	case Pager::RIGHT:
      movePage(Pager::DOWN);
      break;
  }
}

void Pager::setLength(int length) {
  m_cursor      = 0;
  m_pageNumber  = 0;
  m_pageSize    = m_pageSize;
  m_numElements = length;
}