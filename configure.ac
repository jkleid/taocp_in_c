AC_INIT([m], [1.0], [jonathan.kleid+taocp@gmail.com])
AM_PATH_CHECK
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_SEARCH_LIBS([floor], [m])
AC_SEARCH_LIBS([timer_create], [rt])
AC_SEARCH_LIBS([pthread_create], [pthread])
AC_PROG_CC
AC_PROG_RANLIB
m4_pattern_allow([AM_PROG_AR])
AM_PROG_AR
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile 1_3_2/Makefile mix/Makefile])
AC_OUTPUT
