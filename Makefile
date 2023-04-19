ifndef CC
	CC := clang
endif

ifndef CFLAGS
	CFLAGS := --std=c99 -g -Wall
endif

HEADERS := -I include/
LIBRARIES := -lcurl
FILES := src/main.c \
				 src/api.c \
				 src/tools.c
BINARY := c-hatbot

katherineai:
	${CC} ${CFLAGS} ${HEADERS} ${LIBRARIES} ${FILES} -o ${BINARY}

clean:
	@rm ${BINARY} || true

