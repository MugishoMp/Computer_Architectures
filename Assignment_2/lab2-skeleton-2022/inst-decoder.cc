/* rv64-emu -- Simple 64-bit RISC-V simulator
 *
 *    inst-decoder.cc - RISC-V instruction decoder.
 *
 * Copyright (C) 2016,2019  Leiden University, The Netherlands.
 *
 */

#include "inst-decoder.h"

#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <bitset>

/*
 * Class InstructionDecoder -- helper class for getting specific
 * information from the decoded instruction.
 */

void
InstructionDecoder::setInstructionWord(const uint32_t instructionWord)
{
  this->instructionWord = instructionWord;
}

uint32_t
InstructionDecoder::getInstructionWord() const
{
  return instructionWord;
}

RegNumber
InstructionDecoder::getA() const
{
  /* TODO: implement */
  uint32_t a = instructionWord;
  uint32_t op = instructionWord;
  op = op >> 26;
  Type type = getType(op);
  a = a << 11;
  a = a >> 27;
  rA = a;

  std::cout << "A: " << std::endl;
  printBinary(a);
  std::cout << std::endl;

  switch(type) {
    case R:
    case S:
      getB();
      break;
    case I:
    case F:
      getImm(type);
      break;
    case SH:
      break;
  }


  return 0;  /* result undefined */
}

RegNumber
InstructionDecoder::getB() const
{
  /* TODO: implement */
  uint32_t b = instructionWord;
  uint32_t op = instructionWord;
  op = op >> 26;
  Type type = getType(op);
  b = b << 16;
  b = b >> 27;
  rB = b;

  std::cout << "B: " << std::endl;
  printBinary(b);
  std::cout << std::endl;

  switch(type) {
    case R:
      break;
    case S:
      getImm(S);
  }

  return 0;  /* result undefined */
}

RegNumber
InstructionDecoder::getD() const
{
  /* TODO: implement */
  uint32_t d = instructionWord;
  d = d << 6;
  d = d >> 27;
  rD = d;

  std::cout << "D: " << std::endl;
  printBinary(d);
  std::cout << std::endl;

  getA();

  return 0; /* result undefined */
}

RegNumber
InstructionDecoder::getImm(Type type) const
{
  uint32_t imm = instructionWord;

  switch(type) {
    case I:
    case F:
      imm = imm << 16;
      imm = imm >> 16;
      IValue = imm;
      break;
    case S:
      imm = imm << 21;
      imm = imm >> 21;
      IValue = imm;
      break;
    case J:
      imm = imm >> 6;
      imm = imm << 6;
      break;
  }
  std::cout << "Imm: " << std::endl;
  printBinary(imm);
  std::cout << std::endl;
  return 0;
}

RegNumber
InstructionDecoder::getImmI() const
{
  uint32_t immI = instructionWord;
  immI = immI << 6;
  immI = immI >> 27;

  std::cout << "ImmI: " << std::endl;
  printBinary(immI);
  std::cout << std::endl;
  getA();
  return 0;
}

/**
 * @brief Gets Op2 to differentiate between l.sll, l.srl and l.sra
 * 
 * @return RegNumber 
 */
RegNumber
InstructionDecoder::getOp2() const
{
  uint32_t op2 = instructionWord;
  op2 = op2 << 22;
  op2 = op2 >> 28;

  std::cout << "Op2: " << std::endl;
  printBinary(op2);
  std::cout << std::endl;

  switch(op2) { //todo 4bits sll srl sra?
    case 0:
      //l.sll rD, rA, rB
      std::cout << "l.sll r" << rD << ", r";
      std::cout << rA << ", r" << rB << std::endl;
      break;
    case 1:
      //l.srl rD, rA, rB
      std::cout << "l.srl r" << rD << ", r";
      std::cout << rA << ", r" << rB << std::endl;
      break;
    case 2:
      //l.sra rD, rA, rB
      std::cout << "l.sra r" << rD << ", r";
      std::cout << rA << ", r" << rB << std::endl;
      break;
    case 3:
      //l.ror rD, rA, rB Class II
      std::cout << "l.ror r" << rD << ", r";
      std::cout << rA << ", r" << rB << std::endl;
      break;
    default:
      throw IllegalInstruction("Illegal instruction exception");
      break;
  } //now that i look at the things, op2 might be useless...

  return 0;
}

