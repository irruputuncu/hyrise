#ifndef SRC_BIN_UNITS_STORAGE_HELPER_H_
#define SRC_BIN_UNITS_STORAGE_HELPER_H_

#include <gtest/gtest.h>
#include <storage/storage_types.h>
#include <storage/Table.h>
#include <storage/HashTable.h>
#include <storage/GroupValue.h>
#include <algorithm>

template <typename HT>
::testing::AssertionResult AssertHashTableFully(AbstractTable::SharedTablePtr table,
    const field_list_t &columns) {
  HT ht(table, columns);
  if (testHashTableFullCoverage(ht, table, columns)) {
    return ::testing::AssertionSuccess();
  } else {
    return ::testing::AssertionFailure() <<
           "The HashTable did not map the table correctly!";
  }
}

template <typename HT>
bool testHashTableFullCoverage(const HT &hashTable,
                               AbstractTable::SharedTablePtr table,
                               const field_list_t &columns) {
  bool result = true;
  for (pos_t row = 0; row < table->size(); ++row) {
    pos_list_t positions = hashTable.get(table, columns, row);
    if (positions.empty()) {
      result = false;
      break;
    }
  }
  return result;
}
#endif  // SRC_BIN_UNITS_STORAGE_HELPER_H_

