# $OpenBSD: Makefile,v 1.4 2020/08/20 20:50:02 noiseless Exp $

PKGNAME =	libusrsctp-${V}
V =		0.9.5.0
#REVISION =	1
COMMENT =	portable SCTP userland stack
DISTNAME =	${GH_TAGNAME}
CATEGORIES =	tgwip net

GH_ACCOUNT =	sctplab
GH_PROJECT =	usrsctp
GH_TAGNAME =	${V}

HOMEPAGE =	https://github.com/sctplab/usrsctp
#MAINTAINER =	S

# BSD3CLAUSE
PERMIT_PACKAGE =	Yes

CONFIGURE_ARGS =	-DBUILD_SHARED_LIBS=ON
CFLAGS+=	-Wno-error
SHARED_LIBS += 	usrsctp		2.0

MODULES =	devel/cmake

.include <bsd.port.mk>