RegNumber
InstructionDecoder::getOp3() const
{
  uint32_t op3 = instructionWord;
  op3 = op3 << 28;
  op3 = op3 >> 28;

  switch(op3) {
    case 0:
      //l.add rD, rA, rB
      std::cout << "l.add r" << rD << ", r";
      std::cout << rA << ", r" << rB << std::endl;
      break;
    case 1:
      //l.addc rD, rA, rB
      std::cout << "l.addc r" << rD << ", r";
      std::cout << rA << ", r" << rB << std::endl;
      break;
    case 2:
      //l.sub rD, rA, rB
      std::cout << "l.sub r" << rD << ", r";
      std::cout << rA << ", r" << rB << std::endl;
      break;
    case 3:
      //l.and rD, rA, rB
      std::cout << "l.and r" << rD << ", r";
      std::cout << rA << ", r" << rB << std::endl;
      break;
    case 4:
      //l.or rD, rA, rB
      std::cout << "l.or r" << rD << ", r";
      std::cout << rA << ", r" << rB << std::endl;
      break;
    case 5:
      //l.xor rD, rA, rB
      std::cout << "l.xor r" << rD << ", r";
      std::cout << rA << ", r" << rB << std::endl;
      break;
    case 6:
      //sll, srl, sra?
      getOp2();
      break;
    default:
      throw IllegalInstruction("Illegal instruction exception");
      break;
  }

  return 0;
}

RegNumber
InstructionDecoder::getOp() const
{
  /*
  std::string s = std::bitset<32>(instructionWord).to_string();
  s.substr(0, 6); //Size 6 except for F type
  */
  uint32_t op = instructionWord;
  op = op >> 26;
  std::cout << std::endl;
  std::cout << "Full word: " << std::endl;
  printBinary(instructionWord);
  std::cout << std::endl;
  std::cout << "Opcode: " << std::endl; 
  printBinary(op);
  std::cout << std::endl;

  Type type = getType(op);
  std::cout << "Type: " << type << std::endl;

  switch (type) {
    case R:
    case I:
    case SH:
      getD();
      break;
    case S:
      getImmI();
      break;
    case J:
    case F:
    case NOP:
      break;
    default:
      throw IllegalInstruction("Illegal instruction exception");
      break;
  }


  switch (op) {
    case 0x05: {
      NOP;
      std::cout << "l.nop" << std::endl;
      break;
    }
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
      //l.addi rD, rA, I
      std::cout << "l.addi r" << rD << ", r";
      std::cout << rA << ", $" << IValue << std::endl;
      break;
    case 0x28:
    case 0x29:
    case 0x2A:
    case 0x2B:
    case 0x2C:
    case 0x2D: {
      I;
      break;
    }
    case 0x38: {
      //can be a lot, need other opcodes
      //R;
      getOp3();
      break;
    }
    default:
      throw IllegalInstruction("Illegal instruction exception");
      break;
  }
  return 0; /* result undefined */
}

Type
InstructionDecoder::getType(uint32_t word) const{
  switch (word) {
    case 0x05: {
      return NOP;
      break;
    }
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2A:
    case 0x2B:
    case 0x2C:
    case 0x2D: {
      return I;
      break;
    }
    case 0x38: {
      return R;
      break;
    }
    default:
      throw IllegalInstruction("Illegal instruction exception");
      //return NONE;
      break;
  }
}

void
InstructionDecoder::split() const
{

}

void
InstructionDecoder::printBinary(uint32_t word) const{
  std::string s = std::bitset<32>(word).to_string();
  std::cout << "Opcode Hexa in Decimal " << word << std::endl;
  std::cout << "Binary: " << s << std::endl;
}

uint32_t
InstructionDecoder::convertToBinary() const
{
  std::string s = std::bitset<32>(instructionWord).to_string();
  //get binary representation as string

  std::cout << instructionWord << std::endl;
  std::cout << "hoi" << std::endl;
  std::cout << s << std::endl;

  //split(s);



  return 0; /* result undefined */
}
