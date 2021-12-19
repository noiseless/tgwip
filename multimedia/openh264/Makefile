# $OpenBSD$

COMMENT =		Cisco implementation of H.264 codec

GH_ACCOUNT =		cisco
GH_PROJECT =		openh264
GH_TAGNAME =		v2.1.1

CATEGORIES =		multimedia

SHARED_LIBS =		openh264	0.0	# 6.0

MAINTAINER =		Andrew Krasavin <noiseless-ak@yandex.ru>, \
			Klemens Nanni <kn@openbsd.org>

# BSD 2-clause
PERMIT_PACKAGE =	Yes

# Fixed #3305: Frame reorder after the frame is read.
# https://github.com/cisco/openh264/pull/3319
C =			6cc269bebccc8acc6eb28fffb312d8189d4788ad
MASTER_SITES0 =		${MASTER_SITES_GITHUB:H:H:H}/commit/
PATCHFILES =		openh264-frame-reorder-fix{${C}}.patch:0
PATCH_DIST_STRIP =	-p1

WANTLIB +=		${COMPILER_LIBCXX} m

USE_GMAKE =		Yes

MAKE_FLAGS +=		PREFIX=${PREFIX}

# disable tests and unneeded GMP API for now
MAKE_FLAGS +=		HAVE_GMP_API=No

# pass our .so version, see ${WRKSRC}/build-${OS}.mk
MAKE_FLAGS +=		OS=bsd \
			FULL_VERSION=${LIBopenh264_VERSION} \
			SHAREDLIB_MAJORVERSION=${LIBopenh264_VERSION:R}

# overwrite upstream "-O3" and "-g" defaults, ensure our DEBUG build works
MAKE_FLAGS +=		CXX=${CXX} \
			CFLAGS_OPT='${CFLAGS}' \
			CFLAGS_DEBUG='${DEBUG}'

TEST_DEPENDS =		devel/gtest

TEST_FLAGS +=		HAVE_GTEST=Yes

post-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/h264enc ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKBUILD}/h264dec ${PREFIX}/bin/

.include <bsd.port.mk>
