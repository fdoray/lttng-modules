#undef TRACE_SYSTEM
#define TRACE_SYSTEM latency_tracker

#if !defined(LTTNG_TRACE_LATENCY_TRACKER_H) || defined(TRACE_HEADER_MULTI_READ)
#define LTTNG_TRACE_LATENCY_TRACKER_H
#include "../../../probes/lttng-tracepoint-event.h"
#include <linux/tracepoint.h>
#include <linux/netdevice.h>

LTTNG_TRACEPOINT_EVENT(
	syscall_latency,
	TP_PROTO(u64 start_ts, u64 duration, int id),
	TP_ARGS(start_ts, duration, id),
	TP_STRUCT__entry(
		__field(u64, start_ts)
		__field(u64, duration)
		__field(int, id)
	),
	TP_fast_assign(
		tp_assign(start_ts, start_ts)
		tp_assign(duration, duration)
		tp_assign(id, id)
	),
	TP_printk("start_ts=%llu, duration=%llu, id=%d",
		__entry->start_ts, __entry->duration, __entry->id)
   )

#endif /* LTTNG_TRACE_LATENCY_TRACKER_H */

/* this part must be outside protection */
#include "../../../probes/define_trace.h"
