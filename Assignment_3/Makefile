#
# Skeleton code for use with Computer Architecture 2022 assignment 3,
# LIACS, Leiden University.
#

CC = gcc
CXX = g++

# Do not touch the "-f" options, these are here to help you not being
# misled by the compiler.
FLAGS = -O3 -g -Wall -Isupport \
	-fno-tree-vectorize -fno-unroll-loops -fno-inline
CFLAGS = $(FLAGS) -std=gnu99
CXXFLAGS = $(FLAGS) -std=c++17
LDFLAGS = -lm
PNGFLAGS = `pkg-config --cflags --libs libpng`

# Comment these lines to disable the timing code. (macOS does not
# provide clock_gettime().
CFLAGS += -DENABLE_TIMING
CXXFLAGS += -DENABLE_TIMING
LDFLAGS += -lrt


# Register additional targets here
TARGETS = \
		matrixmul-r1-n512	\
		matrixmul-r1-n512-b16  \
		matrixmul-r1-n512-b32  \
		matrixmul-r1-n512-b64  \
		matrixmul-r1-n512-b128  \
		matrixmul-r50-n512  \
		matrixmul-r50-n512-b4  \
		matrixmul-r50-n512-b16  \
		matrixmul-r50-n512-b32  \
		matrixmul-r50-n512-b64  \
		matrixmul-r50-n512-b128  \
		grayscale		\
		grayscaleLoopInterchange\
		tilecomposite		\
		postcode


all:		$(TARGETS)

# Define a target for matrixmul, 1 repeat, N=512 matrix size
matrixmul-r1-n512:	matrixmul.c support/timing.c
			$(CC) $(CFLAGS) -DN=512 -DN_REPEAT=1 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=512 matrix size, BLOCK=16 block size
matrixmul-r1-n512-b16:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=512 -DBLOCK=16 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=512 matrix size, BLOCK=32 block size
matrixmul-r1-n512-b32:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=512 -DBLOCK=32 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=512 matrix size, BLOCK=64 block size
matrixmul-r1-n512-b64:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=512 -DBLOCK=64 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=512 matrix size, BLOCK=128 block size
matrixmul-r1-n512-b128:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=512 -DBLOCK=128 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 50 repeat, N=512 matrix size
matrixmul-r50-n512:	matrixmul.c support/timing.c
			$(CC) $(CFLAGS) -DN=512 -DN_REPEAT=50 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=512 matrix size, BLOCK=4 block size
matrixmul-r50-n512-b4:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=50 -DN=512 -DBLOCK=4 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=512 matrix size, BLOCK=16 block size
matrixmul-r50-n512-b16:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=50 -DN=512 -DBLOCK=16 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=512 matrix size, BLOCK=32 block size
matrixmul-r50-n512-b32:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=50 -DN=512 -DBLOCK=32 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=512 matrix size, BLOCK=64 block size
matrixmul-r50-n512-b64:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=50 -DN=512 -DBLOCK=64 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=512 matrix size, BLOCK=128 block size
matrixmul-r50-n512-b128:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=50 -DN=512 -DBLOCK=128 -o $@ $^ $(LDFLAGS)


# TODO: define more targets here for your experiments.
# In this case, you also want to include a compiler flag to define the
# block size, e.g. -DBLOCK=32.
# Don't forget to add these targets to TARGETS above.



postcode:	postcode.cpp support/timing.c support/postcode.cpp
		$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)


# Common target for the test programs based on images
%:		%.c support/image.c support/timing.c
		$(CC) $(CFLAGS) -o $@ $^ $(PNGFLAGS) $(LDFLAGS)

clean:
		rm -f $(TARGETS)
