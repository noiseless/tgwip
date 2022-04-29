QT6NAME =		QtImageFormats
COMMENT =		support for additional image formats in Qt6

WANTLIB += ${COMPILER_LIBCXX} GL Qt6Core Qt6Gui c jasper jpeg
WANTLIB += m mng tiff webp webpdemux webpmux

LIB_DEPENDS =		graphics/jasper \
			graphics/tiff \
			graphics/libmng \
			graphics/libwebp

.include <bsd.port.mk>
