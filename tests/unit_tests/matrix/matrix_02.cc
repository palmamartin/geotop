#include <gtest/gtest.h>
#include <matrix.h>
#include <rowview.h>

TEST(Matrix, RowView){
  Matrix<int> m{2,2}; // 2x2 matrix
  int c{0};
   
  for (auto &x : m)
    x = ++c;

  EXPECT_EQ( 1, m.row(1)[1] );
  EXPECT_EQ( 2, m.row(1)[2] );
  EXPECT_EQ( 3, m.row(2)[1] );
  EXPECT_EQ( 4, m.row(2)[2] );
 
}

TEST(Matrix, RowView_CheckIndex){
  Matrix<int> m{2,2}; // 2x2 matrix

  EXPECT_NO_THROW( m.row(1) );
  EXPECT_NO_THROW( m.row(2) );

#ifndef NDEBUG
    EXPECT_ANY_THROW( m.row(0) );
    EXPECT_ANY_THROW( m.row(3) );

#else
      EXPECT_NO_THROW( m.row(0) );
      EXPECT_NO_THROW( m.row(3) );
#endif
    
}
