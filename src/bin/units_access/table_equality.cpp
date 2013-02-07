#include "testing/test.h"

#include "io/shortcuts.h"
#include "storage/AbstractTable.h"
#include "storage/TableEqualityTest.h"

class TableEqualityTests : public ::testing::Test {};

TEST_F(TableEqualityTests, test_equal) {
  auto
      t1 = Loader::shortcuts::load("test/tables/employees.tbl"),
      t2 = Loader::shortcuts::load("test/tables/employees.tbl");
  EXPECT_RELATION_EQ(t1, t2);
}

TEST_F(TableEqualityTests, test_not_equal) {
  auto
      t1 = Loader::shortcuts::load("test/tables/employees.tbl"),
      t2 = Loader::shortcuts::load("test/tables/employees_revised.tbl");
  EXPECT_RELATION_NEQ(t1, t2);
}
