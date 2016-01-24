TARGET	= slbuild.elf

CXX		= clang++
LINK	= ${CXX} #/usr/bin/ld

CXXFLAG	= -std=c++11 -O2

BIN		= ../bin

.cpp.o:
	${CXX} -fopenmp=libomp ${CXXFLAG} -c $<

MAIN_CPP=	main.cpp
LOAD_CPP=	loader.cpp
UTIL_CPP=	utility.cpp
CMD_CPP=		commands.cpp
BUILD_CPP=	build.cpp

OBJS=${MAIN_CPP:.cpp=.o} ${LOAD_CPP:.cpp=.o} ${UTIL_CPP:.cpp=.o} ${CMD_CPP:.cpp=.o} ${BUILD_CPP:.cpp=.o}

all:
	make ${TARGET} -j3

${TARGET}:${OBJS}
	${LINK} -o ${BIN}/${TARGET} ${OBJS} -lc++ -lboost_system -lboost_filesystem

clean:
	-${RM} -f *.~ *.lo *.o make.log *.bak .a.out .core .*.core *.elf *~
