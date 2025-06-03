/* Bagian I */
/* Deklarasi Fakta */
pria(panji).
pria(barok).
pria(qika).
pria(aqua).
pria(eriq).
pria(shelby).
pria(rifia).
pria(francesco).
pria(mauang).
pria(jamet).

wanita(frieren).
wanita(roxy).
wanita(mary).
wanita(myers).
wanita(ruby).
wanita(yennefer).
wanita(gizelle).
wanita(aihoshino).
wanita(suzy).
wanita(rhiannon).
wanita(eve).

usia(panji, 78).
usia(gizelle, 20).
usia(aihoshino, 32).
usia(barok, 75).
usia(qika, 55).
usia(aqua, 53).
usia(eriq, 50).
usia(shelby, 25).
usia(rifia, 35).
usia(francesco, 23).
usia(mauang, 15).
usia(jamet, 3).

usia(frieren, 75).
usia(roxy, 73).
usia(mary, 51).
usia(myers, 40).
usia(ruby, 48).
usia(yennefer, 30).
usia(suzy, 23).
usia(rhiannon, 5).
usia(eve, 10).

menikah(panji, frieren).
menikah(frieren, panji).
menikah(barok, roxy).
menikah(roxy, barok).
menikah(qika, mary).
menikah(mary, qika).
menikah(qika, myers).
menikah(myers, qika).
menikah(eriq, ruby).
menikah(ruby, eriq).
menikah(rifia, yennefer).
menikah(yennefer, rifia).
menikah(rifia, aihoshino).
menikah(aihoshino, rifia).
menikah(francesco, suzy).
menikah(suzy, francesco).

anak(qika, panji).
anak(qika, frieren).
anak(aqua, barok).
anak(aqua, roxy).
anak(ruby, barok).
anak(ruby, roxy).
anak(yennefer, qika).
anak(yennefer, mary).
anak(shelby, qika).
anak(shelby, mary).
anak(gizelle, qika).
anak(gizelle, myers).
anak(aihoshino, aqua).
anak(francesco, eriq).
anak(francesco, ruby).
anak(rhiannon, shelby).
anak(eve, yennefer).
anak(eve, rifia).
anak(mauang, rifia).
anak(mauang, aihoshino).
anak(jamet, francesco).
anak(jamet, suzy).

/* Deklarasi Rules */
saudara(X, Y):- 
	anak(X, Z),
	anak(Y, Z),
	X \= Y.

saudaratiri(X, Y):-
	anak(X, Z),
	anak(Y, Z),
	menikah(Z, W),
	anak(X, W),
	\+ anak(Y, W).

kakak(X, Y):-
	saudara(X, Y),
	usia(X, A), 
	usia(Y, B),
	A > B.

keponakan(X, Y):-
	anak(X, Z),
	saudara(Z, Y).

mertua(X, Y):-
	anak(Z, X),
	menikah(Z, Y).

nenek(X, Y):-
	anak(Y, Z),
	anak(Z, X),
	wanita(X).

keturunan(X, Y):-
	anak(X, Y).

keturunan(X, Y):-
	anak(X, Z),
	keturunan(Z, Y).

lajang(X):-
	pria(X),
	\+ menikah(X, _).

lajang(X):-
	wanita(X),
	\+ menikah(X, _).

anakbungsu(X):-
	anak(X, _),
	\+ kakak(X, _).

anaksulung(X):-
	anak(X, _),
	\+ kakak(_, X).

yatimpiatu(X):-
	wanita(X),
	\+ anak(X, Z).

yatimpiatu(X):-
	pria(X),
	\+ anak(X, Z).

/* Bagian II */
/* Deklarasi Rule */
exponent(_, 0, 1) :- !.
exponent(A, B, X):-
	A > 0,
	B >= 0,
	B1 is B - 1,
	exponent(A, B1, X1),
	X is A * X1.

antara(X, Y, Z):-
	Z = X.

antara(X, Y, Z):-
	X < Y,
	X1 is X + 1,
	antara(X1, Y, Z).

cekPrima(2):- !.
cekPrima(X):-
	X > 2,
	antara(2, X, Y),
	\+ (X mod Y =:= 0). 

growth(I, _, _, 0, I) :- 
	I > 0, 
	!.

growth(I, G, H, T, X):-
	T > 0,
	T1 is T - 1,
	growth(I, G, H, T1, X1),
	cekPrima(T), 
	X is X1 + G.

growth(I, G, H, T, X):-
	T > 0,
	T1 is T - 1,
	growth(I, G, H, T1, X1),
	\+ cekPrima(T), 
	X is X1 - H.

harvestFruits(N, Fruits, TreeNumber, FinalFruits):-
	TreeNumber > N,
	FinalFruits = Fruits,
	!.

harvestFruits(_, Fruits, _, 0):-
	Fruits =< 0,
	write('Si Imut pulang sambil menangis :('),
	nl,
	!.

harvestFruits(N, Fruits, TreeNumber, FinalFruits):-
    TreeNumber mod 3 =:= 0,
    NextTree is TreeNumber + 1,
    NewFruits is Fruits + 2, 
    harvestFruits(N, NewFruits, NextTree, FinalFruits), !.

harvestFruits(N, Fruits, TreeNumber, FinalFruits):-
    TreeNumber mod 4 =:= 0, 
    NextTree is TreeNumber + 1,
    NewFruits is Fruits - 5,  
    harvestFruits(N, NewFruits, NextTree, FinalFruits), !.

