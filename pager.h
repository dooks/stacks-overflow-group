#pragma once

/*
 * Keeps track of page numbers, current page, cursor location
 */
class Pager {
  int m_cursor;      // Current cursor
  int m_pageNumber;  // Current page
  int m_numElements; // Length of elements to keep track of
  int m_pageSize;    // How many elements to display per page

public:
  enum dir { UP, DOWN, LEFT, RIGHT };

  Pager();
  Pager(unsigned page_size);

  // Mutators
  void setPageSize(int); // Change number of items to display per page
  void   setLength(int); // Change number of total items
  void  moveCursor(dir); // pages left/right, moves one item up/down
  void    movePage(dir); // Pages left/right

  // Accessors
  int getPageNumber(); // Current page number
  int getCursor();     // Get position of cursor on current page
  int getPageFirst();  // Get number of item at start of current page
  int getPageLast();   // Get number of item at end of current page
  int getAtCursor();   // Get number of item at cursor on current page
};
