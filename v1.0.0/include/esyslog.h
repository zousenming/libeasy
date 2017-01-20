/*
  +----------------------------------------------------------------------+
  | libeasy                                                              |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | yiming_6weijun@163.com so we can mail you a copy immediately.        |
  +----------------------------------------------------------------------+
  | Author: Weijun Lu  <yiming_6weijun@163.com>                          |
  +----------------------------------------------------------------------+
*/
#ifndef _ESYSLOG_H_
#define _ESYSLOG_H_
#include "ecommon.h"

#define SYSLOG_EMERG        0       /* system is unusable */
#define SYSLOG_ALERT        1       /* action must be taken immediately */
#define SYSLOG_CRIT         2       /* critical conditions */
#define SYSLOG_ERR          3       /* error conditions */
#define SYSLOG_WARNING      4       /* warning conditions */
#define SYSLOG_NOTICE       5       /* normal but significant condition */
#define SYSLOG_INFO         6       /* informational */
#define SYSLOG_DEBUG        7       /* debug-level messages */

#define SYSLOG_MAKEPRI(fac, pri)    ((fac) | (pri))

#define SYSLOG_INTERNAL_NOPRI       0x10    /* the "no priority" priority */

#define SYSLOG_INTERNAL_MARK                \
    SYSLOG_MAKEPRI(SYSLOG_NFACILITIES, 0)

/* facility codes */
#define SYSLOG_KERN         (0<<3)  /* kernel messages */
#define SYSLOG_USER         (1<<3)  /* random user-level messages */
#define SYSLOG_MAIL         (2<<3)  /* mail system */
#define SYSLOG_DAEMON       (3<<3)  /* system daemons */
#define SYSLOG_AUTH         (4<<3)  /* security/authorization messages */
#define SYSLOG_SYSLOG       (5<<3)  /* messages generated by syslogd */
#define SYSLOG_LPR          (6<<3)  /* line printer subsystem */
#define SYSLOG_NEWS         (7<<3)  /* network news subsystem */
#define SYSLOG_UUCP         (8<<3)  /* UUCP subsystem */
#define SYSLOG_CRON         (9<<3)  /* clock daemon */
#define SYSLOG_AUTHPRIV     (10<<3) /* security/authorization messages */
#define SYSLOG_FTP          (11<<3) /* ftp daemon */

#define SYSLOG_LOCAL0       (16<<3) /* reserved for local use */
#define SYSLOG_LOCAL1       (17<<3) /* reserved for local use */
#define SYSLOG_LOCAL2       (18<<3) /* reserved for local use */
#define SYSLOG_LOCAL3       (19<<3) /* reserved for local use */
#define SYSLOG_LOCAL4       (20<<3) /* reserved for local use */
#define SYSLOG_LOCAL5       (21<<3) /* reserved for local use */
#define SYSLOG_LOCAL6       (22<<3) /* reserved for local use */
#define SYSLOG_LOCAL7       (23<<3) /* reserved for local use */

#define SYSLOG_NFACILITIES  24      /* current number of facilities */

typedef struct _syslog_code_t{
    char *name;
    int   value;
}syslog_code_t;

/** 
 *        Name: syslog_open 
 * Description: open syslog.
 *   Parameter: ip -> syslog ip地址. 
 *              port -> syslog端口地址.
 *              facility -> syslog设备.
 *              hostname -> 主机名.
 *      Return: 1 -> success
 *              -1 -> failed.
 */
int syslog_open(char *ip, int port, int facility, char *hostname, char *program);

/** 
 *        Name: syslog_write
 * Description: 向syslog-ng写入日志.
 *   Parameter: level  -> 日志级别.
 *              msg    -> 日志内容.
 *              length -> msg长度.
 *      Return: 1 -> success
 *              0 -> failed.
 */
int syslog_write(int level, char *msg, int length);

/** 
 *        Name: syslog_close
 * Description: 关闭syslog.
 *   Parameter: 
 *      Return: 1 -> success
 *              0 -> failed.
 */
int syslog_close();
    
#endif
