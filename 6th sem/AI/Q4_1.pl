% program in PROLOG to implement generate_fib(N,T) to give fibonacci series.

for(N,N) :- fibo(N,R), write(R).			% for loop
for(I,N) :- fibo(I,R), write(R), write(' '), I1 is I+1, for(I1, N),!.

fibo(0,R):- R is 0.
fibo(1,R):- R is 1.
fibo(N,R):- N1 is N-1, N2 is N-2, fibo(N1,R1), fibo(N2,R2), R is R1+R2, !.

go :-   write('Enter number : '),
	read(N),nl,					% reading number
	for(1,N).
