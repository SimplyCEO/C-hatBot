ifndef CC
	CC := clang
endif

ifndef CFLAGS
	CFLAGS := --std=c89 -g -Wall
endif

HEADERS := -I include/
LIBRARIES :=

FILES := src/main.c

katherineai:
	${CC} ${CFLAGS} ${HEADERS} ${LIBRARIES} ${FILES} -o katherineai

clean:
	@rm katherineai || true
