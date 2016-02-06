//
// Created by raven on 2016-02-05.
//
#include <main_wrapper.h>
#include <jni.h>
#include "NativeComponents.h"

JNIEnv* genv;

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    if (vm->GetEnv(reinterpret_cast<void**>(&genv), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }

    NativeComponents::CriticalException=(jclass)genv->NewGlobalRef(genv->FindClass("mathlibra/MathlibraCriticalException"));
    if(NativeComponents::CriticalException == NULL)
    {
        return -1;
    }
    NativeComponents::CriticalExceptionC=genv->GetMethodID(
            NativeComponents::CriticalException,
            "<init>",
            "(Ljava/lang/String;Ljava/lang/String;S)V");
    if(NativeComponents::CriticalExceptionC==NULL)
    {
        return -1;
    }
    NativeComponents::Exception=(jclass)genv->NewGlobalRef(genv->FindClass("mathlibra/MathlibraException"));
    if(NativeComponents::Exception==NULL)
    {
        return -1;
    }
    NativeComponents::ExceptionC=genv->GetMethodID(
            NativeComponents::Exception,
            "<init>",
            "(Ljava/lang/String;Ljava/lang/String;S)V");
    if(NativeComponents::ExceptionC==NULL)
    {
        return -1;
    }
    NativeComponents::FunctionData=(jclass)genv->NewGlobalRef(genv->FindClass("mathlibra/FunctionData"));
    if(NativeComponents::FunctionData==NULL)
    {
        return -1;
    }
    NativeComponents::FunctionDataC =genv->GetMethodID(NativeComponents::FunctionData,
                                                       "<init>",
                                                       "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    if(NativeComponents::FunctionDataC==NULL)
    {
        return -1;
    }
    NativeComponents::NativeType=(jclass)genv->NewGlobalRef(genv->FindClass("mathlibra/NativeType"));
    if(NativeComponents::NativeType == NULL)
    {
        return -1;
    }
    NativeComponents::NhandleId=genv->GetFieldID(NativeComponents::NativeType,"__handle","J");
    if(NativeComponents::NhandleId==NULL)
    {
        return -1;
    }
    NativeComponents::NativeTypeC=genv->GetMethodID(NativeComponents::NativeType,"<init>","(JZ)V");
    if(NativeComponents::NativeTypeC==NULL)
    {
        return -1;
    }
    NativeComponents::Double=(jclass)genv->NewGlobalRef(genv->FindClass("[D"));
    if(NativeComponents::Double==NULL)
    {
        return -1;
    }
    NativeComponents::String=(jclass)genv->NewGlobalRef(genv->FindClass("java/lang/String"));
    if(NativeComponents::String==NULL)
    {
        return -1;
    }
    auto tmp = genv->FindClass("mathlibra/Mathlibra");
    if(tmp== NULL)
    {
        return -1;
    }

    NativeComponents::MhandleId=genv->GetFieldID(tmp,"__handle","J");


    return JNI_VERSION_1_6;
}
void JNI_OnUnload(JavaVM *vm, void *reserved)
{
       genv->DeleteGlobalRef(NativeComponents::CriticalException);
       genv->DeleteGlobalRef(NativeComponents::Exception);
       genv->DeleteGlobalRef(NativeComponents::FunctionData);
       genv->DeleteGlobalRef(NativeComponents::NativeType);
       genv->DeleteGlobalRef(NativeComponents::Double);
       genv->DeleteGlobalRef(NativeComponents::String);

}
namespace NativeComponents {
    jfieldID NhandleId;
    jmethodID NativeTypeC;
    jclass FunctionData;
    jclass Exception;
    jclass CriticalException;
    jclass   NativeType;
    jclass   Double;
    jclass    String;
    jmethodID CriticalExceptionC;
    jfieldID MhandleId;
    jmethodID ExceptionC;
    jmethodID FunctionDataC;
    void mathlibra_throw_jni(JNIEnv *env, interface::wrapper_exception_info w) {
        if(w.isCritical)
        {
             env->Throw((jthrowable)env->NewObject(NativeComponents::CriticalException,
                           NativeComponents::CriticalExceptionC,
                           env->NewStringUTF(w.desc),
                           env->NewStringUTF(w.type),
                           w.id
             ));
        }
        else
        {
            env->Throw((jthrowable)env->NewObject(NativeComponents::Exception,
                        NativeComponents::ExceptionC,
                        env->NewStringUTF(w.desc),
                        env->NewStringUTF(w.type),
                        w.id
            ));
        }
    }
}
