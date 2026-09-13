src=$(wildcard *.c)
target=$(patsubst %.c,%,$(src))

ALL:$(target)

%.out:%.c 
	gcc $< -o $@

clean:
	-rm -rf $(target) 

.PHONY:clean ALL

