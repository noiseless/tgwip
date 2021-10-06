# $OpenBSD$

PKGNAME =	${_NAME}-${V}
_NAME =		rnnoise
V =		20210122
REVISION =	0
COMMENT =	recurrent neural network for audio noise reduction
DISTNAME =	${GH_TAGNAME}
CATEGORIES =	audio local tgwip

EXTRACT_CASES=	*.tar.gz) pax -zrs ',^rnnoise-${GH_TAGNAME}/,${WRKDIR}/${PKGNAME}/,' \
				-f ${FULLDISTDIR}/$$archive;;

WRKDIST =	${WRKDIR}/${PKGNAME}

GH_ACCOUNT =	xiph
GH_PROJECT =	rnnoise
GH_TAGNAME =	1cbdbcf1283499bbb2230a6b0f126eb9b236defd

# BSD2CLAUSE
PERMIT_PACKAGE =	Yes

WANTLIB += 		m

SHARED_LIBS =		rnnoise		0.0

USE_GMAKE =		Yes
CONFIGURE_STYLE =	autoreconf
AUTOCONF_VERSION =	2.69
AUTOMAKE_VERSION =	1.15
CONFIGURE_ARGS =	--disable-static --disable-examples
AUTORECONF =		${WRKDIST}/autogen.sh

.include <bsd.port.mk>
