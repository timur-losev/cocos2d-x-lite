#include "jswrapper/v8/tracing/trace_event.h"


#if (SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8) && SE_ENABLE_INSPECTOR

namespace node {
namespace tracing {

v8::Platform* platform_ = nullptr;

void TraceEventHelper::SetCurrentPlatform(v8::Platform* platform) {
  platform_ = platform;
}

v8::Platform* TraceEventHelper::GetCurrentPlatform() {
  return platform_;
}


}  // namespace tracing
}  // namespace node


#endif
