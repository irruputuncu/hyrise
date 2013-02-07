#ifndef SRC_LIB_ACCESS_EXPRESSIONSCAN_H_
#define SRC_LIB_ACCESS_EXPRESSIONSCAN_H_

#include "access/PlanOperation.h"

namespace hyrise {
namespace access {

class ColumnExpression {
public:
  explicit ColumnExpression(AbstractTable::SharedTablePtr t);
  virtual ~ColumnExpression();

  virtual void setResult(AbstractTable::SharedTablePtr result,
                         const field_t column,
                         const size_t row) const = 0;
  virtual std::string getName() const = 0;
  virtual DataType getType() const = 0;

protected:
  AbstractTable::SharedTablePtr _table;
};

class AddExp : public ColumnExpression {
public:
  AddExp(AbstractTable::SharedTablePtr t,
         const field_t field1,
         const field_t field2);
  virtual ~AddExp();

  virtual void setResult(AbstractTable::SharedTablePtr result,
                         const field_t column,
                         const size_t row) const;
  virtual std::string getName() const;
  virtual DataType getType() const;

protected:
  field_t _field1;
  field_t _field2;
};

class ExpressionScan : public _PlanOperation {
public:
  ExpressionScan();
  virtual ~ExpressionScan();

  virtual void setExpression(std::string name,
                             ColumnExpression *expression);
  virtual void executePlanOperation();
  const std::string vname();

private:
  ColumnExpression *_expression;
  std::string _column_name;
};

}
}

#endif  // SRC_LIB_ACCESS_EXPRESSIONSCAN_H_
