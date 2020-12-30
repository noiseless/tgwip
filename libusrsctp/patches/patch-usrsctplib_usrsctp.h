--- usrsctplib/usrsctp.h.orig	2020-12-10 14:44:32.000000000 +0000
+++ usrsctplib/usrsctp.h	2012-20-10 14:44:32.000000000 +0000
@@ -87,6 +87,25 @@ extern "C" {
 
 typedef uint32_t sctp_assoc_t;
 
+#if defined(_WIN32) && defined(_MSC_VER)
+#pragma pack (push, 1)
+#define SCTP_PACKED
+#else
+#define SCTP_PACKED __attribute__((packed))
+#endif
+
+struct sctp_common_header {
+       uint16_t source_port;
+       uint16_t destination_port;
+       uint32_t verification_tag;
+       uint32_t crc32c;
+} SCTP_PACKED;
+
+#if defined(_WIN32) && defined(_MSC_VER)
+#pragma pack()
+#endif
+#undef SCTP_PACKED
+
 #define AF_CONN 123
 /* The definition of struct sockaddr_conn MUST be in
  * tune with other sockaddr_* structures.

