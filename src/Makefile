
.DEFAULT_GOAL := run

server:
	@echo "Running DBMS server"
	gcc server.c -o server.out && ./server.out
	@echo "Cleaning"
	rm server.out

client: 
	@echo "Running DBMS client"
	gcc client.c -o client.out && ./client.out
	@echo "Cleaning"
	rm client.out
