#ifndef SRC_BIN_UNITS_STORAGE_TABLE_EQUAL_TEST_H
#define SRC_BIN_UNITS_STORAGE_TABLE_EQUAL_TEST_H

#include "gtest/gtest.h"
#include "helper/types.h"

typedef const hyrise::storage::c_atable_ptr_t& tblptr;

/// Compare two relations (i.e. tables) for value equality
///
/// Compares relations whether they have equal contents. handles tables
/// from a relational standpoint, thus order is not important.
///
/// EXPECT_RELATION_[N]EQ compares from a relational standpoint, thus order of
/// rows and the order of fields is not checked
/// EXPECT_SORTED_RELATION_[N]EQ also considers the order of the rows.
///
/// Use via: EXPECT_RELATION_EQ(result, reference);
/// or: EXPECT_SORTED_RELATION_EQ(result, reference);
///
/// @param[in] left_exp Left expression string
/// @param[in] right_exp Right expression string
/// @param[in] left Table to compare
/// @param[in] right Table to compare
::testing::AssertionResult RelationEquals(const char *left_exp,
                                          const char *right_exp,
                                          tblptr left,
                                          tblptr right);

::testing::AssertionResult RelationNotEquals(const char *left_exp,
                                             const char *right_exp,
                                             tblptr left,
                                             tblptr right);

#define EXPECT_RELATION_EQ(a,b) EXPECT_PRED_FORMAT2(RelationEquals, a, b)
#define EXPECT_RELATION_NEQ(a,b) EXPECT_PRED_FORMAT2(RelationNotEquals, a, b)

::testing::AssertionResult SortedRelationEquals(const char *left_exp,
                                          const char *right_exp,
                                          tblptr left,
                                          tblptr right);

::testing::AssertionResult SortedRelationNotEquals(const char *left_exp,
                                             const char *right_exp,
                                             tblptr left,
                                             tblptr right);

#define EXPECT_SORTED_RELATION_EQ EXPECT_PRED_FORMAT2(SortedRelationEquals, a, b)
#define EXPECT_SORTED_RELATION_NEQ EXPECT_PRED_FORMAT2(SortedRelationEquals, a, b)

#endif //SRC_BIN_UNITS_STORAGE_TABLE_EQUAL_TEST_H
