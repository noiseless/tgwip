# $OpenBSD: Makefile,v 1.4 2020/08/20 20:50:02 noiseless Exp $

PKGNAME =	range-v3-${V}
V =		0.11.0
COMMENT =	experimental range library for C++11/14/17
DISTNAME =	${GH_TAGNAME}
CATEGORIES =	tgwip local devel

GH_ACCOUNT =	ericniebler
GH_PROJECT =	range-v3
GH_TAGNAME =	${V}

HOMEPAGE =	https://github.com/ericniebler/range-v3
#MAINTAINER =	S

# BSL
PERMIT_PACKAGE =	Yes

MODULES =	devel/cmake

CONFIGURE_ARGS =	-DRANGE_V3_TESTS=OFF

.include <bsd.port.mk>
