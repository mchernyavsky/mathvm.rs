#pragma once

#include <assert.h>

#include <vector>

#include "mathvm.h"

// ================================================================================

namespace mathvm {
  typedef std::vector<std::string> StringPool;

  class RTVar {
  public:
    RTVar() {
      _t = VT_INVALID;
    }

    RTVar(int i) {
      _t = VT_INT;
      _u.i = i;
    }

    RTVar(int64_t i) {
      _t = VT_INT;
      _u.i = i;
    }

    RTVar(double d) {
      _t = VT_DOUBLE;
      _u.d = d;
    }

    RTVar(char *s) {
      _t = VT_STRING;
      _u.s = s;
    }

    VarType type() const { return _t; }

    int64_t getInt() const {
      assert(_t == VT_INT);

      return _u.i;
    }

    double getDouble() const {
      assert(_t == VT_DOUBLE);

      return _u.d;
    }

    const char *getString() const {
      assert(_t == VT_STRING);

      return _u.s;
    }

  private:
    VarType _t;

    union {
      int64_t i;
      double  d;
      char*   s;
    } _u;
  };


  class BytecodeInterpreter : public Code {
  public:
    void setVarPoolSize(unsigned int);

    Status* execute(vector<Var*> vars);
    
    Bytecode *bytecode();
    StringPool *strings();
    
  private:
    std::vector<RTVar> var_pool;
    StringPool string_pool;
    Bytecode code;
  };
}