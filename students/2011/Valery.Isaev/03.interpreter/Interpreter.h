#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_

#include "mathvm.h"

class Interpreter: public mathvm::Code {
    typedef union {
        int64_t vInt;
        double vDouble;
        const char* vStr;
    } Value;
    typedef union {
        int16_t* pJmp;
        uint16_t* pVar;
        uint8_t* pInsn;
        int64_t* pInt;
        double* pDouble;
    } CodePtr;
    typedef struct {
        CodePtr code_ptr;
        Value* vars_ptr;
        Value* stack_ptr;
    } StackEntry;
    typedef uint16_t VarInt;
    Value* Stack;
    StackEntry* CallStack;
public:
    Interpreter();
    ~Interpreter();
    mathvm::Status* execute(std::vector<mathvm::Var*>& vars);
};

#endif