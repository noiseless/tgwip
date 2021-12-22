# $OpenBSD: $

COMMENT =		QR Code generator library
GH_ACCOUNT =		nayuki
GH_PROJECT =		QR-Code-generator
GH_TAGNAME =		v1.7.0
PKGNAME =		${DISTNAME:L}
CATEGORIES =		graphics

HOMEPAGE =		https://www.nayuki.io/page/qr-code-generator-library

# MIT
PERMIT_PACKAGE =	Yes

MAINTAINER =		Klemens Nanni <kn@openbsd.org>

# C++
COMPILER =		base-clang ports-gcc

# upstream supports c cpp java python rust typescript-javascript
LANGS 	=		c cpp

MAKE_ENV +=		CPPFLAGS='${CPPFLAGS}' \
			CXXFLAGS='${CXXFLAGS}'

# upstream provides no shared library versions for any language;
# maintain one version and keep all libraries in sync
LIBVER =		0.0
MAKE_FLAGS +=		SHLIB_MAJOR=${LIBVER:R} \
			SHLIB_MINOR=${LIBVER:E}
.for _lang in ${LANGS}
_LIB${_lang} =		qrcodegen${_lang:c=}
SHARED_LIBS +=		${_LIB${_lang}}	${LIBVER}
.endfor
# just shared libraries
MAKE_FLAGS +=		-DNOLIBSTATIC \
			-DNOPROFILE

FAKE_FLAGS =		LIBDIR=/usr/local/lib

# XXX on an amd64 snapshot with base-clang 11.1.0:
# - base-clang builds without this
# - ports-gcc needs this
# on an amd64 snapshot with base-clang 13.0.0:
# - base-clang needs this
# - ports-gcc needs this
#
# qrcodegen.cpp:24:10: fatal error: 'algorithm' file not found
# include <algorithm>
CPPFLAGS +=		-I/usr/include/c++/v1

post-extract:
	echo 'SUBDIR =	${LANGS}'		>| ${WRKSRC}/${MAKE_FILE}
	echo '.include <bsd.subdir.mk>'		>> ${WRKSRC}/${MAKE_FILE}
.for _lang in ${LANGS}
	echo 'LIB =	${_LIB${_lang}}'	>| ${WRKSRC}/${_lang}/Makefile
	echo 'SRCS =	qrcodegen.${_lang}'	>> ${WRKSRC}/${_lang}/Makefile
	echo '.include <bsd.lib.mk>'		>> ${WRKSRC}/${_lang}/Makefile
.endfor

.include <bsd.port.mk>
