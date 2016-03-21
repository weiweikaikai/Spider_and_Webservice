PWD=$(shell pwd)
CGI_PATH=$(PWD)/cgi_bin
SER_BIN=httpd
CLI_BIN=client
SER_SRC=httpd.c  
CLI_SRC=client.c
INCLUDE=.
CC=gcc
FLAGS=-o
LDFLAGS=-lpthread#-static
LIB=

.PHONY:all
all:$(SER_BIN) $(CLI_BIN) cgi

$(SER_BIN):$(SER_SRC)
	@$(CC) $(FLAGS) $@ $^ $(LDFLAGS) $(INCLUDE)
$(CLI_BIN):$(CLI_SRC)
	@$(CC) $(FLAGS) $@ $^ $(LDFLAGS) $(INCLUDE)

.PHONY:cgi
cgi:
	@for name in `echo $(CGI_PATH)`;\
	do\
		cd $$name;\
		make;\
		cd -;\
	done

.PHONY:clean
clean:
	@rm -rf $(SER_BIN) $(CLI_BIN) 
	@for name in `echo $(CGI_PATH)`;\
	do\
		cd $$name;\
		make clean;\
		cd -;\
	done







