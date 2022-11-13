/* rv64-emu -- Simple 64-bit RISC-V simulator
 *
 *    stages.cc - Pipeline stages
 *
 * Copyright (C) 2016-2020  Leiden University, The Netherlands.
 */

#include "stages.h"

#include <iostream>

/*
 * Instruction fetch
 */

void
InstructionFetchStage::propagate()
{
  try
    {
      /* TODO: implement instruction fetch from instruction memory. */
      instructionMemory.setAddress(PC);
      instructionMemory.setSize(4);//4294967295); //4 bytes
      if_id.value = instructionMemory.getValue();

      /* Enable this once you have implemented instruction fetch. */
      if (if_id.value == TestEndMarker)
        throw TestEndMarkerEncountered(PC);
    }
  catch (TestEndMarkerEncountered &e)
    {
      throw;
    }
  catch (std::exception &e)
    {
      throw InstructionFetchFailure(PC);
    }
}

void
InstructionFetchStage::clockPulse()
{
  /* TODO: write necessary fields in pipeline register */
  if_id.PC = PC;
}

/*
 * Instruction decode
 */

void
dump_instruction(std::ostream &os, const uint32_t instructionWord,
                 const InstructionDecoder &decoder);

void
InstructionDecodeStage::propagate()
{
  ControlSignals cs;
  /* TODO: set instruction word on the instruction decoder */
  decoder.setInstructionWord(if_id.value);
  /* TODO: need a control signals class that generates control
   * signals from a given opcode and function code.
   */
  cs.setOp(decoder.getOp());
  cs.setFunc(decoder.getFunc());  

  PC = if_id.PC;


  /* debug mode: dump decoded instructions to cerr.
   * In case of no pipelining: always dump.
   * In case of pipelining: special case, if the PC == 0x0 (so on the
   * first cycle), don't dump an instruction. This avoids dumping a
   * dummy instruction on the first cycle when ID is effectively running
   * uninitialized.
   */
  if (debugMode && (! pipelining || (pipelining && PC != 0x0)))
    {
      /* Dump program counter & decoded instruction in debug mode */
      auto storeFlags(std::cerr.flags());

      std::cerr << std::hex << std::showbase << PC << "\t";
      std::cerr.setf(storeFlags);

      std::cerr << decoder << std::endl;
    }

  /* TODO: register fetch and other matters */
  /* TODO: perhaps also determine and write the new PC here? */
  regfile.setRS1(decoder.getA());
  regfile.setRS2(decoder.getB());
  RegValue RS1_value = regfile.getReadData1();
  RegValue RS2_value = regfile.getReadData2();
  PC += 4;
}

void InstructionDecodeStage::clockPulse()
{
  /* ignore the "instruction" in the first cycle. */
  if (! pipelining || (pipelining && PC != 0x0))
    ++nInstrIssued;

  /* TODO: write necessary fields in pipeline register */
  id_ex.PC = PC;
}

/*
 * Execute
 */

void
ExecuteStage::propagate()
{
  /* TODO configure ALU based on control signals and using inputs
   * from pipeline register.
   * Consider using the Mux class.
   */

  PC = id_ex.PC;
}

void
ExecuteStage::clockPulse()
{
  /* TODO: write necessary fields in pipeline register. This
   * includes the result (output) of the ALU. For memory-operations
   * the ALU computes the effective memory address.
   */

  ex_m.PC = PC;
}

/*
 * Memory
 */

void
MemoryStage::propagate()
{
  /* TODO: configure data memory based on control signals and using
   * inputs from pipeline register.
   */

  PC = ex_m.PC;
}

void
MemoryStage::clockPulse()
{
  /* TODO: pulse the data memory */

  /* TODO: write necessary fields in pipeline register */

  m_wb.PC = PC;
}

/*
 * Write back
 */

void
WriteBackStage::propagate()
{
  if (! pipelining || (pipelining && m_wb.PC != 0x0))
    ++nInstrCompleted;

  /* TODO: configure write lines of register file based on control
   * signals
   */
}

void
WriteBackStage::clockPulse()
{
  /* TODO: pulse the register file */
}
