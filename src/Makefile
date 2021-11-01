
.DEFAULT_GOAL := run

server:
	@echo "Running DBMS server"
	gcc servidor.c -o servidor.out && ./servidor.out
	@echo "Cleaning"
	rm servidor.out

client: 
	@echo "Running DBMS client"
	gcc cliente.c -o cliente.out && ./cliente.out
	@echo "Cleaning"
	rm cliente.out
