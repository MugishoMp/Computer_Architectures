The testdata/ directory that can be found here contains reference output for
levels 0, 1, 2, 3 and 4 (that is, all levels without pipelining). You can
automatically run the programs and compare to the reference output by
running the following command from the "rv64-emu" directory:

./test_output.py -C path/to/lab2-test-programs-2022


For the reference output, the following assumptions apply:

- "bytes read" includes memory reads for instruction fetch.
- The emulator terminates as soon as the "l.sw 0(r3),r11" instruction
  reaches and completes the memory stage. This means that this final "l.sw"
  instruction is issued but not completed (it does not reach write back) and
  this is reflected in the instruction counts.
- For levels 0 to 3 delay slots did not have to be considered. Our reference
  implementation simply executes the instruction in the delay slot in this
  case after returning from the jump or when the branch is not taken.

We did not include reference output for pipelined execution because the
instruction counts and memory bytes may differ due to intricate differences
in implementation. However, the register state at program termination should
be equivalent if the test programs are executed with pipelining enabled.
