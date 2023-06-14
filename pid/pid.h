#ifndef _PID_H_
#define _PID_H_

// enum taken from /include/linux/pid.h
// added in PIDTYPE_TID

enum pid_type
{
	PIDTYPE_PID,
	PIDTYPE_TGID,
	PIDTYPE_PGID,
	PIDTYPE_SID,
	PIDTYPE_MAX,
    PIDTYPE_TID
};
typedef enum pid_type PidType_t;

#endif // _PID_H_