TARGET	= slbuild.elf

CXX		= clang++
LINK	= ${CXX} #/usr/bin/ld

CXXFLAG	= -std=c++11 -O2

BIN		= ../bin

.cpp.o:
	${CXX} -fopenmp ${CXXFLAG} -c $<

MAIN_CPP= main.cpp
LOAD_CPP= loader.cpp
UTIL_CPP= utility.cpp

OBJS=${MAIN_CPP:.cpp=.o} ${LOAD_CPP:.cpp=.o} ${UTIL_CPP:.cpp=.o}

all:
	#${CXX} -fopenmp ${CXXFLAG} -o ${BIN}/${TARGET} ${MAIN_CPP} ${LOAD_CPP} ${UTIL_CPP} -lboost_system -lboost_filesystem -lboost_thread
	make ${TARGET} -j3

${TARGET}:${OBJS}
	${LINK} -o ${BIN}/${TARGET} ${OBJS} -lc++ -lboost_system -lboost_filesystem -lboost_thread

clean:
	-${RM} -f *.~ *.lo *.o make.log *.bak .a.out .core .*.core *.elf *~
