
CC 		:= npx tsc
SRCS 	:= $(wildcard *.ts)
BIN  	:= *.js
USE 	:= index.js 


all : clean ${BIN}

debug : clean ${OBJ}
	${CC} ${WARN} ${FLAG} -o ${BIN} ${SRCS}

${BIN}: ${SRCS}
	${CC}  $^


clean :
	rm -f ${BIN}

use : clean ${BIN}
	node ${USE}

index : clean 
	${CC} index.ts && node ${USE}