#include <linux/module.h>
#include "../lttng-tracer.h"

/* Build time verification of mismatch between mainline TRACE_EVENT()
 * arguments and LTTng adaptation layer LTTNG_TRACEPOINT_EVENT() arguments.
 */
#include "../instrumentation/events/mainline/latency_tracker.h"

/* create LTTng tracepoint probes */
#define LTTNG_PACKAGE_BUILD
#define CREATE_TRACE_POINTS
#define TRACE_INCLUDE_PATH ../instrumentation/events/lttng-module

#include "../instrumentation/events/lttng-module/latency_tracker.h"

MODULE_LICENSE("GPL and additional rights");
MODULE_AUTHOR("Julien Desfossez <jdesfossez@efficios.com>");
MODULE_DESCRIPTION("LTTng latency_tracker probes");
MODULE_VERSION(__stringify(LTTNG_MODULES_MAJOR_VERSION) "."
    __stringify(LTTNG_MODULES_MINOR_VERSION) "."
    __stringify(LTTNG_MODULES_PATCHLEVEL_VERSION)
    LTTNG_MODULES_EXTRAVERSION);
