src=$(wildcard *.c)
target=$(patsubst %.c,%,$(src))

ALL:$(target)

%:%.c
	gcc $< -o $@ -g -Wall -pthread

clean:
	-rm -rf $(target)

.PHONY: clean ALL
