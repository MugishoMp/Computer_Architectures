/* rv64-emu -- Simple 64-bit RISC-V simulator
 *
 *    inst-decoder.h - RISC-V instruction decoder.
 *
 * Copyright (C) 2016,2019  Leiden University, The Netherlands.
 */

#ifndef __INST_DECODER_H__
#define __INST_DECODER_H__

#include "reg-file.h"

#include <stdexcept>
#include <cstdint>
#include <string>
#include <bitset>

static const int INSTRUCTION_SIZE = 4;

enum Type {
    R, I, S, SH, J, F, NOP, NONE, CUST4, JUMP, SF, BF
};

/* TODO: add enums and constants necessary for your instruction decoder. */


/* Exception that should be thrown when an illegal instruction
 * is encountered.
 */
class IllegalInstruction : public std::runtime_error
{
  public:
    explicit IllegalInstruction(const std::string &what)
      : std::runtime_error(what)
    { }

    explicit IllegalInstruction(const char *what)
      : std::runtime_error(what)
    { }
};


/* InstructionDecoder component to be used by class Processor */
class InstructionDecoder
{
  
  /*
  enum OpCode_R {
    H=0b001010, 
    010001, 010011 //Jump register/Jump and Link register
  };
  enum OpCode_I {
    010011, //l.maci, I or F?
    011010, 011011,
    100000, 100001, 100010, 100011,
    100100, 100101, 100110, 100111,
    101000, 101011, 101100, 
  }; //101001, 101010, 101101, DAK not DAI?
  enum OpCode_SH {
    101110 //00, 01, 10, 11 op2
  };
  enum OpCode_F {
    10111100000, 10111100001, 10111100010,
    10111100011, 10111100100, 10111100101,
    10111101010, 10111101011, 10111101100,
    10111101101, 
  };
  enum OpCode_S {
    110001, //0001, 0011, 0010, 0100
    110010, //00001000, 00001001, 00001010, 00001011, 00001100, 00001101
    //OO00011000, ...,  idk man
  }; */
  public:
    void                setInstructionWord(const uint32_t instructionWord);
    uint32_t            getInstructionWord() const;

    RegNumber           getA() const;
    RegNumber           getB() const;
    RegNumber           getD() const;
    RegNumber           getOp() const;
    RegNumber           getOp2() const;
    RegNumber           getOp3() const;
    RegNumber           getImm(Type type) const;
    RegNumber           getRes() const;
    RegNumber           getImmI() const;
    uint32_t            getFunc() const;
    
    uint32_t            convertToBinary() const;
    void                split() const;
    void                printBinary(uint32_t word) const;
    Type                getType(uint32_t word) const;
    void                StringRepresentation() const;
    void                getOp3String() const;
    void                getOp2String() const;
    void                getFlagString() const;

    /* TODO: probably want methods to get opcode, function code */

    /* TODO: need a method to obtain the immediate */

  private:
    uint32_t instructionWord;
    mutable uint32_t rD;
    mutable uint32_t rA;
    mutable uint32_t rB;
    mutable uint32_t IValue;
    mutable uint32_t immIValue;
    std::string instructionString;
};

std::ostream &operator<<(std::ostream &os, const InstructionDecoder &decoder);

#endif /* __INST_DECODER_H__ */
