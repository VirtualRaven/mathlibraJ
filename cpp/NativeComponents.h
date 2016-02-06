#ifndef NATIVE_COMPONENTS_INCLUDED
#define NATIVE_COMPONENTS_INCLUDED
#include "main_wrapper.h"
#include <jni.h>
#ifdef __cplusplus
extern "C" {
    jint JNI_OnLoad(JavaVM *vm, void *reserved);
    void JNI_OnUnload(JavaVM *vm, void *reserved);
};
#endif //__cplusplus
namespace NativeComponents
{
    extern jfieldID NhandleId;
    extern jfieldID MhandleId;
    extern jclass FunctionData;
    extern jmethodID FunctionDataC;
    extern jclass Exception;
    extern jmethodID ExceptionC;
    extern jclass CriticalException;
    extern jmethodID CriticalExceptionC;
    extern jclass   NativeType;
    extern jclass   Double;
    extern jmethodID NativeTypeC;
    extern jclass    String;
    void mathlibra_throw_jni(JNIEnv*, interface::wrapper_exception_info);
}
#endif