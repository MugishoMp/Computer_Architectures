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
		grayscale		\
		grayscaleLoopInterchange\
		tilecomposite		\
		tilecompositeOptimized \
		tilecompositeOptimized2 \
		postcode   \
		# matrixmul-r1-n512-b0	\
		# matrixmul-r1-n512-b4  \
		# matrixmul-r1-n512-b8  \
		# matrixmul-r1-n512-b16  \
		# matrixmul-r1-n512-b32  \
		# matrixmul-r1-n512-b64  \
		# matrixmul-r1-n512-b128  \
		# matrixmul-r1-n512-b192	 \
		# matrixmul-r1-n512-b224	 \
		# matrixmul-r1-n512-b240  \
		# matrixmul-r1-n512-b248  \
		# matrixmul-r1-n512-b256  \
		# matrixmul-r1-n1024-b0	\
		# matrixmul-r1-n1024-b8  \
		# matrixmul-r1-n1024-b16  \
		# matrixmul-r1-n1024-b32  \
		# matrixmul-r1-n1024-b64  \
		# matrixmul-r1-n1024-b128  \
		# matrixmul-r1-n1024-b256  \
		# matrixmul-r1-n1024-b384	 \
		# matrixmul-r1-n1024-b448	 \
		# matrixmul-r1-n1024-b480  \
		# matrixmul-r1-n1024-b496  \
		# matrixmul-r1-n1024-b512  \
		# matrixmul-r1-n2048-b0	\
		# matrixmul-r1-n2048-b32  \
		# matrixmul-r1-n2048-b64  \
		# matrixmul-r1-n2048-b128  \
		# matrixmul-r1-n2048-b256  \
		# matrixmul-r1-n2048-b512  \
		# matrixmul-r1-n2048-b768	 \
		# matrixmul-r1-n2048-b896	 \
		# matrixmul-r1-n2048-b960  \
		# matrixmul-r1-n2048-b992  \
		# matrixmul-r1-n2048-b1024  \


all:		$(TARGETS)

# Define a target for matrixmul, 1 repeat, N=512 matrix size
# b=0 meaning this version doesnt use loop blocks
matrixmul-r1-n512-b0:	matrixmul.c support/timing.c
			$(CC) $(CFLAGS) -DN=512 -DN_REPEAT=1 -o $@ $^ $(LDFLAGS)


# TODO: define more targets here for your experiments.
# In this case, you also want to include a compiler flag to define the
# block size, e.g. -DBLOCK=32.
# Don't forget to add these targets to TARGETS above.
############################### MATRIX SIZE 512 ###############################

# Define a target for matrixmul, 1 repeat, N=512 matrix size, BLOCK=4 block size
matrixmul-r1-n512-b4:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=512 -DBLOCK=4 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=512 matrix size, BLOCK=8 block size
matrixmul-r1-n512-b8:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=512 -DBLOCK=8 -o $@ $^ $(LDFLAGS)

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

# Define a target for matrixmul, 1 repeat, N=512 matrix size, BLOCK=192 block size
matrixmul-r1-n512-b192:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=512 -DBLOCK=192 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=512 matrix size, BLOCK=224 block size
matrixmul-r1-n512-b224:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=512 -DBLOCK=224 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=512 matrix size, BLOCK=240 block size
matrixmul-r1-n512-b240:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=512 -DBLOCK=240 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=512 matrix size, BLOCK=248 block size
matrixmul-r1-n512-b248:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=512 -DBLOCK=248 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=512 matrix size, BLOCK=256 block size
matrixmul-r1-n512-b256:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=512 -DBLOCK=256 -o $@ $^ $(LDFLAGS)




############################### MATRIX SIZE 1024 ###############################

# Define a target for matrixmul, 1 repeat, N=1024 matrix size
# b=0 meaning this version doesnt use loop blocks
matrixmul-r1-n1024-b0:	matrixmul.c support/timing.c
			$(CC) $(CFLAGS) -DN=1024 -DN_REPEAT=1 -o $@ $^ $(LDFLAGS)


