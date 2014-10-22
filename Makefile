NAME    := emirps
BIN_DIR := /usr/local/bin

all: build

build: $(NAME).c
	gcc -o $(NAME) $< -lm

test:
	@curl --silent -o oeis.txt "http://oeis.org/search?q=id:A006567&fmt=text"
	@cat /dev/null > test.txt
	@grep "%S A006567" oeis.txt | sed "s/%S A006567 //" >> test.txt
	@grep "%T A006567" oeis.txt | sed "s/%T A006567 //" >> test.txt
	@grep "%U A006567" oeis.txt | sed "s/%U A006567 //" >> test.txt
	@cat test.txt | tr -d '\n' > test2.txt
	@cat test2.txt | tr ',' '\n' > test.txt
	@echo "" >> test.txt
	@./$(NAME) 1193 > test2.txt
	@diff test.txt test2.txt
	@cat test.txt
	@echo "Passed test of emirps from 13 - 1193"
	@rm -f test*.txt

install:
	install -m 0755 $(NAME) $(BIN_DIR)

uninstall:
	rm -f $(BIN_DIR)/$(NAME)

clean:
	rm -f $(NAME) test*.txt