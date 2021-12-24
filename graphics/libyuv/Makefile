# $OpenBSD$

COMMENT =		library for freeswitch yuv graphics manipulation
CATEGORIES =		graphics

# clone of https://chromium.googlesource.com/libyuv/libyuv which has
# no releases or tags, main/master/stable/<commit> tarballs are *unstable*;
# use GitHub fork with stable tarballs;
GH_ACCOUNT =		noiseless
GH_PROJECT =		libyuv

# check version in include/libyuv/version.h
# git blame -l ./include/libyuv/version.h | \
# awk '/#define LIBYUV_VERSION/ {printf "ci: %s, ver:%s\n", $1, $NF}'
GH_COMMIT =		78625492cb0ff43faebbb6cb6db2209cd4ccb785

# Declare this variable explicitly only to pass it to SUBST_CMD subsequently
VERSION =		0.0.1807
DISTNAME =		${GH_PROJECT}-${VERSION}

HOMEPAGE =		https://chromium.googlesource.com/libyuv/libyuv/

# BSD 3-clause
PERMIT_PACKAGE =	Yes

CONFIGURE_ARGS +=	-DTEST:BOOL=ON

COMPILER =		base-clang ports-gcc
WANTLIB +=		${COMPILER_LIBCXX} c jpeg m

# Needed only for tests
BUILD_DEPENDS +=	devel/gtest

LIB_DEPENDS +=		graphics/jpeg

SHARED_LIBS =		yuv	0.0     # 0.0.0

MODULES =		devel/cmake

SUBST_VARS +=		VERSION

# (XXX) macppc: 2 FAILED TESTS
do-test:
	${WRKBUILD}/libyuv_unittest --gtest_also_run_disabled_tests

post-install:
	${SUBST_DATA} ${FILESDIR}/libyuv.pc ${PREFIX}/lib/pkgconfig/libyuv.pc

.include <bsd.port.mk>
