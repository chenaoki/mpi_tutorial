all:a.out

a.out:
	mpic++ test.c

clean:
	rm a.out

run:
	mpirun -np 8 a.out
