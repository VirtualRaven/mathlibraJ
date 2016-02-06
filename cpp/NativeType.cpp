//
// Created by raven on 2016-02-02.
//
#include <type_enum.h>
#include "mathlibra_NativeType.h"
#include "type.h"
#include "NativeComponents.h"


JNIEXPORT jlong JNICALL Java_mathlibra_NativeType_copyInstance
  (JNIEnv *, jclass, jlong v)
{
    return reinterpret_cast<jlong>(reinterpret_cast<type*>(v)->copy());
}
JNIEXPORT void JNICALL Java_mathlibra_NativeType_freeInstance
  (JNIEnv *, jclass, jlong v)
{
   delete reinterpret_cast<type*>(v);
}
JNIEXPORT jint JNICALL Java_mathlibra_NativeType_sizeN
  (JNIEnv * env, jobject o)
{
    return reinterpret_cast<type*>(env->GetLongField(o,NativeComponents::NhandleId))->sizeN();
}
JNIEXPORT jint JNICALL Java_mathlibra_NativeType_sizeM
  (JNIEnv * env, jobject o)
{
    return reinterpret_cast<type*>(env->GetLongField(o,NativeComponents::NhandleId))->sizeM();
}

JNIEXPORT jboolean JNICALL Java_mathlibra_NativeType_isVector
  (JNIEnv *env, jobject o)
{
    return reinterpret_cast<type*>(env->GetLongField(o,NativeComponents::NhandleId))->isVector();
}

JNIEXPORT jboolean JNICALL Java_mathlibra_NativeType_isList
  (JNIEnv * env, jobject o)
{
    return reinterpret_cast<type*>(env->GetLongField(o,NativeComponents::NhandleId))->isList();
}

JNIEXPORT jboolean JNICALL Java_mathlibra_NativeType_isSingleton
  (JNIEnv *env, jobject o)
{
    return reinterpret_cast<type*>(env->GetLongField(o,NativeComponents::NhandleId))->isVector();
}

JNIEXPORT jboolean JNICALL Java_mathlibra_NativeType_isString
  (JNIEnv *env, jobject o)
{
    return reinterpret_cast<type*>(env->GetLongField(o,NativeComponents::NhandleId))->isString();
}

JNIEXPORT jboolean JNICALL Java_mathlibra_NativeType_isNumber
  (JNIEnv *env, jobject o)
{
    return reinterpret_cast<type*>(env->GetLongField(o,NativeComponents::NhandleId))->isNumber();
}

JNIEXPORT jdouble JNICALL Java_mathlibra_NativeType_toNumberN
  (JNIEnv * env, jobject o)
{
    return reinterpret_cast<type*>(env->GetLongField(o,NativeComponents::NhandleId))->toNumber();
}
JNIEXPORT jstring JNICALL Java_mathlibra_NativeType_toString
  (JNIEnv * env, jobject o)
{
    return env->NewStringUTF(reinterpret_cast<type*>(env->GetLongField(o,NativeComponents::NhandleId))->toString());

}
JNIEXPORT jobject JNICALL Java_mathlibra_NativeType_getObj
  (JNIEnv * env, jobject o)
{
    auto tmp = reinterpret_cast<type*>(env->GetLongField(o,NativeComponents::NhandleId));
    switch(tmp->stores())
    {
        case T_DOUBLE:
        {
            auto mat = static_cast<num_mat*>(tmp);
            int n=mat->sizeN(),m=mat->sizeM();
            auto objArray=env->NewObjectArray(n,NativeComponents::Double,NULL);
            if(objArray==NULL)
                return NULL;
            for(int i=0; i < n; i++)
            {
                auto array = env->NewDoubleArray(m);
                env->SetDoubleArrayRegion(array,0,m,mat->raw()+i*m*sizeof(double));
                env->SetObjectArrayElement(objArray,i,array);
            }
            return objArray;

        }

        case T_CHAR:
        {
            auto mat = static_cast<char_mat*>(tmp);
            int n=mat->sizeN(),m=mat->sizeM();
            auto objArray=env->NewObjectArray(n,NativeComponents::String,NULL);
            for(int i =0; i< n; i++)
            {
                env->SetObjectArrayElement(objArray,i,env->NewStringUTF(mat->raw()+i*m));
            }
            return objArray;

        }
        case T_TYPE:
        {
            auto mat = static_cast<mat_mat*>(tmp);
            int n=mat->sizeN(),m=mat->sizeM();
            auto it = mat->begin();
            auto objArray = env->NewObjectArray(n,NativeComponents::NativeType,NULL);
            for(int i=0; i <n; i++)
            {
                auto objArray2= env->NewObjectArray(m,NativeComponents::NativeType,NULL);
                for(int j=0; j<m; j++)
                {
                    auto obj =env->NewObject(NativeComponents::NativeType,NativeComponents::NativeTypeC, reinterpret_cast<long>(*it++),JNI_TRUE);
                    if(obj==NULL)
                        return NULL;
                    env->SetObjectArrayElement(objArray2,j,obj);
                }
                env->SetObjectArrayElement(objArray,i,objArray2);
            }
            return objArray;

        }
        default:
        {
            auto obj=env->NewObject(NativeComponents::CriticalException,
                           NativeComponents::CriticalExceptionC,
                           "WRAPPER FAILURE",
                           "Unknown return type, mathlibraJ may be outdated",0);
            env->Throw((jthrowable)obj);
            return NULL;
        }
    }
}

