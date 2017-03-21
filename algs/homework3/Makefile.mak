PROGRAM=PROG
BINDIR = bin
SRC = src
OBJ = obj

CC     = g++
CLINK  = $(CC)
C_LIB  = -lm
CFLAGS = -Wall -O3 
CLINKFLAGS= -O3 

OBJS = ${OBJ}/main.o \

${BINDIR}/${PROGRAM}: ${OBJS}
	${CLINK} ${CLINKFLAGS} -o ${BINDIR}/${PROGRAM} ${OBJS} ${C_LIB}

${OBJ}/main.o: ${SRC}/main.cpp
	$(CC) $(CFLAGS) -c ${SRC}/main.cpp -o ${OBJ}/main.o


clean:
	rm -f ${OBJ}/*.o
cleanall:
	rm -f ${OBJ}/*.o ${BINDIR}/${PROGRAM}