# Define a target for matrixmul, 1 repeat, N=1024 matrix size, BLOCK=8 block size
matrixmul-r1-n1024-b8:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=1024 -DBLOCK=8 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=1024 matrix size, BLOCK=16 block size
matrixmul-r1-n1024-b16:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=1024 -DBLOCK=16 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=1024 matrix size, BLOCK=32 block size
matrixmul-r1-n1024-b32:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=1024 -DBLOCK=32 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=1024 matrix size, BLOCK=64 block size
matrixmul-r1-n1024-b64:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=1024 -DBLOCK=64 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=1024 matrix size, BLOCK=128 block size
matrixmul-r1-n1024-b128:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=1024 -DBLOCK=128 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=1024 matrix size, BLOCK=256 block size
matrixmul-r1-n1024-b256:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=1024 -DBLOCK=256 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=1024 matrix size, BLOCK=384 block size
matrixmul-r1-n1024-b384:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=1024 -DBLOCK=384 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=1024 matrix size, BLOCK=448 block size
matrixmul-r1-n1024-b448:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=1024 -DBLOCK=448 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=1024 matrix size, BLOCK=480 block size
matrixmul-r1-n1024-b480:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=1024 -DBLOCK=480 -o $@ $^ $(LDFLAGS)
# Define a target for matrixmul, 1 repeat, N=1024 matrix size, BLOCK=496 block size
matrixmul-r1-n1024-b496:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=1024 -DBLOCK=496 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=1024 matrix size, BLOCK=512 block size
matrixmul-r1-n1024-b512:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=1024 -DBLOCK=512 -o $@ $^ $(LDFLAGS)




############################### MATRIX SIZE 2048 ###############################

# Define a target for matrixmul, 1 repeat, N=2048 matrix size
# b=0 meaning this version doesnt use loop blocks
matrixmul-r1-n2048-b0:	matrixmul.c support/timing.c
			$(CC) $(CFLAGS) -DN=2048 -DN_REPEAT=1 -o $@ $^ $(LDFLAGS)


# Define a target for matrixmul, 1 repeat, N=2048 matrix size, BLOCK=16 block size
matrixmul-r1-n2048-b16:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=2048 -DBLOCK=16 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=2048 matrix size, BLOCK=32 block size
matrixmul-r1-n2048-b32:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=2048 -DBLOCK=32 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=2048 matrix size, BLOCK=64 block size
matrixmul-r1-n2048-b64:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=2048 -DBLOCK=64 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=2048 matrix size, BLOCK=128 block size
matrixmul-r1-n2048-b128:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=2048 -DBLOCK=128 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=2048 matrix size, BLOCK=256 block size
matrixmul-r1-n2048-b256:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=2048 -DBLOCK=256 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=2048 matrix size, BLOCK=512 block size
matrixmul-r1-n2048-b512:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=2048 -DBLOCK=512 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=2048 matrix size, BLOCK=768 block size
matrixmul-r1-n2048-b768:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=2048 -DBLOCK=768 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=2048 matrix size, BLOCK=896 block size
matrixmul-r1-n2048-b896:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=2048 -DBLOCK=896 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=2048 matrix size, BLOCK=960 block size
matrixmul-r1-n2048-b960:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=2048 -DBLOCK=960 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=2048 matrix size, BLOCK=992 block size
matrixmul-r1-n2048-b992:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=2048 -DBLOCK=992 -o $@ $^ $(LDFLAGS)

# Define a target for matrixmul, 1 repeat, N=2048 matrix size, BLOCK=1024 block size
matrixmul-r1-n2048-b1024:	matrixmulLoopBlocking.c support/timing.c
			$(CC) $(CFLAGS) -DN_REPEAT=1 -DN=2048 -DBLOCK=1024 -o $@ $^ $(LDFLAGS)


postcode:	postcode.cpp support/timing.c support/postcode.cpp
		$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)


# Common target for the test programs based on images
%:		%.c support/image.c support/timing.c
		$(CC) $(CFLAGS) -o $@ $^ $(PNGFLAGS) $(LDFLAGS)

clean:
		rm -f $(TARGETS)
