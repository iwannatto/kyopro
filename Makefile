# コマンドラインからコンテストnumを与えられるようになりたい

N =

abc :
	mkdir abc${N}
	cp template/t.cc abc${N}/a.cc
	cp template/t.cc abc${N}/b.cc
	cp template/t.cc abc${N}/c.cc
	cp template/t.cc abc${N}/d.cc
	# cp template/Makefile abc${N}/
	cp template/memo.txt abc${N}/

arc :
	mkdir arc
	cp template/t.cc arc/c.cc
	cp template/t.cc arc/d.cc
	cp template/t.cc arc/e.cc
	cp template/t.cc arc/f.cc
	# cp template/Makefile arc/
	cp template/memo.txt arc/

agc :
	mkdir agc
	cp template/t.cc agc/a.cc
	cp template/t.cc agc/b.cc
	cp template/t.cc agc/c.cc
	cp template/t.cc agc/d.cc
	cp template/t.cc agc/e.cc
	cp template/t.cc agc/f.cc
	# cp template/Makefile agc/
	cp template/memo.txt agc/
