odd_length([_|T]) :- even_length(T).

even_length([]).
even_length([_|T]) :- odd_length(T).

go :-   write('Enter the list : '),
	read(L),nl,
	odd_length(L).
