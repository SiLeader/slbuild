TARGET	= slbuild.elf

LINKER	= lld

BIN		= ../bin

FRONT	= libfront.a
BACK	= libback.a

all:
	cd backend; make all
	cd frontend; make all
	
	${LINKER} -o ${BIN}/${TARGET} ${BIN}/${FRONT} ${BIN}/${BACK}
	
clean:
	cd backend; make clean
	cd frontend; make clean
	
