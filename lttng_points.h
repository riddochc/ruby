#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER ruby_vm

#if !defined(_TRACEPOINT_UST_RUBY_VM) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _TRACEPOINT_UST_RUBY_VM

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(ruby_vm,
                 c_call,
                 TP_ARGS(int, thread,
                         const char*, classname,
                         const char*, idname),
                 TP_FIELDS(ctf_integer_hex(int, c_call_thread, thread)
                           ctf_string(c_call_classname, classname)
                           ctf_string(c_call_idname, idname)))
TRACEPOINT_LOGLEVEL(ruby_vm, c_call, TRACE_DEBUG_FUNCTION)

TRACEPOINT_EVENT(ruby_vm,
                 c_call_recv,
                 TP_ARGS(int, thread,
                         const char*, classname,
                         const char*, idname,
                         const char*, recv),
                 TP_FIELDS(ctf_integer_hex(int, c_call_thread, thread)
                           ctf_string(c_call_classname, classname)
                           ctf_string(c_call_idname, idname)
                           ctf_string(c_call_recv_class, recv)))
TRACEPOINT_LOGLEVEL(ruby_vm, c_call_recv, TRACE_DEBUG_FUNCTION)

TRACEPOINT_EVENT(ruby_vm,
                 c_return,
                 TP_ARGS(int, thread,
                         const char*, classname,
                         const char*, idname),
                 TP_FIELDS(ctf_integer_hex(int, c_call_thread, thread)
                           ctf_string(c_return_classname, classname)
                           ctf_string(c_return_idname, idname)))
TRACEPOINT_LOGLEVEL(ruby_vm, c_return, TRACE_DEBUG_FUNCTION)

TRACEPOINT_EVENT(ruby_vm,
                 c_return_recv,
                 TP_ARGS(int, thread,
                         const char*, classname,
                         const char*, idname,
                         const char*, recv,
                         const char*, value),
                 TP_FIELDS(ctf_integer_hex(int, c_call_thread, thread)
                           ctf_string(c_return_classname, classname)
                           ctf_string(c_return_idname, idname)
                           ctf_string(c_return_recv_class, recv)
                           ctf_string(c_return_retval_class, value)))
TRACEPOINT_LOGLEVEL(ruby_vm, c_return_recv, TRACE_DEBUG_FUNCTION)

TRACEPOINT_EVENT(ruby_vm,
                 ruby_call,
                 TP_ARGS(int, thread,
                         const char*, classname,
                         const char*, idname),
                 TP_FIELDS(ctf_integer_hex(int, call_thread, thread)
                           ctf_string(call_classname, classname)
                           ctf_string(call_idname, idname)))
TRACEPOINT_LOGLEVEL(ruby_vm, ruby_call, TRACE_DEBUG_FUNCTION)

TRACEPOINT_EVENT(ruby_vm,
                 ruby_return,
                 TP_ARGS(int, thread,
                         const char*, classname,
                         const char*, idname),
                 TP_FIELDS(ctf_integer_hex(int, call_thread, thread)
                           ctf_string(return_classname, classname)
                           ctf_string(return_idname, idname)))
TRACEPOINT_LOGLEVEL(ruby_vm, ruby_return, TRACE_DEBUG_FUNCTION)

TRACEPOINT_EVENT(ruby_vm,
                 ruby_return_empty,
                 TP_ARGS(int, thread),
                 TP_FIELDS(ctf_integer_hex(int, call_thread, thread)))
TRACEPOINT_LOGLEVEL(ruby_vm, ruby_return_empty, TRACE_DEBUG_FUNCTION)


TRACEPOINT_EVENT(ruby_vm,
                 symbol_create,
                 TP_ARGS(const char*, name),
                 TP_FIELDS(ctf_string(symbol_name, name)))
TRACEPOINT_LOGLEVEL(ruby_vm, symbol_create, TRACE_DEBUG_FUNCTION)

TRACEPOINT_EVENT(ruby_vm,
                 object_alloc,
                 TP_ARGS(const char*, name),
                 TP_FIELDS(ctf_string(object_class, name)))
TRACEPOINT_LOGLEVEL(ruby_vm, object_alloc, TRACE_DEBUG_FUNCTION)

TRACEPOINT_EVENT(ruby_vm,
                 raise,
                 TP_ARGS(int, thread,
                         const char*, classname,
                         const char*, message),
                 TP_FIELDS(
                         ctf_integer_hex(int, call_thread, thread)
                         ctf_string(raise_class, cname)
                         ctf_string(raise_message, message)))
TRACEPOINT_LOGLEVEL(ruby_vm, raise, TRACE_ERROR)

TRACEPOINT_EVENT(ruby_vm,
                 load_entry,
                 TP_ARGS(const char*, filename),
                 TP_FIELDS(ctf_string(load_filename, filename)))
TRACEPOINT_LOGLEVEL(ruby_vm, load_entry, TRACE_DEBUG_FUNCTION)

TRACEPOINT_EVENT(ruby_vm,
                 load_return,
                 TP_ARGS(const char*, filename),
                 TP_FIELDS(ctf_string(load_filename, filename)))
TRACEPOINT_LOGLEVEL(ruby_vm, load_entry, TRACE_DEBUG_FUNCTION)

TRACEPOINT_EVENT(ruby_vm,
                 require_entry,
                 TP_ARGS(const char*, filename),
                 TP_FIELDS(ctf_string(require_filename, filename)))
TRACEPOINT_LOGLEVEL(ruby_vm, require_entry, TRACE_DEBUG_FUNCTION)

TRACEPOINT_EVENT(ruby_vm,
                 require_return,
                 TP_ARGS(const char*, filename),
                 TP_FIELDS(ctf_string(require_filename, filename)))
TRACEPOINT_LOGLEVEL(ruby_vm, require_return, TRACE_DEBUG_FUNCTION)

TRACEPOINT_EVENT(ruby_vm,
                 find_require_entry,
                 TP_ARGS(const char*, filename),
                 TP_FIELDS(ctf_string(require_filename, filename)))
TRACEPOINT_LOGLEVEL(ruby_vm, find_require_entry, TRACE_DEBUG_FUNCTION)

TRACEPOINT_EVENT(ruby_vm,
                 find_require_return,
                 TP_ARGS(const char*, filename),
                 TP_FIELDS(ctf_string(require_filename, filename)))
TRACEPOINT_LOGLEVEL(ruby_vm, find_require_return, TRACE_DEBUG_FUNCTION)

TRACEPOINT_EVENT(ruby_vm,
                 string_alloc,
                 TP_ARGS(int, length),
                 TP_FIELDS(ctf_integer(int, string_length, length)))
TRACEPOINT_LOGLEVEL(ruby_vm, string_alloc, TRACE_DEBUG_FUNCTION)

TRACEPOINT_EVENT(ruby_vm,
                 string_new,
                 TP_ARGS(const char*, strdata,
                         int, length),
                 TP_FIELDS(ctf_sequence_text(unsigned char, string_data, strdata, size_t, length)))
TRACEPOINT_LOGLEVEL(ruby_vm, string_new, TRACE_DEBUG_FUNCTION)

TRACEPOINT_EVENT(ruby_vm,
                 string_create,
                 TP_ARGS(const char*, strdata),
                 TP_FIELDS(ctf_string(string_data, strdata)))
TRACEPOINT_LOGLEVEL(ruby_vm, string_create, TRACE_DEBUG_FUNCTION)


#endif /* _TRACEPOINT_UST_RUBY_VM_INSTS */

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./lttng.h"

/* This part must be outside ifdef protection */
#include <lttng/tracepoint-event.h>


