bin/mace4 -f test/Group_theory.in | bin/interpformat cooked > Group_theory.m
./mcs --input qg5.out --output result --maxdepth 3 --value '["x","y"]' --rewrite 'f(x,x)=x.'

bin/mace4 -f test/ring_theory.in | bin/interpformat cooked > ring_theory.m 
./mcs -i ring_theory.m -o result_ring -d 2 -v '["x","y"]' --rewrite 'x+e=x.e+x=x.x*e=e.e*x=e.'

./mcs -i ring_theory.m -o result_ring -d 2 -v '["x","y","z"]' --rewrite 'x+e=x.e+x=x.x*e=e.e*x=e.'

bin/mace4 -c -f test/bool_theory.in | bin/interpformat cooked > bool_theory.m
./mcs -i bool_theory.m -o result_bool -d 2 -v '["x"]' --rewrite "x*x=x.x+x=x.x*I=x.x+O=x.x*O=O.x+I=I.*(x,'(x))=O.+(x,'(x))=I."
./mcs -i bool_theory.m -o result_bool -d 2 -v '["x"]' --rewrite "x*x=x.x+x=x.x*I=x.I*x=x.O+x=x.x+O=x.O*x=O.x*O=O.I+x=I.x+I=I.*(x,'(x))=O.*('(x),x)=O.+(x,'(x))=I.+('(x),x)=I."
./mcs -i bool_theory.m -o result_bool -d 2 -v '["x","y"]' --rewrite "x*x=x.x+x=x.x*I=x.I*x=x.O+x=x.x+O=x.O*x=O.x*O=O.I+x=I.x+I=I.*(x,'(x))=O.*('(x),x)=O.+(x,'(x))=I.+('(x),x)=I."