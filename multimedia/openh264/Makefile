# $OpenBSD$

COMMENT =		Cisco implementation of H.264 codec

V =			2.1.1
GH_ACCOUNT =		cisco
GH_PROJECT =		openh264
GH_TAGNAME =		v${V}

CATEGORIES =		multimedia

MAINTAINER =		Andrew Krasavin <noiseless-ak@yandex.ru>, \
			Klemens Nanni <kn@openbsd.org>

# BSD 2-clause
PERMIT_PACKAGE =	Yes

# Fixed #3305: Frame reorder after the frame is read.
# https://github.com/cisco/openh264/pull/3319
C =			6cc269bebccc8acc6eb28fffb312d8189d4788ad
MASTER_SITES0 =		https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES =		openh264-frame-reorder-fix{${C}}.patch:0
PATCH_DIST_STRIP =	-p1 

BUILD_DEPENDS =		devel/nasm

WANTLIB +=		${COMPILER_LIBCXX} m

USE_GMAKE =		Yes

CONFIGURE_STYLE =	none
MAKE_ENV =		PREFIX="${PREFIX}" \
			CXX=clang++ \
			OS=bsd ARCH="${ARCH:S/amd64/x86_64/}" \
			CCASFLAGS='$$(CFLAGS) ${ASFLAGS}' \
			CFLAGS_OPT="" CFLAGS_DEBUG=""

.include <bsd.port.mk>
