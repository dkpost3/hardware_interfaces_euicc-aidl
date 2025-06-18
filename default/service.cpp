#include <android/binder_interface_utils.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>
#include "EuiccImpl.h"

using aidl::android::hardware::euicc::EuiccImpl;

int main() {
    ABinderProcess_setThreadPoolMaxThreadCount(1);
    std::shared_ptr<EuiccImpl> euicc = ndk::SharedRefBase::make<EuiccImpl>();
    const std::string instance = std::string() + EuiccImpl::descriptor + "/default";
    binder_status_t status = AServiceManager_addService(euicc->asBinder().get(), instance.c_str());
    CHECK(status == STATUS_OK);
    ABinderProcess_joinThreadPool();
    return EXIT_FAILURE;  // unreachable
}