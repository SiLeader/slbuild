TARGET	= libfront.a

CC		= clang
CXX		= clang++
LINK	= lld
AR		= ar

CXXFLAG	= -std=c++14 -c
ARFLAG	= rcs

INC		= ../include
BIN		= ../../bin

.cpp.o:
	${CXX} ${CXXFLAG} -I${INC} $<

MAIN_CPP= main.cpp

OBJS=${MAIN_CPP:.cpp=.o}

all:
	make ${TARGET}
	
${TARGET}:${OBJS}
	${AR} ${ARFLAG} ${BIN}/${TARGET} ${OBJS}
	
clean:
	-${RM} -f *.~ *.lo *.o make.log *.bak .a.out .core .*.core *.elf *~
