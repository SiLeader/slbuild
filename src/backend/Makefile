TARGET	= libback.a

CC		= clang
CXX		= clang++
LINK	= lld
AR		= ar

CXXFLAG	= -std=c++11 -c
ARFLAG	= rcs

INC		= ../include
BIN		= ../../bin

.cpp.o:
	${CXX} ${CXXFLAG} -I${INC} $<

LOAD_CPP= loader.cpp
UTIL_CPP= utility.cpp

OBJS=${LOAD_CPP:.cpp=.o} ${UTIL_CPP:.cpp=.o}

all:
	make ${TARGET}
	
${TARGET}:${OBJS}
	${AR} ${ARFLAG} ${BIN}/${TARGET} ${OBJS}
	

clean:
	-${RM} -f *.~ *.lo *.o make.log *.bak .a.out .core .*.core *.elf *~
