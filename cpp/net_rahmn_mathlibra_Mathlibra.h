/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class net_rahmn_mathlibra_Mathlibra */

#ifndef _Included_net_rahmn_mathlibra_Mathlibra
#define _Included_net_rahmn_mathlibra_Mathlibra
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    createInstance
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_net_rahmn_mathlibra_Mathlibra_createInstance
  (JNIEnv *, jclass);

/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    freeInstance
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_net_rahmn_mathlibra_Mathlibra_freeInstance
  (JNIEnv *, jclass, jlong);

/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    mapN
 * Signature: (DDDLjava/lang/String;)Ljava/nio/ByteBuffer;
 */
JNIEXPORT jobject JNICALL Java_net_rahmn_mathlibra_Mathlibra_mapN
  (JNIEnv *, jobject, jdouble, jdouble, jdouble, jstring);

/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    freeBufferN
 * Signature: (Ljava/nio/Buffer;)V
 */
JNIEXPORT void JNICALL Java_net_rahmn_mathlibra_Mathlibra_freeBufferN
  (JNIEnv *, jclass, jobject);

/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    setArg
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_net_rahmn_mathlibra_Mathlibra_setArg
  (JNIEnv *, jobject, jstring);

/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    interpretArg
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_net_rahmn_mathlibra_Mathlibra_interpretArg
  (JNIEnv *, jobject);

/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    executeArg
 * Signature: ()Lnet/rahmn/mathlibra/NativeType;
 */
JNIEXPORT jobject JNICALL Java_net_rahmn_mathlibra_Mathlibra_executeArg
  (JNIEnv *, jobject);

/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    defineFunction
 * Signature: (Ljava/lang/String;Z)V
 */
JNIEXPORT void JNICALL Java_net_rahmn_mathlibra_Mathlibra_defineFunction
  (JNIEnv *, jobject, jstring, jboolean);

/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    undefineFunction
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_net_rahmn_mathlibra_Mathlibra_undefineFunction
  (JNIEnv *, jobject, jstring);

/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    getFunctionNames
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_net_rahmn_mathlibra_Mathlibra_getFunctionNames
  (JNIEnv *, jobject);

/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    getFunctions
 * Signature: ()[Lnet/rahmn/mathlibra/FunctionData;
 */
JNIEXPORT jobjectArray JNICALL Java_net_rahmn_mathlibra_Mathlibra_getFunctions
  (JNIEnv *, jobject);

/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    getVariableNames
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_net_rahmn_mathlibra_Mathlibra_getVariableNames
  (JNIEnv *, jobject);

/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    getVariable
 * Signature: (Ljava/lang/String;)Lnet/rahmn/mathlibra/NativeType;
 */
JNIEXPORT jobject JNICALL Java_net_rahmn_mathlibra_Mathlibra_getVariable
  (JNIEnv *, jobject, jstring);

/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    setVariable
 * Signature: (Ljava/lang/String;Lnet/rahmn/mathlibra/NativeType;Z)V
 */
JNIEXPORT void JNICALL Java_net_rahmn_mathlibra_Mathlibra_setVariable
  (JNIEnv *, jobject, jstring, jobject, jboolean);

/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    isVariableDefined
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_net_rahmn_mathlibra_Mathlibra_isVariableDefined
  (JNIEnv *, jobject, jstring);

/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    isVariableConst
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_net_rahmn_mathlibra_Mathlibra_isVariableConst
  (JNIEnv *, jobject, jstring);

/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    clearVariables
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_net_rahmn_mathlibra_Mathlibra_clearVariables
  (JNIEnv *, jobject);

/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    enablePlugins
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_net_rahmn_mathlibra_Mathlibra_enablePlugins
  (JNIEnv *, jobject);

/*
 * Class:     net_rahmn_mathlibra_Mathlibra
 * Method:    getVersion
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_net_rahmn_mathlibra_Mathlibra_getVersion
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
