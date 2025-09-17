#include <stdio.h>
#include <stdlib.h>
#include "csr.h"

void check_flag(const char* name, csr_config_t flag) {
    int ret = csr_check(flag);
    if (ret == 0) {
        printf("  [✓] %s: Allowed\n", name);
    } else {
        printf("  [✗] %s: Denied\n", name);
    }
}

int main(void) {
    csr_config_t config;
    int ret = csr_get_active_config(&config);

    if (ret != 0) {
        perror("csr_get_active_config");
        return 1;
    }

    printf("CSR Active Config: 0x%08x\n", config);
    printf("Flag status:\n");

    check_flag("Allow untrusted kexts",            CSR_ALLOW_UNTRUSTED_KEXTS);
    check_flag("Unrestricted filesystem",          CSR_ALLOW_UNRESTRICTED_FS);
    check_flag("task_for_pid()",                   CSR_ALLOW_TASK_FOR_PID);
    check_flag("Kernel debugger",                  CSR_ALLOW_KERNEL_DEBUGGER);
    check_flag("Apple internal",                   CSR_ALLOW_APPLE_INTERNAL);
    check_flag("Unrestricted DTrace",              CSR_ALLOW_UNRESTRICTED_DTRACE);
    check_flag("Unrestricted NVRAM",               CSR_ALLOW_UNRESTRICTED_NVRAM);
    check_flag("Device configuration",             CSR_ALLOW_DEVICE_CONFIGURATION);
    check_flag("Any Recovery OS",                  CSR_ALLOW_ANY_RECOVERY_OS);
    check_flag("Unapproved kexts",                 CSR_ALLOW_UNAPPROVED_KEXTS);
    check_flag("Executable policy override",       CSR_ALLOW_EXECUTABLE_POLICY_OVERRIDE);
    check_flag("Unauthenticated root",             CSR_ALLOW_UNAUTHENTICATED_ROOT);
    check_flag("Research guests",                  CSR_ALLOW_RESEARCH_GUESTS);

    return 0;
}
