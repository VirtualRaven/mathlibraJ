//
// Created by raven on 2016-02-05.
//
#include <iostream>
#include "mathlibra_Mathlibra.h"
#include "NativeComponents.h"
#include "export.h"
JNIEXPORT void JNICALL Java_mathlibra_Mathlibra_initNativeComponents
  (JNIEnv *env, jclass c)
{

}

JNIEXPORT jlong JNICALL Java_mathlibra_Mathlibra_createInstance
        (JNIEnv * env, jclass c)
{
    reinterpret_cast<long>(InitLib());
}


JNIEXPORT void JNICALL Java_mathlibra_Mathlibra_freeInstance
        (JNIEnv *, jclass, jlong v)
{
    delete reinterpret_cast<interface::calc_lib_interface*>(v);
}
JNIEXPORT void JNICALL Java_mathlibra_Mathlibra_setArg
        (JNIEnv * env, jobject o, jstring str)
{
    auto hwn= reinterpret_cast<interface::calc_lib_interface*>(env->GetLongField(o,NativeComponents::MhandleId));
    if(hwn==NULL)
        return;
    auto strd=env->GetStringUTFChars(str,NULL);
    hwn->set_arg(strd);
    env->ReleaseStringUTFChars(str,strd);
}


JNIEXPORT void JNICALL Java_mathlibra_Mathlibra_interpretArg
        (JNIEnv * env, jobject o)
{

    auto hwn= reinterpret_cast<interface::calc_lib_interface*>(env->GetLongField(o,NativeComponents::MhandleId));
    if(hwn==NULL)
        return;
    hwn->interpret_arg();
    if(hwn->exceptionOccured())
    {
        NativeComponents::mathlibra_throw_jni(env,hwn->get_exception_info());
    }
}

JNIEXPORT jobject JNICALL Java_mathlibra_Mathlibra_executeArg
        (JNIEnv * env, jobject o)
{

    auto hwn= reinterpret_cast<interface::calc_lib_interface*>(env->GetLongField(o,NativeComponents::MhandleId));
    if(hwn==NULL)
        return NULL;
    interface::type_ptr tmp = hwn->execute_arg();
    if(hwn->exceptionOccured()) {
        NativeComponents::mathlibra_throw_jni(env,hwn->get_exception_info());
        return NULL;
    }
    else {
        tmp.release();
        return env->NewObject(NativeComponents::NativeType,
                       NativeComponents::NativeTypeC,
                       tmp.ptr(),
                       JNI_FALSE);
    }
}
JNIEXPORT jobjectArray JNICALL Java_mathlibra_Mathlibra_getFunctionNames
        (JNIEnv * env, jobject o)
{
    auto hwn= reinterpret_cast<interface::calc_lib_interface*>(env->GetLongField(o,NativeComponents::MhandleId));
    if(hwn==NULL)
        return NULL;
    auto tmp = hwn->getFunctionNames();
    if(hwn->exceptionOccured())
    {
        NativeComponents::mathlibra_throw_jni(env,hwn->get_exception_info());
        return NULL;
    }
    else
    {
        jobjectArray obj =env->NewObjectArray(tmp.size(),NativeComponents::String,NULL);
        for(int i=0; i <tmp.size(); i++)
        {
            jobject str= env->NewStringUTF(tmp[i].c_str());
            if(str==NULL)
                return NULL;
            env->SetObjectArrayElement(obj,i,str);
        }
        return obj;
    }
}
JNIEXPORT jobjectArray JNICALL Java_mathlibra_Mathlibra_getFunctions
        (JNIEnv *env, jobject o)
{

    auto hwn= reinterpret_cast<interface::calc_lib_interface*>(env->GetLongField(o,NativeComponents::MhandleId));
    if(hwn==NULL)
        return NULL;

    auto tmp = hwn->getFunctionObjs();
    if(hwn->exceptionOccured()) {
        NativeComponents::mathlibra_throw_jni(env,hwn->get_exception_info());
        return NULL;
    }
    else
    {
        jobjectArray obj=env->NewObjectArray(tmp.size(),NativeComponents::FunctionData,NULL);
        if(obj==NULL)
            return NULL;
        for(int i=0; i<tmp.size(); i++)
        {
            auto c= tmp[i];
            jobject funcData= env->NewObject(NativeComponents::FunctionData,
                                     NativeComponents::FunctionDataC,
                                     env->NewStringUTF(c.name.c_str()),
                                     env->NewStringUTF(c.tag.c_str()),
                                     env->NewStringUTF(c.doc.c_str()),
                                     env->NewStringUTF(c.disp_name.c_str())
            );
            if(funcData==NULL)
                return NULL;
            env->SetObjectArrayElement(obj,i,funcData);
        }
        return obj;
    }

}