harvestFruits(N, Fruits, TreeNumber, FinalFruits):-
    TreeNumber mod 5 =:= 0,  
    NextTree is TreeNumber + 1,
    NewFruits is Fruits + 3, 
    harvestFruits(N, NewFruits, NextTree, FinalFruits), !.

harvestFruits(N, Fruits, TreeNumber, FinalFruits):-
    cekPrima(TreeNumber),  
    NextTree is TreeNumber + 1,
    NewFruits is Fruits - 10, 
    harvestFruits(N, NewFruits, NextTree, FinalFruits), !.

harvestFruits(N, Fruits, TreeNumber, FinalFruits):-
    NextTree is TreeNumber + 1,
    harvestFruits(N, Fruits, NextTree, FinalFruits), !.

fpb(X, 0, X) :- !.
fpb(X, Y, Z) :- 
	Y > 0,
	X1 is Y,
	Y1 is X mod Y,
	fpb(X1, Y1, Z).

kpk(X, Y, Z) :-
	X > 0,
	Y > 0,
	fpb(X, Y, F),
	Z is (X * Y) // F.

factorial(0, 1) :- !.
factorial(N, X) :-
	N > 0,
	N1 is N - 1,
	factorial(N1, X1),
	X is N * X1.

makePattern(N) :-
    between(1, N, Row),
    JarakPinggir is min(Row, N - Row + 1),
    between(1, N, Col),
    Nilai is min(JarakPinggir, min(Col, N - Col + 1)),
    write(Nilai),
	Col =:= N,
	nl,
    fail.

makePattern2(N) :-
	between(1, N, Row),
	JarakPinggir is min(Row, N - Row + 1),
	between(1, N, Col),
	Nilai is min(JarakPinggir, min(Col, N - Col + 1)),
	write(Nilai),
	\+ Col =:= N,
	write(' '),
	fail.

/* BAGIAN III */

min([X], X).
min([H|T], Min) :-
    min(T, TMin),
    (H =< TMin, Min = H; H > TMin, Min = TMin).

max([X], X).
max([H|T], Max) :-
    max(T, TMax),
    (H >= TMax, Max = H; H < TMax, Max = TMax).

range(List, Range) :-
    min(List, Min),
    max(List, Max),
    Range is Max - Min.

count([], 0).
count([_|T], Count) :-
    count(T, TCount),
    Count is TCount + 1.

sum([], 0).
sum([H|T], Sum) :-
    sum(T, TSum),
    Sum is H + TSum.

mergeSort([], [], []).
mergeSort(List, [], List).
mergeSort([], List, List).
mergeSort([HeadA|TailA], [HeadB|TailB], [HeadA|Result]) :- 
	HeadA =< HeadB, 
	mergeSort(TailA,
	[HeadB|TailB], Result),
	!.

mergeSort([HeadA|TailA], [HeadB|TailB], [HeadB|Result]) :- 
	HeadB =< HeadA,
	mergeSort([HeadA|TailA], 
	TailB, Result), 
	!.

filterArray([], _, _, []).
filterArray([H|T], Element1, Element2, [H|Filtered]) :-
    H > Element1,
    0 is H mod Element2,
    filterArray(T, Element1, Element2, Filtered).

filterArray([H|T], Element1, Element2, Filtered) :-
    (H =< Element1; \+ 0 is H mod Element2),
    filterArray(T, Element1, Element2, Filtered).

reverse(List, Reversed) :-
    reverse_acc(List, [], Reversed).

reverse_acc([], Acc, Acc).
reverse_acc([H|T], Acc, Reversed) :-
    reverse_acc(T, [H|Acc], Reversed).

reverse2(List, Reversed) :-
    reverse_acc2(List, [], Reversed).

reverse_acc2([], Acc, Acc).
reverse_acc2([H|T], Acc, Reversed) :-
    reverse_acc2(T, [H|Acc], Reversed).

cekPalindrom(L) :- 
    reverse2(L, L), !.


insertLast(Elmt, [], [Elmt]) :- !.
insertLast(Elmt, [Head|Tail], [Head|Res]) :- insertLast(Elmt, Tail, Res), !.

rotateSekali([], []).
rotateSekali([H|T], Result) :- insertLast(H, T, Result).


rotate([], _, []) :- !.
rotate(List, 0, List) :- !.
rotate(List, N, Result) :- count(List, L), Neff is (N + L) mod L,
rotateSekali(List, Temp),
NextN is Neff - 1,
rotate(Temp, NextN, Result).

insertFirst(Elmt, [], [Elmt]) :- !.
insertFirst(Elmt, List, [Elmt|List]) :- !.

mapNilai(N, a):-
	N >= 80,
	!.

mapNilai(N, b):-
	N >= 70,
	!.
mapNilai(N, c):-
	N >= 60,
	!.
mapNilai(N, d):-
	N >= 50,
	!.
mapNilai(_, e):- 
	N < 50,
	!.

mapArrayNilai([], []).
mapArrayNilai([Head|Tail], [Indeks|Res]) :- 
    mapNilai(Head, Indeks), mapArrayNilai(Tail, Res).


rerata(L, Rata) :- 
    sum(L, Total), 
	count(L, Jumlah),
	Rata is Total / Jumlah.

prosesMahasiswa(Name, Grades, Result) :- 
    insertLast(Name, [], PreResult1), 
    mapArrayNilai(Grades, Indeks), insertLast(Indeks, PreResult1, PreResult2), 
    rerata(Grades, Rata), insertLast(Rata, PreResult2, PreResult3),
    (Rata >= 80, Status = 'Pass'; Status = 'Fail'), insertLast(Status, PreResult3, Result).