#pragma once

#include <aidl/android/hardware/euicc/BnEuicc.h>

namespace aidl::android::hardware::euicc {

class EuiccImpl : public BnEuicc {
  public:
    ndk::ScopedAStatus getEid(std::string* _aidl_return) override {
        *_aidl_return = "89049032000000000000"; // Пример eID
        return ndk::ScopedAStatus::ok();
    }
};

}  // namespace aidl::android::hardware::euicc