JNIEXPORT jobjectArray JNICALL Java_mathlibra_Mathlibra_getVariableNames
        (JNIEnv * env, jobject o)
{
    auto hwn= reinterpret_cast<interface::calc_lib_interface*>(env->GetLongField(o,NativeComponents::MhandleId));
    if(hwn==NULL)
        return NULL;
    auto tmp = hwn->getVariableNames();
    if(hwn->exceptionOccured())
    {
        NativeComponents::mathlibra_throw_jni(env,hwn->get_exception_info());
        return NULL;
    }
    else
    {
        jobjectArray obj =env->NewObjectArray(tmp.size(),NativeComponents::String,NULL);
        for(int i=0; i <tmp.size(); i++)
        {
            jobject str= env->NewStringUTF(tmp[i].c_str());
            if(str==NULL)
                return NULL;
            env->SetObjectArrayElement(obj,i,str);
        }
        return obj;
    }
}
JNIEXPORT jobject JNICALL Java_mathlibra_Mathlibra_getVariable
        (JNIEnv * env, jobject o, jstring str)
{

    auto hwn= reinterpret_cast<interface::calc_lib_interface*>(env->GetLongField(o,NativeComponents::MhandleId));
    if(hwn==NULL)
        return NULL;
    auto string = env->GetStringUTFChars(str,NULL);
    if(string==NULL)
        return NULL;
    interface::mem_obj_api tmp=hwn->getVariable(string);
    env->ReleaseStringUTFChars(str,string);
    if(hwn->exceptionOccured())
    {
        NativeComponents::mathlibra_throw_jni(env,hwn->get_exception_info());
        return NULL;
    }
    else
    {
        return env->NewObject(NativeComponents::NativeType,
                              NativeComponents::NativeTypeC,
                              reinterpret_cast<jlong>(tmp.value),
                              JNI_TRUE);
    }
}
JNIEXPORT jboolean JNICALL Java_mathlibra_Mathlibra_isVariableDefined
        (JNIEnv * env, jobject o, jstring str)
{

    auto hwn= reinterpret_cast<interface::calc_lib_interface*>(env->GetLongField(o,NativeComponents::MhandleId));
    if(hwn==NULL)
        return JNI_FALSE;
    auto string = env->GetStringUTFChars(str,NULL);
    if(string==NULL)
        return JNI_FALSE;
    auto tmp=hwn->isDefined(string);
    env->ReleaseStringUTFChars(str,string);
    if(hwn->exceptionOccured()) {
        NativeComponents::mathlibra_throw_jni(env,hwn->get_exception_info());
        return JNI_FALSE;
    }
    else
        return tmp;
}
JNIEXPORT jboolean JNICALL Java_mathlibra_Mathlibra_isVariableConst
        (JNIEnv * env, jobject o, jstring str)
{

    auto hwn= reinterpret_cast<interface::calc_lib_interface*>(env->GetLongField(o,NativeComponents::MhandleId));
    if(hwn==NULL)
        return JNI_FALSE;
    auto string = env->GetStringUTFChars(str,NULL);
    if(string==NULL)
        return JNI_FALSE;
    auto tmp=hwn->isConstVariable(string);
    env->ReleaseStringUTFChars(str,string);
    if(hwn->exceptionOccured()) {
        NativeComponents::mathlibra_throw_jni(env,hwn->get_exception_info());
        return JNI_FALSE;
    }
    else
        return tmp;
}


JNIEXPORT void JNICALL Java_mathlibra_Mathlibra_clearVariables
        (JNIEnv * env, jobject o)
{

    auto hwn= reinterpret_cast<interface::calc_lib_interface*>(env->GetLongField(o,NativeComponents::MhandleId));
    if(hwn==NULL)
        return;
    hwn->clearVariables();
    if(hwn->exceptionOccured())
    {
        NativeComponents::mathlibra_throw_jni(env,hwn->get_exception_info());
    }
}

JNIEXPORT void JNICALL Java_mathlibra_Mathlibra_enablePlugins
        (JNIEnv * env, jobject o)
{

    auto hwn= reinterpret_cast<interface::calc_lib_interface*>(env->GetLongField(o,NativeComponents::MhandleId));
    if(hwn==NULL)
        return;
    hwn->enablePlugins();
    if(hwn->exceptionOccured())
    {
        NativeComponents::mathlibra_throw_jni(env,hwn->get_exception_info());
    }
}


JNIEXPORT void JNICALL Java_mathlibra_Mathlibra_setVariable
        (JNIEnv *env, jobject o, jstring str, jobject o2, jboolean b)
{

    auto hwn= reinterpret_cast<interface::calc_lib_interface*>(env->GetLongField(o,NativeComponents::MhandleId));
    if(hwn==NULL)
        return;
    auto data=reinterpret_cast<interface::type*>(env->GetLongField(o2,NativeComponents::NhandleId));
    if(data==NULL)
    {
        return;
    }
    const char* x=env->GetStringUTFChars(str,NULL);

    hwn->manageVariable(std::string(x),interface::type_ptr(data->copy()),b==JNI_TRUE);
    env->ReleaseStringUTFChars(str,x);
    if(hwn->exceptionOccured())
    {
        NativeComponents::mathlibra_throw_jni(env,hwn->get_exception_info());
    }

}

JNIEXPORT jstring JNICALL Java_mathlibra_Mathlibra_getVersion
        (JNIEnv * env, jclass c)
{
    return env->NewStringUTF("TEST");
}
