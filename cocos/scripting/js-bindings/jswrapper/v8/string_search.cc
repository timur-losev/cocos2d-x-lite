#include "string_search.h"

#if (SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8) && SE_ENABLE_INSPECTOR

namespace node {
namespace stringsearch {

int StringSearchBase::kBadCharShiftTable[kUC16AlphabetSize];
int StringSearchBase::kGoodSuffixShiftTable[kBMMaxShift + 1];
int StringSearchBase::kSuffixTable[kBMMaxShift + 1];

}  // namespace stringsearch
}  // namespace node
#endif //#if (SCRIPT_ENGINE_TYPE == SCRIPT_ENGINE_V8) && SE_ENABLE_INSPECTOR

