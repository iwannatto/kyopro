T = template/t.cc
MEMO = template/memo.txt
MAKEFILE = template/Makefile

practice2 :
	mkdir $@
	cp ${T} $@/a.cc
	cp ${T} $@/b.cc
	cp ${T} $@/c.cc
	cp ${T} $@/d.cc
	cp ${T} $@/e.cc
	cp ${T} $@/f.cc
	cp ${MEMO} $@/
	cp ${MAKEFILE} $@/