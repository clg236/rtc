// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/webrtc/NetworkMonitor

#ifndef org_webrtc_NetworkMonitor_JNI
#define org_webrtc_NetworkMonitor_JNI

#include <jni.h>

#include "../../../../../../../sdk/android/src/jni/jni_generator_helper.h"

// Step 1: forward declarations.
JNI_REGISTRATION_EXPORT extern const char
    kClassPath_org_webrtc_NetworkMonitor[];
const char kClassPath_org_webrtc_NetworkMonitor[] = "org/webrtc/NetworkMonitor";

// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT base::subtle::AtomicWord
    g_org_webrtc_NetworkMonitor_clazz = 0;
#ifndef org_webrtc_NetworkMonitor_clazz_defined
#define org_webrtc_NetworkMonitor_clazz_defined
inline jclass org_webrtc_NetworkMonitor_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env, kClassPath_org_webrtc_NetworkMonitor,
      &g_org_webrtc_NetworkMonitor_clazz);
}
#endif

// Step 2: method stubs.
JNI_GENERATOR_EXPORT void
    Java_org_webrtc_NetworkMonitor_nativeNotifyConnectionTypeChanged(JNIEnv*
    env, jobject jcaller,
    jlong nativePtr) {
  webrtc::jni::AndroidNetworkMonitor* native =
      reinterpret_cast<webrtc::jni::AndroidNetworkMonitor*>(nativePtr);
  CHECK_NATIVE_PTR(env, jcaller, native, "NotifyConnectionTypeChanged");
  return native->NotifyConnectionTypeChanged(env,
      base::android::JavaParamRef<jobject>(env, jcaller));
}

JNI_GENERATOR_EXPORT void
    Java_org_webrtc_NetworkMonitor_nativeNotifyOfNetworkConnect(JNIEnv* env,
    jobject jcaller,
    jlong nativePtr,
    jobject networkInfo) {
  webrtc::jni::AndroidNetworkMonitor* native =
      reinterpret_cast<webrtc::jni::AndroidNetworkMonitor*>(nativePtr);
  CHECK_NATIVE_PTR(env, jcaller, native, "NotifyOfNetworkConnect");
  return native->NotifyOfNetworkConnect(env,
      base::android::JavaParamRef<jobject>(env, jcaller),
      base::android::JavaParamRef<jobject>(env, networkInfo));
}

JNI_GENERATOR_EXPORT void
    Java_org_webrtc_NetworkMonitor_nativeNotifyOfNetworkDisconnect(JNIEnv* env,
    jobject jcaller,
    jlong nativePtr,
    jlong networkHandle) {
  webrtc::jni::AndroidNetworkMonitor* native =
      reinterpret_cast<webrtc::jni::AndroidNetworkMonitor*>(nativePtr);
  CHECK_NATIVE_PTR(env, jcaller, native, "NotifyOfNetworkDisconnect");
  return native->NotifyOfNetworkDisconnect(env,
      base::android::JavaParamRef<jobject>(env, jcaller), networkHandle);
}

JNI_GENERATOR_EXPORT void
    Java_org_webrtc_NetworkMonitor_nativeNotifyOfActiveNetworkList(JNIEnv* env,
    jobject jcaller,
    jlong nativePtr,
    jobjectArray networkInfos) {
  webrtc::jni::AndroidNetworkMonitor* native =
      reinterpret_cast<webrtc::jni::AndroidNetworkMonitor*>(nativePtr);
  CHECK_NATIVE_PTR(env, jcaller, native, "NotifyOfActiveNetworkList");
  return native->NotifyOfActiveNetworkList(env,
      base::android::JavaParamRef<jobject>(env, jcaller),
      base::android::JavaParamRef<jobjectArray>(env, networkInfos));
}

static base::subtle::AtomicWord g_org_webrtc_NetworkMonitor_getInstance = 0;
static base::android::ScopedJavaLocalRef<jobject>
    Java_NetworkMonitor_getInstance(JNIEnv* env) {
  CHECK_CLAZZ(env, org_webrtc_NetworkMonitor_clazz(env),
      org_webrtc_NetworkMonitor_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, org_webrtc_NetworkMonitor_clazz(env),
      "getInstance",
"("
")"
"Lorg/webrtc/NetworkMonitor;",
      &g_org_webrtc_NetworkMonitor_getInstance);

  jobject ret =
      env->CallStaticObjectMethod(org_webrtc_NetworkMonitor_clazz(env),
          method_id);
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_org_webrtc_NetworkMonitor_startMonitoring = 0;
static void Java_NetworkMonitor_startMonitoring(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj, jlong nativeObserver) {
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_NetworkMonitor_clazz(env));
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_NetworkMonitor_clazz(env),
      "startMonitoring",
"("
"J"
")"
"V",
      &g_org_webrtc_NetworkMonitor_startMonitoring);

     env->CallVoidMethod(obj.obj(),
          method_id, nativeObserver);
  jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_org_webrtc_NetworkMonitor_stopMonitoring = 0;
static void Java_NetworkMonitor_stopMonitoring(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj, jlong nativeObserver) {
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_NetworkMonitor_clazz(env));
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_NetworkMonitor_clazz(env),
      "stopMonitoring",
"("
"J"
")"
"V",
      &g_org_webrtc_NetworkMonitor_stopMonitoring);

     env->CallVoidMethod(obj.obj(),
          method_id, nativeObserver);
  jni_generator::CheckException(env);
}

static base::subtle::AtomicWord
    g_org_webrtc_NetworkMonitor_networkBindingSupported = 0;
static jboolean Java_NetworkMonitor_networkBindingSupported(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) {
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_NetworkMonitor_clazz(env), false);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_NetworkMonitor_clazz(env),
      "networkBindingSupported",
"("
")"
"Z",
      &g_org_webrtc_NetworkMonitor_networkBindingSupported);

  jboolean ret =
      env->CallBooleanMethod(obj.obj(),
          method_id);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_org_webrtc_NetworkMonitor_androidSdkInt = 0;
static jint Java_NetworkMonitor_androidSdkInt(JNIEnv* env) {
  CHECK_CLAZZ(env, org_webrtc_NetworkMonitor_clazz(env),
      org_webrtc_NetworkMonitor_clazz(env), 0);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, org_webrtc_NetworkMonitor_clazz(env),
      "androidSdkInt",
"("
")"
"I",
      &g_org_webrtc_NetworkMonitor_androidSdkInt);

  jint ret =
      env->CallStaticIntMethod(org_webrtc_NetworkMonitor_clazz(env),
          method_id);
  jni_generator::CheckException(env);
  return ret;
}

#endif  // org_webrtc_NetworkMonitor_JNI
