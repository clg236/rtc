// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/base/PathService

#ifndef org_chromium_base_PathService_JNI
#define org_chromium_base_PathService_JNI

#include <jni.h>

#include "../../../../../../../base/android/jni_generator/jni_generator_helper.h"

// Step 1: forward declarations.
JNI_REGISTRATION_EXPORT extern const char
    kClassPath_org_chromium_base_PathService[];
const char kClassPath_org_chromium_base_PathService[] =
    "org/chromium/base/PathService";

// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT base::subtle::AtomicWord
    g_org_chromium_base_PathService_clazz = 0;
#ifndef org_chromium_base_PathService_clazz_defined
#define org_chromium_base_PathService_clazz_defined
inline jclass org_chromium_base_PathService_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env,
      kClassPath_org_chromium_base_PathService,
      &g_org_chromium_base_PathService_clazz);
}
#endif

namespace base {
namespace android {

// Step 2: method stubs.

static void JNI_PathService_Override(JNIEnv* env, const
    base::android::JavaParamRef<jclass>& jcaller,
    jint what,
    const base::android::JavaParamRef<jstring>& path);

JNI_GENERATOR_EXPORT void
    Java_org_chromium_base_PathService_nativeOverride(JNIEnv* env, jclass
    jcaller,
    jint what,
    jstring path) {
  return JNI_PathService_Override(env, base::android::JavaParamRef<jclass>(env,
      jcaller), what, base::android::JavaParamRef<jstring>(env, path));
}

}  // namespace android
}  // namespace base

#endif  // org_chromium_base_PathService_JNI
