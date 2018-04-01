% Prolog program to implement two predicates evenlength(List) and oddlength(List) so
% that they are true if their argument is a list of even or odd length respectively

odd_length([_|T]) :- even_length(T).			% ignoring head and checking if tail is odd; meaning list is even

even_length([]).					% base case when list is empty; it is even
even_length([_|T]) :- odd_length(T).			% ignoring head and checking if tail is even; meaning list is odd

go :-   write('Enter the list : '),
	read(L),nl,					% reading list
	odd_length(L).
