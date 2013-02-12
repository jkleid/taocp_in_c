TESTS = check_M check_M_literal check_P
bin_PROGRAMS = print_primes ex3 ex8
check_PROGRAMS = check_M check_M_literal check_P

check_M_SOURCES = check_M.c M.c
check_M_CFLAGS = @CHECK_CFLAGS@
check_M_LDADD = @CHECK_LIBS@

check_M_literal_SOURCES = check_M.c M_literal.c
check_M_literal_CFLAGS = @CHECK_CFLAGS@
check_M_literal_LDADD = @CHECK_LIBS@

print_primes_SOURCES = harness_P.c P.c

check_P_SOURCES = check_P.c P.c
check_P_CFLAGS = @CHECK_CFLAGS@
check_P_LDADD = @CHECK_LIBS@

ex3_SOURCES = ex3.c M.c
ex8_SOURCES = ex8.c
