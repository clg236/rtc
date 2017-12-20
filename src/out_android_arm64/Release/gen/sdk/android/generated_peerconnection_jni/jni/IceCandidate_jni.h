// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/webrtc/IceCandidate

#ifndef org_webrtc_IceCandidate_JNI
#define org_webrtc_IceCandidate_JNI

#include <jni.h>

#include "../../../../../../../sdk/android/src/jni/jni_generator_helper.h"

// Step 1: forward declarations.
JNI_REGISTRATION_EXPORT extern const char kClassPath_org_webrtc_IceCandidate[];
const char kClassPath_org_webrtc_IceCandidate[] = "org/webrtc/IceCandidate";

// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT base::subtle::AtomicWord g_org_webrtc_IceCandidate_clazz
    = 0;
#ifndef org_webrtc_IceCandidate_clazz_defined
#define org_webrtc_IceCandidate_clazz_defined
inline jclass org_webrtc_IceCandidate_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env, kClassPath_org_webrtc_IceCandidate,
      &g_org_webrtc_IceCandidate_clazz);
}
#endif

// Step 2: method stubs.

static base::subtle::AtomicWord g_org_webrtc_IceCandidate_Constructor = 0;
static base::android::ScopedJavaLocalRef<jobject>
    Java_IceCandidate_Constructor(JNIEnv* env, const
    base::android::JavaRef<jstring>& sdpMid,
    JniIntWrapper sdpMLineIndex,
    const base::android::JavaRef<jstring>& sdp,
    const base::android::JavaRef<jstring>& serverUrl) {
  CHECK_CLAZZ(env, org_webrtc_IceCandidate_clazz(env),
      org_webrtc_IceCandidate_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_IceCandidate_clazz(env),
      "<init>",
"("
"Ljava/lang/String;"
"I"
"Ljava/lang/String;"
"Ljava/lang/String;"
")"
"V",
      &g_org_webrtc_IceCandidate_Constructor);

  jobject ret =
      env->NewObject(org_webrtc_IceCandidate_clazz(env),
          method_id, sdpMid.obj(), as_jint(sdpMLineIndex), sdp.obj(),
              serverUrl.obj());
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_org_webrtc_IceCandidate_getSdpMid = 0;
static base::android::ScopedJavaLocalRef<jstring>
    Java_IceCandidate_getSdpMid(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) {
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_IceCandidate_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_IceCandidate_clazz(env),
      "getSdpMid",
"("
")"
"Ljava/lang/String;",
      &g_org_webrtc_IceCandidate_getSdpMid);

  jstring ret =
      static_cast<jstring>(env->CallObjectMethod(obj.obj(),
          method_id));
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord g_org_webrtc_IceCandidate_getSdp = 0;
static base::android::ScopedJavaLocalRef<jstring>
    Java_IceCandidate_getSdp(JNIEnv* env, const base::android::JavaRef<jobject>&
    obj) {
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_IceCandidate_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_IceCandidate_clazz(env),
      "getSdp",
"("
")"
"Ljava/lang/String;",
      &g_org_webrtc_IceCandidate_getSdp);

  jstring ret =
      static_cast<jstring>(env->CallObjectMethod(obj.obj(),
          method_id));
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

#endif  // org_webrtc_IceCandidate_JNI
