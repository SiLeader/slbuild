TARGET	= slbuild.elf

CC		= clang
CXX		= clang++
LINK	= ld
AR		= ar

CXXFLAG	= -std=c++11 -c
ARFLAG	= rcs

INC		= ../include
BIN		= ../../bin

.cpp.o:
	${CXX} -fopenmp ${CXXFLAG} -I${INC} $<

MAIN_CPP= main.cpp

OBJS=${MAIN_CPP:.cpp=.o}

all:
	make ${TARGET}
	
${TARGET}:${OBJS}
	#${AR} ${ARFLAG} ${BIN}/${TARGET} ${OBJS}
	${LINK} ${BIN}/${TARGET} ${OBJS} ${BIN}/libback.a 
	
clean:
	-${RM} -f *.~ *.lo *.o make.log *.bak .a.out .core .*.core *.elf *~
