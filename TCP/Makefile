all : socksC socksS

socksC : socksC.o
	gcc -Wall -g -o socksC socksC.o

socksS : socksS.o
	gcc -Wall -g -o socksS socksS.o
  
clean :
	rm *.o socksC socksS
