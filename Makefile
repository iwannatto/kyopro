T = template/t.cc
MEMO = template/memo.txt
MAKEFILE = template/Makefile

abc344 :
	mkdir $@
	cp ${T} $@/a.cc
	cp ${T} $@/b.cc
	cp ${T} $@/c.cc
	cp ${T} $@/d.cc
	cp ${T} $@/e.cc
	cp ${T} $@/f.cc
	cp ${MEMO} $@/
	cp ${MAKEFILE} $@/

kakomon :
	mkdir $@
	cp ${T} $@/a.cc
	cp ${MAKEFILE} $@/