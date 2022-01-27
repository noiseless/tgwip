# $OpenBSD$

COMMENT =		library for freeswitch yuv graphics manipulation
# clone of https://chromium.googlesource.com/libyuv/libyuv which has
# no releases or tags, main/master/stable/<commit> tarballs are *unstable*;
# use mirror to get stable tarballs for latest master
GH_ACCOUNT =		noiseless
GH_PROJECT =		libyuv

GH_COMMIT =		2c6bfc02d5265c95df69190c785f5d00d13bb444
CATEGORIES =		graphics
# see ${WRKSRC}/CM_linux_packages.cmake and/or configure output
VERSION =		0.0.1809
DISTNAME =		${GH_PROJECT}-${VERSION}
SUBST_VARS +=		VERSION

MAINTAINER +=		Andrew Krasavin <noiseless-ak@yandex.ru>, \
			Klemens Nanni <kn@openbsd.org>

SHARED_LIBS =		yuv	0.0	# 0.0.0

HOMEPAGE =		https://chromium.googlesource.com/libyuv/libyuv/

# BSD 3-clause
PERMIT_PACKAGE =	Yes

WANTLIB +=		${COMPILER_LIBCXX} c jpeg m

COMPILER =		base-clang ports-gcc
COMPILER_LANGS =	c++

MODULES =		devel/cmake

CONFIGURE_ARGS =	-DTEST=ON

BUILD_DEPENDS =		devel/gtest

LIB_DEPENDS =		graphics/jpeg

# (XXX) macppc: 2 FAILED TESTS
do-test:
	${WRKBUILD}/libyuv_unittest --gtest_also_run_disabled_tests

post-install:
	${SUBST_DATA} ${FILESDIR}/libyuv.pc ${PREFIX}/lib/pkgconfig/libyuv.pc

.include <bsd.port.mk>
